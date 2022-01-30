#include <iostream>
#include <queue>
using namespace std;
struct Node{
	struct Node *left;
	int data;
	struct Node *right;
}*root=NULL;

bool ifBST(struct Node *r){
	struct Node *p=r;
	if(p==NULL){
	return false;	
	}
	while(p!=NULL){
		if(p->right->data > p->data ){
		p=p->right;
		return true;
		}
		else{
			cout<<"FALSE RIGHT"<<endl;
			return false;
			break;
		}
		if(p->left->data < p->data ){
		p=p->left;
		return true;
		}
		else{
			cout<<"FALSE LEFT"<<endl;
			return false;
			break;
		}	
	}
}


struct Node* create(int DATA){
  struct Node* temp=new Node;
  temp->data=DATA;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
    


void inorder(struct Node* p){
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
	int ch;
	root =create(50);
	root->left =create(30);
	root->right =create(70);
	root->left->left =create(15);
	root->left->right =create(45);
	root->right->left =create(65);
	root->right->right =create(85);

	do{
	cout<<"\n1.CHECK IF TREE IS BST"<<endl<<"2.INORDER TRAVERSAL"<<endl
	    <<"3.LEVELORDER TRAVERSAL"<<endl<<"4.EXIT"<<endl;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	switch(ch){
		case 1:
			if(ifBST(root)==true){
				cout<<"THE TREE IS A BINARY SEARCH TREE"<<endl;
			}
			else{
				cout<<"TREE IS NOT A BST"<<endl;
			}
			break;
		case 2:
			cout<<"INORDER TRAVERSAL : ";
			inorder(root);
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
