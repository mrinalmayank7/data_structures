#include <iostream>
#include <queue>
using namespace std;
struct Node{
	struct Node *left;
	int data;
	struct Node *right;
}*root=NULL;

void create(){
	queue<Node *> q;
	cout<<"TO TERMINATE THE LEAFS, ENTER -1"<<endl;
	struct Node *p, *temp;
	int DATA;
	cout<<"ENTER DATA OF THE ROOT NODE : ";
	cin>>DATA;
	root= new Node;
	root->data=DATA;
	root->left=root->right=NULL;
    q.push(root);
    
    while(!q.empty()){
    	p=q.front(); //P POINTS TO CURRENT NODE
    	q.pop();
    	cout<<"ENTER LEFT NODE DATA OF "<<p->data<<" : ";
	    cin>>DATA;
	    if(DATA!=-1){
	    	temp=new Node;
		    temp->data=DATA;	
    	    temp->left=temp->right=NULL;
    	    p->left=temp;
    	    q.push(temp);
	    }
	
    	cout<<"ENTER RIGHT NODE DATA OF "<<p->data<<" : ";
	    cin>>DATA;
	    if(DATA!=-1){
	        temp=new Node;
		    temp->data=DATA;	
    	    temp->left=temp->right=NULL;
    	    p->right=temp;
    	    q.push(temp);
	    }
	    
	}
	
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
	do{
	cout<<"\n1.CREATE A BINARY TREE"<<endl<<"2.PREORDER TRAVERSAL"<<endl<<"3.INORDER TRAVERSAL"<<endl
	    <<"4.POSTORDER TRAVERSAL"<<endl<<"5.LEVELORDER TRAVERSAL"<<endl<<"6.EXIT"<<endl;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	switch(ch){
		case 1:
			create();
			break;
		case 2:
			cout<<"PREORDER TRAVERSAL : ";
			preorder(root);
			break;
		case 3:
			cout<<"INORDER TRAVERSAL : ";
			inorder(root);
			break;
		case 4:
			cout<<"POSTORDER TRAVERSAL : ";
			postorder(root);
			break;
		case 5:
			cout<<"LEVELORDER TRAVERSAL : ";
			levelorder(root);
			break;
		case 6:
			return 0;	
		default:
			cout<<"INVALID CHOICE";
			break;
	}
	}while(ch<=6);
}
