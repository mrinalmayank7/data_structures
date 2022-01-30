#include<iostream>
using namespace std;
struct Node{
	struct Node *left;
	int data;
	struct Node *right;
}*root;


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

int height(struct Node *p)
{
    if (p== NULL){
    	return -1;
    }
        int leftH = height(p->left); //calculate depth of left subtree
        int rightH= height(p->right); //calculate depth of right subtree
        if (leftH > rightH){
        	return(leftH+1); //+1 for height of  root
		}
        else {
        	return(rightH+1);
		}
    

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
	if(height(p->left)>height(p->right)){
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

return p;
}

void inorder(struct Node *p){
	if(p!=NULL){
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}
}
int main(){
int ch,key;
do{ 
cout<<"\n1.INSERT"<<endl<<"2.DELETE"<<endl<<"3.INRODER TRAVERSAL(SORTED IN BST)"<<endl<<"4.SEARCH"<<endl
    <<"5.HEIGHT"<<endl<<"6.EXIT"<<endl;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"ENTER KEY TO INSERT IN THE BST : ";
			cin>>key;
			insert(key); 
			break;
		case 2:
			cout<<"ENTER KEY TO DELETE FROM THE BST : ";
			cin>>key;
			Delete(root,key); 
			break;
		case 3:
			cout<<endl;
			inorder(root);
			cout<<endl;
			break;
		case 4:
			cout<<"ENTER ELEMENT TO SEARCH : ";
			cin>>key;
			if(search(key)==NULL){
				cout<<"ELEMENT NOT FOUND"<<endl;
			}
			else{
				cout<<"ELEMENT FOUND"<<endl;
			}
			break;
		case 5:
			cout<<"HEIGHT OF THE TREE IS : "<<height(root);
			break;
		case 6:
			return 0;
		default :
			cout<<"INVALID CHOICE";
			break;
	}
}while(ch<=6);
	
}
