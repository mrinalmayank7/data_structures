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


struct Node *InPre(struct Node *p){
while(p!=NULL && p->right!=NULL){
	p=p->right;
}
return p;	
}
struct Node *InSuc(struct Node *p){
while(p!=NULL && p->left!=NULL){
	p=p->left;
}
return p;	
} 
struct Node* Delete(struct Node *p, int key){
struct Node *q;
if(p==NULL){
	return NULL;
}
if(p->left==NULL && p->right==NULL){ //if become leaf
if(p==root){
	root=NULL;
}
delete(p);
return NULL;	
}


if(key< p->data){
p->left=Delete(p->left,key);
}
else if(key>p->data){
p->right=Delete(p->right,key);
}
else{
	if(Nodeheight(p->left)>Nodeheight(p->right)){
		q=InPre(p->left); //find inorder successor in left subtree
		p->data=q->data;//replace element to be deleted with inorder successor
		p->left=Delete(p->left, q->data); //if the inroder successor is not left
		//recursiely call till the element to be deleted is replaced with leaf inorder successors
	}
	else{
		q=InSuc(p->right); //find inorder predecessor in right subtree
		p->data=q->data;
		p->right=Delete(p->right, q->data); 	
	}
}

    p->height = Nodeheight(p);
 
    if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1){  // L-1 Rotation
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 0){  // R0 Rotation
        return RRRotation(p);
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
cout<<"\n1.INSERT"<<endl<<"2.DELETE"<<endl<<"3.LEVEL ORDER TRAVERSAL"<<endl<<"4.INRODER TRAVERSAL(SORTED IN BST)"<<endl
    <<"5.HEIGHT"<<endl<<"6.EXIT"<<endl;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"ENTER KEY TO INSERT IN THE AVL TREE : ";
			cin>>key;
			insert(root,key); 
			break;
		case 2:
			cout<<"ENTER KEY TO DELETE FROM THE AVL TREE : ";
			cin>>key;
			Delete(root,key); 
			break; 
		case 3:
			cout<<endl;
			levelorder(root);
			cout<<endl;
			break;
		case 4:
			cout<<endl;
			inorder(root);
			cout<<endl;
			break;
		case 5:
			cout<<"HEIGHT OF THE TREE IS : "<<Nodeheight(root);
			break;
		case 6:
			return 0;
		default :
			cout<<"INVALID CHOICE";
			break;
	}
}while(ch<=6);
}
