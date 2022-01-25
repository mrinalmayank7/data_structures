#include<iostream>
using namespace std;
struct Node{
	struct Node *prev;
	int data;
	struct Node *next;
}*head;

void create( int n){
    int i,DATA;
    struct Node *temp , *p;
    head =new Node;
    
    cout<<"Enter the data of node 1 : ";
    cin>>DATA;
    head->data=DATA;    
    head->next=head->prev=NULL;  
    p=head; 
    for(i=1;i<n;i++){ 
        temp = new Node;
        cout<<"enter the data of node "<<i+1<<" : ";
        cin>>DATA;
        temp->data= DATA; 
        temp->prev= p;
        temp->next= NULL;
        p->next=temp; 
        p=temp; 
    }
}

void display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";//print current node
        p=p->next; //move to next node, here we can also call it recursively by : display(p->next);
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

void insertBEG(int DATA){
struct Node *temp;
temp = new Node;
temp->data= DATA;
temp->next= head;
temp->prev= NULL;
head->prev=temp;
head=temp;
}

void insertATANYPOS(int DATA, int pos){
	struct Node* temp =new Node , *p =head; 
	temp->data=DATA; 
	for(int i=0;i<pos-1;i++){ 
	p=p->next;
	}
	temp->next=p->next;
	temp->prev=p;
	if(p->next!=NULL){
	p->next->prev=temp;
	}
	p->next=temp; 	
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
           temp->prev=p;
           break;
		}
		p=p->next;       
    }
}

void deleteBEG(){
	struct Node *temp;
	temp=head;
	head=head->next;
	if(head!=NULL){
	head->prev=NULL;
	}
	cout<<temp->data<< " HAS BEEN DELETED";
	delete(temp);
	
}

void deleteATANYPOS(int pos){
    struct Node *p=head;
	for(int i=0;i<pos-1 && p!=NULL;i++){ 
	p=p->next;  
	}
	p->prev->next=p->next;
	if(p->next!=NULL){
	p->next->prev=p->prev;
	}
	cout<<p->data<< " HAS BEEN DELETED";
	delete(p);		
}
 void deleteEND(){
	struct Node *p=head;
	while(p!=NULL){
	if(p->next==NULL){
	cout<<p->data<< " HAS BEEN DELETED";
	p->prev->next=NULL;
	delete(p);
	break;
	}
	p=p->next;	
	}		
}

int main(){
int n,key,ch,DATA, pos;
do{
cout<<"\n1.CREATE"<<endl<<"2.DISPLAY"<<endl<<"3.INSERT AT BEGINNING"<<endl
    <<"4.INSERT AT THE END"<<endl<<"5.INSERT AT ANY POSITION"<<endl<<"6.DELETE FROM BEGINNING"<<endl
	<<"7.DELETE FROM END"<<endl<<"8.DELETE FROM ANY POSITION"<<endl<<"9.EXIT"<<endl;
cout<<"ENTER YOUR CHOICE :";
cin>>ch;
cout<<"\n";
switch(ch){
case 1:
	cout<<"HOW MANY NODES YOU WANT TO INSERT : ";
    cin>>n;
    create(n);
    break;
case 2:
	cout<<"LIST ELEMENTS : ";
	display(head);	
    break;

case 3:
	cout<<"ENTER ELEMENT TO INSERT AT BEGINNING :";
	cin>>DATA;
	insertBEG(DATA);
	break;
case 4:
	cout<<"ENTER ELEMENT TO INSERT AT THE END :";
	cin>>DATA;
	insertEND(DATA);
	break;
case 5:
	cout<<"AFTER WHAT POSITION YOU WANT TO INSERT ELEMENT :";
	cin>>pos;
	cout<<"ENTER ELEMENT TO INSERT AT POSITION "<<pos+1<<" : ";
	cin>>DATA;

	insertATANYPOS(DATA,pos);
	break;
case 6:
	deleteBEG();
	break;
case 7:
	deleteEND();
	break;
case 8:
	cout<<"ENTER THE POSITION OF THE NODE TO DELETE:";
	cin>>pos;
	deleteATANYPOS(pos);
	break;

case 9:
	return 0;
		
default :
	cout<<"INVALID CHOICE";
	break;
}
}while(ch<=9);
}
