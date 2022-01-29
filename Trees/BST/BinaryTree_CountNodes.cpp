#include <iostream>
#include <queue>
using namespace std;
struct Node{
	struct Node *left;
	int data;
	struct Node *right;
}*root=NULL;

struct Node* create(int DATA){
  struct Node* temp=new Node;
  temp->data=DATA;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
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


int count(struct Node *p){
	int x,y;
	if(p!=NULL){
	 x=count(p->left);
	 y=count(p->right);
	 return x+y+1; //return count as left recursive count + right recursive count + current node	
	}
	return 0;
}

int countleaf(struct Node* p){//similar to creation
	queue<Node *> q;
	q.push(p);
	int cnt=0;
	if(p->left==NULL && p->right==NULL){
		cnt=1;
	}
	while(!q.empty()){
		p=q.front();
		q.pop();
		if(p->left){
			if(p->left->left==NULL && p->left->right==NULL){
		     cnt++;
	        }
         	q.push(p->left);	
		}
	    	if(p->right){
			if(p->right->left==NULL && p->right->right==NULL){
		     cnt++;
	        }
         	q.push(p->right);	
		}
	}
	return cnt;
}




int main(){
	int ch;
	root =create(1);
	root->left =create(2);
	root->right =create(3);
	root->left->left =create(4);
	root->left->right =create(5);
	root->right->left =create(6);
	root->right->right =create(7);
	root->left->right->left =create(8);
	root->left->right->right =create(9);

	do{
	cout<<"\n1.COUNT TOTAL NODES"<<endl<<"2.COUNT LEAF NODES"<<endl
	    <<"3.LEVELORDER TRAVERSAL"<<endl<<"4.EXIT"<<endl;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"TOTAL NO. OF NODES  : "<<count(root);
			break;
		case 2:
			cout<<"TOTAL NO. OF LEAF NODES : "<<countleaf(root);
			break;
		case 3:
			cout<<"LEVELORDER TRAVERSAL : ";
			levelorder(root);
			break;
		case 4:
			return 0;	
		default:
			cout<<"INVALID CHOICE";
			break;
	}
	}while(ch<=4);
}
