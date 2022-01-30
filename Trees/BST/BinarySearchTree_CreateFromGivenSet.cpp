#include<iostream>
using namespace std;
struct Node{
	struct Node *left;
	int data;
	struct Node *right;
}*root;

void create(){
}
struct Node* search(int key){
	struct Node *temp=root;
	while(temp!=NULL){
	if(temp->data==key){
		return temp;
	}
	else if(key<temp->data){
	 temp=temp->left;
	}
	else{
	 temp=temp->right;
	}		
	}
	return NULL;
}
void insert(int key){
	struct Node *temp=root, *p,*r;
	if(root==NULL){
		p= new Node;
		p->data=key;
		p->left=p->right=NULL;
		root=p;
		return;
	}
	while(temp!=NULL){
	r=temp; //R HOLDS TEMP, SO WHEN TEMP->NEXT (RIGHT OR LEFT) IS NULL , WHILE LOOP STOP AND R HOLDS THE LAST PARENT ELEMENT AFTER WHICH KEY TO BE INSERTED
	if(key<temp->data){
		temp=temp->left; //SEARCH KEY ON RIGHT SIDE ITERATIVELY, WHEN TEMP=TEMP->RIGHT == NULL STOP
	}
	else if(key>temp->data){
		temp=temp->right; //SEARH KEY ON LEFT SIDE ITERATIVELY, WHEN TEMP=TEMP->LEFT == NULL STOP
	}
	else{
		return; //IF KEY = TEMP THEN DUPLICATE WHICH VIOLATES BST PROPERTY
	}	
	}
	p= new Node;
	p->data=key;
	p->left=p->right=NULL;
	
	if(key<r->data){
	r->	left=p;
	}
	else{
	r->right=p;
	}
}

void inorder(struct Node *p){
	if(p!=NULL){
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}
}
int main(){
int n;
int ch,key,A[n];
do{ 
cout<<"\n1.CREATE"<<endl<<"2.INRODER TRAVERSAL(SORTED IN BST)"<<endl<<"3.SEARCH"<<endl<<"4.EXIT"<<endl;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"IF ALREADY CREATED, NEW ELEMENTS WILL BE ADDED IN THE BST"<<endl;
			cout<<"HOW MANY ELEMENTS DO YOU WANT TO INSERT IN THE BST :";
			cin>>n;
			cout<<"ENTER THE ELEMENTS TO INSERT IN THE BST"<<endl;

			for(int i=0;i<n;i++){
			cin>>(A[i]);
			insert(A[i]);	
			} 
			break;
		case 2:
			cout<<endl;
			inorder(root);
			cout<<endl;
			break;
		case 3:
			cout<<"ENTER ELEMENT TO SEARCH : ";
			cin>>key;
			if(search(key)==NULL){
				cout<<"ELEMENT NOT FOUND"<<endl;
			}
			else{
				cout<<"ELEMENT FOUND"<<endl;
			}
			break;
		case 4:
			return 0;
		default :
			cout<<"INVALID CHOICE";
			break;
	}
}while(ch<=4);
	
}
