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

void display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";//print current node
        p=p->next; //move to next node, here we can also call it recursively by : display(p->next);
    }
}

bool isloop(struct Node *first){
struct Node *p, *q;
p=q=first;
 //the while loop will stop when there is a loop if p==q
 // as q will encounter p from back, since q is moving one step faster than p
 //therefore if there is a cycle, there will be a time q will reach p and become q==p
 //if there is no loop then q will never reach p as it is always moving one step forward
while(p!=NULL && q!=NULL){
p=p->next; // p moving 1 step
q=q->next->next; // q moving 2 step
if(p==q){
return true;
break;
}
}
return false;
}


int main(){
    int n;
    struct Node *loopvar;
    cout<<"ENTER LINKED LIST SIZE :";
    cin>>n;
    create(n);
    // /*CREATE A LOOP FOR VERIFICATION , comment these steps for making list linear again
    loopvar=head;
    for(int i=0;i<n-1;i++){
    loopvar=loopvar->next;
	}
	loopvar->next=head->next->next;
	//THE ABOVE PROCEDURE CREATED A LOOP IN THE LINKEDLIST */
	if(isloop(head)==true){
	cout<<"THERE IS A LOOP IN THE LINKED LIST ";
	}
	else{
	cout<<"THIS IS A LINEAR LINKED LIST "<<endl;
	display(head);
	}	
 

}
