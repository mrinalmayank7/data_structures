#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
}*head;



void create( int n){
    int i,DATA;
    struct Node *temp , *p;
    head =new Node;
    
    cout<<"Enter the data of node 1 : ";
    cin>>DATA;
    head->data=DATA;    //first element is created
    head->next=NULL; //point next to null 
    p=head; //make lastnode as head
    for(i=1;i<n;i++){ //i=1 since 0th node is already created as head
        temp = new Node;
        cout<<"enter the data of node "<<i+1<<" : ";
        cin>>DATA;
        temp->data= DATA; //newnode added
        temp->next= NULL;
        p->next=temp; //link newnode with previous node
        p=temp; //make newnode as lastnode, it will iterate again till all nodes are inserted
    }
}
int count(struct Node *p){
	int c=0;
    while(p!=NULL){
        c=c+1;
        p=p->next; 
    }
    return c;
}
reverse(struct Node *first){
struct Node *p=first;
int n=count(first);
int i,A[n];
for(i=0;p!=NULL;i++){
A[i]=p->data;
p=p->next;
}
p=first;
i--; 
while(p!=NULL){
p->data=A[i--];
p=p->next;
}
}
void display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";//print current node
        p=p->next; //move to next node, here we can also call it recursively by : display(p->next);
    }
}



int main(){
    int n;
    struct Node *loopvar;
    cout<<"ENTER LINKED LIST SIZE :";
    cin>>n;
    create(n);
    reverse(head);
	display(head);
		
 

}
