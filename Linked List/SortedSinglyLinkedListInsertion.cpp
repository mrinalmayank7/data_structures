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

int max(struct Node *p){
	int max=INT_MIN; //assign max as minimum integer so that it can be reinitialized to find the max element
	    while(p!=NULL){
        if(p->data > max){
        max=p->data;	
		}
		p=p->next;  
    }
    return max;
}
int min(struct Node *p){
	int min=INT_MAX; 
	    while(p!=NULL){
        if(p->data < min){
        min=p->data;	
		}
		p=p->next;  
    }
    return min;
}


void insertBEG(int DATA){
struct Node *temp;
temp = new Node;
temp->data= DATA;
temp->next= head;
head=temp;
}

void insertEND(int DATA){
struct Node *temp, *p;
p=head;
temp = new Node;
temp->data= DATA;
temp->next= NULL;
    while(p!=NULL){
        if(p->next==NULL){
           p->next=temp;
           break;
		}
		p=p->next;       
    }
}
void insertATSORTEDPOS(int DATA){
 
	if (DATA>=max(head)){
	insertEND(DATA);
	}
	else if (DATA<=min(head)){
	insertBEG(DATA);
	}
	else{
    struct Node* temp =new Node , *p =head ,*q=head; 
	temp->data=DATA; 
	while(p!=NULL){
        if(p->data>temp->data){ // find the first element greater than the element to insert
        while(q->next<p){  //find the previous element to that first greatest element
        	q=q->next;    
		}
          temp->next=q->next; 
          q->next=temp;
		break;
        }
		p=p->next;	
	}		
}
}
int main(){
int n,DATA, pos;
	cout<<"HOW MANY NODES YOU WANT TO INSERT : ";
    cin>>n;
    create(n);
    cout<<"ENTER ELEMENT TO INSERT AT SORTED POSITION :";
	cin>>DATA;
	insertATSORTEDPOS(DATA);

	cout<<"LIST ELEMENTS : ";
	display(head);	

}
