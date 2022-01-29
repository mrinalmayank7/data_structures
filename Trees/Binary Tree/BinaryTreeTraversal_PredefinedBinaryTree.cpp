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
    


void preorder(struct Node* p){
    if(p!=NULL){
    cout<<p->data<<" ";
	 preorder(p->left);
	 preorder(p->right);
	 }		
}

void inorder(struct Node* p){
	 if(p!=NULL){
	 inorder(p->left);
	 cout<<p->data<<" ";
	 inorder(p->right);
}
}

void postorder(struct Node* p){
     if(p!=NULL){	
	 postorder(p->left);
	 postorder(p->right);
	 cout<<p->data<<" ";
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
	int ch;
	root =create(1);
	root->left =create(2);
	root->right =create(3);
	root->left->left =create(4);
	root->left->right =create(5);
	root->right->left =create(6);
	root->right->right =create(7);

	do{
	cout<<"\n1.PREORDER TRAVERSAL"<<endl<<"2.INORDER TRAVERSAL"<<endl
	    <<"3.POSTORDER TRAVERSAL"<<endl<<"4.LEVELORDER TRAVERSAL"<<endl<<"5.EXIT"<<endl;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"PREORDER TRAVERSAL : ";
			preorder(root);
			break;
		case 2:
			cout<<"INORDER TRAVERSAL : ";
			inorder(root);
			break;
		case 3:
			cout<<"POSTORDER TRAVERSAL : ";
			postorder(root);
			break;
		case 4:
			cout<<"LEVELORDER TRAVERSAL : ";
			levelorder(root);
			break;
		case 5:
			return 0;	
		default:
			cout<<"INVALID CHOICE";
			break;
	}
	}while(ch<=5);
}
