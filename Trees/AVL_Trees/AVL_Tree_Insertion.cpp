#include<iostream>
#include<queue>
using namespace std;
struct Node{
	struct Node *left;
	int data;
    int height;
	struct Node *right;
}*root=NULL;

int Nodeheight(struct Node *p)
{
    if (p== NULL){
    	return 0;
    }
        int leftH = Nodeheight(p->left); //calculate depth of left subtree
        int rightH= Nodeheight(p->right); //calculate depth of right subtree
        if (leftH > rightH){
        	return(leftH+1); //+1 for height of  root
		}
        else {
        	return(rightH+1);
		}
    
}

int BalanceFactor(struct Node *p){
	    if (p==NULL){
    	return 0;
        }
        return Nodeheight(p->left)-Nodeheight(p->right);		
}

struct Node * LLRotation(struct Node *p){
	struct Node *pl=p->left, *plr=p->left->right;
	pl->right=p;
	p->left=plr;
	p->height=Nodeheight(p);
	pl->height=Nodeheight(pl);
	
	if(root==p){
		root=pl;
	}
	return pl;
}
struct Node * LRRotation(struct Node *p){
	struct Node *pl=p->left, *plr=p->left->right;
	p->left=plr->right;
	pl->right=plr->left;
	plr->right=p;
	plr->left=pl;
	p->height=Nodeheight(p);
	pl->height=Nodeheight(pl);
	plr->height=Nodeheight(plr);
	
	if(root==p){
		root=plr;
	}
	return plr;
}
struct Node * RRRotation(struct Node *p){ //reverse of LL -> swap all left and right pointers
	struct Node *pl=p->right, *plr=p->right->left;
	pl->left=p;
	p->right=plr;
	p->height=Nodeheight(p);
	pl->height=Nodeheight(pl);
	
	if(root==p){
		root=pl;
	}
	return pl;
}
struct Node * RLRotation(struct Node *p){ //reverse of LR -> swap all left and right pointers
	struct Node *pl=p->right, *plr=p->right->left;
	p->right=plr->left;
	pl->left=plr->right;
	plr->left=p;
	plr->right=pl;
	p->height=Nodeheight(p);
	pl->height=Nodeheight(pl);
	plr->height=Nodeheight(plr);
	
	if(root==p){
		root=plr;
	}
	return plr;
}
struct Node* insert(struct Node *p, int key){
	struct Node *temp=NULL;
	if(p==NULL){
		temp= new Node;
		temp->data=key;
		temp->height=1; //set height of new node as 0
		temp->left=temp->right=NULL;
		if(root==NULL){
			root=temp;
		}
		return temp;

	}
	if(key < p->data){
		p->left=insert(p->left,key);
	}
	else if(key > p->data){
		p->right=insert(p->right,key);	
	}
	
   p->height=Nodeheight(p);	
	if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1){
		return LLRotation(p);
	}
	else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1){
		return LRRotation(p);
	}
	if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1){
		return RRRotation(p);
	}
	if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1){
		return RLRotation(p);
	}
	
return p;
}

void inorder(struct Node *p){
	if(p!=NULL){
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}
}

void levelorder(struct Node* p){//similar to creation
	queue<Node *> q;
	cout<<p->data<<" ";
	q.push(p);
	while(!q.empty()){
		p=q.front();
		q.pop();
		if(p->left){
			cout<<p->left->data<<" ";
         	q.push(p->left);	
		}
		if(p->right){
			cout<<p->right->data<<" ";
         	q.push(p->right);	
		}
	}
}
int main(){
	int ch,key;
do{ 
cout<<"\n1.INSERT"<<endl<<"2.LEVEL ORDER TRAVERSAL"<<endl<<"3.INRODER TRAVERSAL(SORTED IN BST)"<<endl
    <<"4.HEIGHT"<<endl<<"5.EXIT"<<endl;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"ENTER KEY TO INSERT IN THE BST : ";
			cin>>key;
			insert(root,key); 
			break;
		case 2:
			cout<<endl;
			levelorder(root);
			cout<<endl;
			break;
		case 3:
			cout<<endl;
			inorder(root);
			cout<<endl;
			break;
		case 4:
			cout<<"HEIGHT OF THE TREE IS : "<<Nodeheight(root);
			break;
		case 5:
			return 0;
		default :
			cout<<"INVALID CHOICE";
			break;
	}
}while(ch<=5);
}
