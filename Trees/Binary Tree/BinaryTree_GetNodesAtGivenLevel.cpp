#include <iostream>
#include<math.h>
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



void getLevel(struct Node *p, int level)
{
    if (p == NULL)
        return;
    if (level == 1)
        cout<< p->data<<" ";
    else if (level > 1)
    {
        getLevel(p->left, level-1);
        getLevel(p->right, level-1);
    }
}








int main(){
	int ch,L;
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
	cout<<"\n1.GET NODES AT PARTICULAR LEVEL"<<endl<<"2.LEVELORDER TRAVERSAL"<<endl<<"3.EXIT"<<endl;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"ENTER THE LEVEL  : ";
			cin>>L;
			getLevel(root,L);
			break;
		case 2:
			cout<<"LEVELORDER TRAVERSAL : ";
			levelorder(root);
			break;
		case 3:
			return 0;	
		default:
			cout<<"INVALID CHOICE";
			break;
	}
	}while(ch<=3);
}
