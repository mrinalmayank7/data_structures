#include<iostream>
#include<queue>
using namespace std;
struct Node{
	struct Node * left;
	int data;
	int height;
	struct Node * right;
}*root;

int Nodeheight(struct Node* p){
	if(p==NULL){
		return 0;
	}
	int leftH=Nodeheight(p->left);
	int rightH=Nodeheight(p->right);
	if(leftH>rightH){
		return leftH+1;
	}
	else{
		return rightH+1;
	}
}
int BalanceFactor(struct Node *p){
	    if (p==NULL){
    	return 0;
        }
        return Nodeheight(p->left)-Nodeheight(p->right);		
}
struct Node* insert(struct Node *p,int key){
struct Node* temp=NULL;
if(p==NULL){
temp=new Node;
temp->data=key;
temp->height=1;
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

return p;
}

void LevelOrder(struct Node* p){
	queue<Node *>q;
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

bool validateAVL(struct Node* p){

	queue<Node *>q;
	
	if(BalanceFactor(p)>1 || BalanceFactor(p)<-1){
		return false;
	}
	q.push(p);
	while(!q.empty()){
    p=q.front();
    q.pop();
    if(p->left){
    if(BalanceFactor(p->left)>1 || BalanceFactor(p->left)<-1){
		return false;
		break;
	}
    	q.push(p->left);
	}
	if(p->right){
    if(BalanceFactor(p->right)>1 || BalanceFactor(p->right)<-1){
		return false;
		break;
	}
    	q.push(p->right);
	}
	}
	return true;
}	

int main(){
int n;
int A[n];
cout<<"HOW MANY ELEMENTS DO YOU WANT TO INSERT IN THE BST ? ";
cin>>n;
for(int i=0;i<n;i++){
cout<<"INSERT ELEMENT "<<i+1<<" : ";
cin>>A[i];
insert(root,A[i]);
}
cout<<endl;
if(validateAVL(root)==false){
	cout<<"IT IS A BST BUT NOT A AVL TREE"<<endl;
}
else{
	cout<<"IT IS A AVL TREE"<<endl;
}
cout<<endl;	
cout<<"LEVEL ORDER TRAVERSAL : "<<endl;
LevelOrder(root);
cout<<endl;	
}
