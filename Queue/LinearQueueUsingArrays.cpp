#include<iostream>
using namespace std;
#define MAX 5
int Q[MAX];
int front=-1;
int rear=-1;

bool isEmpty();
bool isFull();

void display(){
int i;
if(isEmpty()){
cout<<"QUEUE IS EMPTY"<<endl;
}
else{

	for(int i=front+1;i<=rear;i++){
		cout<<Q[i]<<" ";
	}
	cout<<endl;
}
}
void enQueue(int element){
	if(isFull()){
		cout<<"OVERFLOW"<<endl;
	}
	else{

		rear++;
		Q[rear]=element;
	}
}

void deQueue(){
	if(isEmpty()){
		cout<<"UNDERFLOW"<<endl;
	}
	else{
		front++;
		cout<<Q[front]<<" Deleted"<<endl;
	}
}
	
bool isEmpty(){
	if(front==rear){
		front=-1;
		rear=-1; //resetting pointers if queue becomes empty to reuse the space 
		return true;
	}
	else{
		return false;
	}	
}
bool isFull(){
	if(rear==MAX-1){
		return true;
	}
	else{
		return false;
	}
}


int main(){
int ch, element;
do{
cout<<"\n1.DISPLAY"<<endl<<"2.ENQUEUE"<<endl<<"3.DEQUEUE"<<endl
    <<"4.EXIT"<<endl;
cout<<"ENTER YOUR CHOICE :";
cin>>ch;
cout<<"\n";
switch(ch){
case 1:
	display();
	break;
case 2:
	cout<<"ENTER THE ELEMENT TO ENQUEUE :";
	cin>>element;
	enQueue(element);
	break;
case 3:
	deQueue();
	break;

case 4:
	return 0;
		
default :
	cout<<"INVALID CHOICE";
	break;
}
}while(ch<=4);	


}
