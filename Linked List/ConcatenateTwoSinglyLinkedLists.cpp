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

void conactenate(struct Node *p,struct Node *q){
third=p;
while(p!=NULL){
if(p->next==NULL){
p->next=q;
break;	
}
p=p->next;
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
	
	conactenate(first,second);
	cout<<"CONCATENATED LINKED LIST ELEMENTS : "<<endl;
	display(third);
	cout<<endl;
		
   

}
