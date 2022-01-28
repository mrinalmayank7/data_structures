#include<iostream>
using namespace std;
#define MAX 5
int Q[MAX];
int front=0, rear=0;
bool isEmpty();
bool isFull();
void enQueue(int element){
	if(isFull()){
		cout<<"OVERFLOW"<<endl;
	}
	else{
		rear=(rear+1)%MAX;
		Q[rear]=element;
	}	
}
void deQueue(){	
    if(isEmpty()){
		cout<<"UNDERFLOW"<<endl;
	}
	else{
		front=(front+1)%MAX;
		cout<<Q[front]<<" Deleted"<<endl; //Q[front] holds empty space
		
	}
}
 bool isEmpty(){
	if(front==rear){
		return true;
	}
	else{
		return false;
	}	
}
bool isFull(){
	if((rear+1)%MAX==front){ //when rear encounter front from back
		return true;
	}
	
	else{
		return false;
	}
}

void display(){
	if(isEmpty()){
		cout<<"QUEUE IS EMPTY"<<endl;
	}
	else{
	int i=front+1;
	do{
		cout<<Q[i]<<" ";
		i=(i+1)%MAX;
	}while(i!=(rear+1)%MAX);
	cout<<endl;
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
