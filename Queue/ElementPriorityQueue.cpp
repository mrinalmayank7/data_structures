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
	if(rear==MAX-1){
		cout<<"OVERFLOW AT REAR END"<<endl;
	}
	else if(isEmpty()){ //first element insert normally
		rear++;
		Q[rear]=element;
	}
	else{ //insert at sorted position
	int i;
	rear++;	
	i=rear;
	while(element<Q[i-1]){
	Q[i]=Q[i-1];
	i--;
	}
	Q[i]=element;	
	}	
}


void deQueueR(){ //dequeue rear or max
	if(isEmpty()){
		cout<<"UNDERFLOW"<<endl;
	}
	else{
		cout<<Q[rear]<<" Deleted"<<endl;
		
		rear--;
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



int main(){
int ch, element;
do{
cout<<"\n1.DISPLAY"<<endl<<"2.ENQUEUE AT SORTED POSITION"<<endl<<"3.DEQUEUE MAXIMUM ELEMENT / REAR"<<endl
    <<"4.EXIT"<<endl;
cout<<"ENTER YOUR CHOICE :";
cin>>ch;
cout<<"\n";
switch(ch){
case 1:
	display();
	break;
case 2:
	cout<<"ENTER THE ELEMENT TO ENQUEUE AT SORTED POSITION:";
	cin>>element;
	enQueue(element);
	break;
case 3:
	deQueueR();
	break;
case 4:
	return 0;
		
default :
	cout<<"INVALID CHOICE";
	break;
}
}while(ch<=4);	


}
