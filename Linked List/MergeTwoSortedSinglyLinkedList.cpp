#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
}*first,*second,*third;

void createfirst( int n){
    int i,DATA;
    struct Node *temp , *p;
    first =new Node;
    
    cout<<"Enter the data of node 1 : ";
    cin>>DATA;
    first->data=DATA;    
    first->next=NULL;  
    p=first; 
    for(i=1;i<n;i++){
        temp = new Node;
        cout<<"enter the data of node "<<i+1<<" : ";
        cin>>DATA;
        temp->data= DATA; 
        temp->next= NULL;
        p->next=temp; 
        p=temp; 
    }
}

void createsecond( int n){
    int i,DATA;
    struct Node *temp , *p;
    second =new Node;
    
    cout<<"Enter the data of node 1 : ";
    cin>>DATA;
    second->data=DATA;    
    second->next=NULL;  
    p=second; 
    for(i=1;i<n;i++){
        temp = new Node;
        cout<<"enter the data of node "<<i+1<<" : ";
        cin>>DATA;
        temp->data= DATA; 
        temp->next= NULL;
        p->next=temp; 
        p=temp; 
    }
}

void display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next; 
    }
}

void merge(struct Node *p,struct Node *q){ //p=frist,q=second
struct Node* last;
//BRINGING POINTERS TO FIRST NODE WHICH IS SMALLEST
if(p->data< q->data){
third=last=p;
p=p->next;
last->next=NULL;
}
else{
third=last=q;
q=q->next;
last->next=NULL;
}

//ITERATIVELY APPEND SORTED ELEMENTS TO THIRD LIST
while(p!=NULL && q!=NULL){
if(p->data< q->data){
last->next=p;
last=p;
p=p->next;
last->next=NULL;

}
else{
last->next=q;
last=q;
q=q->next;
last->next=NULL;
}
}
//FOR LEFT ELELEMNTS FOR EITHER IN Q OR P , APPEND TO LAST	
if(p!=NULL){
last->next=p;
}
else{
last->next=q;	
}
}


int main(){
int n,m;
    cout<<"CREATE FIRST LINKED LIST "<<endl;
	cout<<"HOW MANY NODES YOU WANT TO INSERT : ";
    cin>>n;
    createfirst(n);
    cout<<"CREATE SECOND LINKED LIST "<<endl;
	cout<<"HOW MANY NODES YOU WANT TO INSERT : ";
    cin>>m;
    createsecond(m);
   
	cout<<"FIRST LINKED LIST ELEMENTS : "<<endl;
	display(first);
	cout<<endl;
	cout<<"SECOND LINKED LIST ELEMENTS : "<<endl;
	display(second);
	cout<<endl;
	
	merge(first,second);
	cout<<" MERGED LINKED LIST ELEMENTS : "<<endl;
	display(third);
	cout<<endl;
		
   

}
