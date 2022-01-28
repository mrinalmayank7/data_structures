#include<iostream>
using namespace std;
struct Queue{
	int data;
	struct Queue *next;
}*front=NULL,*rear=NULL;

void enQueue(int DATA){
	struct Queue *temp,*p=front;
	temp= new Queue;
	if(temp==NULL){
		cout<<"OVERFLOW";
	}
	else{
	temp->data=DATA;
	temp->next=NULL;
	if(front==NULL){
		front=rear=temp;
	}
	else{
	rear->next=temp;
	rear=temp;
	}
	}
}

void deQueue(){
	struct Queue *temp;
	if(front==NULL){
		cout<<"UNDERFLOW"<<endl;
	}
	else{
	 temp=front;
	 front=front->next;
	 delete(temp);
	}
}
void display(){
	struct Queue *p=front;
	if(p==NULL){
		cout<<"UNDERFLOW";
	}
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
}

int main(){
	int ch, element;
	do{
	cout<<"\n1.DISPLAY"<<endl<<"2.ENQUEUE"<<endl<<"3.DEQUEUE"<<endl<<"4.EXIT"<<endl;
	cout<<"ENTER YOUR CHOICE :";
	cin>>ch;
	switch(ch){
		case 1:display();
		       break;
		case 2:
			   cout<<"ENTER ELEMENT TO ENQUEUE :";
		       cin>>element;
			   enQueue(element);
		       break;
		case 3:deQueue();
		       break;
		case 4:return 0;
		default: cout<<"INVALID CHOICE "<<endl;
		         break;
		       
	}
	}while(ch<=4);
}

