#include<iostream>
#include<vector>
using namespace std;
struct Node{
	int data;
	struct Node *next;
}*head;

void create(vector <int> DATA, int n){
    int i;
    struct Node *temp , *p;
    head =new Node;
    head->data=DATA[0];    
    head->next=NULL; 
    p=head; 
    for(i=1;i<n;i++){ 
        temp = new Node;
        temp->data= DATA[i]; 
        temp->next= NULL;
        p->next=temp; 
        p=temp;
    }
}

removeduplicates(){
	struct Node *p=head, *q=head->next;
	while(p!=NULL&& q!=NULL){
		if(p->data!=q->data){
		p=p->next;
		q=q->next;	
		}
		else{
			p->next=q->next;// p is now pointing next of q and q is to be deleted 
			delete(q);// now q is deleted and new q shoud be next of p / ahead of p
			q= p->next;
		}
	}
}
int main(){
	vector<int> A={33,33,56,56,56,77,88,86,86,99,99,99,100};
	create(A,A.size());
	    struct Node *p=head;
	    removeduplicates();
	    
	    while(p!=NULL){
        cout<<p->data<<" ";//print current node
        p=p->next; //move to next node, here we can also call it recursively by : display(p->next);
    }
}
