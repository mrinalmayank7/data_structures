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
int count(struct Node *p){
	int c=0;
    while(p!=NULL){
        c=c+1;
        p=p->next; 
    }
    return c;
}
int sum(struct Node *p){
	int sum=0;
    while(p!=NULL){
        sum=sum+p->data;
        p=p->next; 
    }
    return sum;
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
//binary search is not suitable for linked list
Node* linearsearch(struct Node *p, int key){
    while(p!=NULL){
        if(key==p->data){
        	return p;
        	break;
		}
        p=p->next; //move to next node, here we can also call it recursively by : display(p->next);
    }
    return NULL;
}

bool issorted(){
struct Node *p=head;
int x;
while(	p!=NULL){
if(p->data < x){ //x is the previous value
	return false;
	break;
}
x=p->data;
p=p->next;
}
return true;
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
void insertATANYPOS(int DATA, int pos){
	struct Node* temp =new Node , *p =head; 
	temp->data=DATA; //add data to node
	for(int i=0;i<pos-1;i++){ //traverse till position after which you want to insert
	p=p->next; //now the node after which you want to insert is p
	}
	temp->next=p->next; // link next pointer of new node to next of p
	p->next=temp; // link next of p to new node	
}

void deleteBEG(){
	struct Node *temp;
	temp=head;
	head=head->next;
	cout<<temp->data<< " HAS BEEN DELETED";
	delete(temp);
	
}
 void deleteEND(){
	struct Node *p=head;
	while(p!=NULL){
	if(p->next->next==NULL){
	cout<<p->next->data<< " HAS BEEN DELETED";
	p->next=NULL;
	delete(p->next);
	break;
	}
	p=p->next;	
	}		
}



void deleteATANYPOS(int pos){
    struct Node *p=head,*q=NULL;
	for(int i=0;i<pos-1 && p!=NULL;i++){ 
	q=p; //now q is before the node to be deleted
	p=p->next;  //p is the node to be deleted
	}
	q->next=p->next;
	cout<<p->data<< " HAS BEEN DELETED";
	delete(p);		
}

int main(){
int n,key,ch,DATA, pos;
do{
cout<<"\n1.CREATE"<<endl<<"2.DISPLAY | COUNT | SUM | MAX"<<endl<<"3.SEARCH "<<endl<<"4.INSERT AT BEGINNING"<<endl
    <<"5.INSERT AT THE END"<<endl<<"6.INSERT AT ANY POSITION"<<endl<<"7.DELETE FROM BEGINNING"<<endl
	<<"8.DELETE FROM END"<<endl<<"9.DELETE FROM ANY POSITION"<<endl<<"10.CHECK LINKED LIST IS SORTED OR NOT"<<endl<<"11.EXIT"<<endl;
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
    cout<<endl<<"TOTAL NUMBER OF NODES : "<<count(head)<<endl;
    cout<<"SUM OF  ALL NODES : "<<sum(head)<<endl;
    cout<<"MAXUMIUM ELEMENT IN THE LIST : "<<max(head)<<endl;
    break;
case 3:
	cout<<"ENTER ELEMENT TO SEARCH IN THE LINKED LIST : ";
    cin>>key;
    if(linearsearch(head,key)==NULL){
    cout<<"ELEMENT NOT FOUND"<<endl;
    }
    else{
    cout<<"ELEMENT FOUND AT ADDRESS "<<linearsearch(head,key)<<endl;	
    }
    break;
case 4:
	cout<<"ENTER ELEMENT TO INSERT AT BEGINNING :";
	cin>>DATA;
	insertBEG(DATA);
	break;
case 5:
	cout<<"ENTER ELEMENT TO INSERT AT THE END :";
	cin>>DATA;
	insertEND(DATA);
	break;
case 6:
	cout<<"AFTER WHAT POSITION YOU WANT TO INSERT ELEMENT :";
	cin>>pos;
	cout<<"ENTER ELEMENT TO INSERT AT POSITION "<<pos+1<<" : ";
	cin>>DATA;

	insertATANYPOS(DATA,pos);
	break;
case 7:
	deleteBEG();
	break;
case 8:
	deleteEND();
	break;
case 9:
	cout<<"ENTER THE POSITION OF THE NODE TO DELETE:";
	cin>>pos;
	deleteATANYPOS(pos);
	break;
case 10:

	if(issorted()==true){
		cout<<"LINKED LIST IS SORTED"<<endl;
	}
	else{
		cout<<"LINKED LIST IS NOT SORTED"<<endl;	
	}
	break;
case 11:
	return 0;
		
default :
	cout<<"INVALID CHOICE";
	break;
}
}while(ch<=11);



}
