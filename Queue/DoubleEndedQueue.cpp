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
void enQueueR(int element){
	if(rear==MAX-1){
		cout<<"OVERFLOW AT REAR END"<<endl;
	}
	else{
		rear++;
		Q[rear]=element;
	}
}

void enQueueF(int element){
	if(front==-1){
		cout<<"OVERFLOW AT FRONT END"<<endl;
	}
	else{
        Q[front]=element;
		front--;
	}
}

void deQueueF(){
	if(isEmpty()){
		cout<<"UNDERFLOW"<<endl;
	}
	else{
		front++;
		cout<<Q[front]<<" Deleted"<<endl;
	}
}

void deQueueR(){
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
cout<<"\n1.DISPLAY"<<endl<<"2.ENQUEUE AT REAR"<<endl<<"3.ENQUEUE AT FRONT"<<endl
    <<"4.DEQUEUE AT REAR"<<endl<<"5.DEQUEUE AT FRONT"<<endl<<"6.EXIT"<<endl;
cout<<"ENTER YOUR CHOICE :";
cin>>ch;
cout<<"\n";
switch(ch){
case 1:
	display();
	break;
case 2:
	cout<<"ENTER THE ELEMENT TO ENQUEUE AT REAR:";
	cin>>element;
	enQueueR(element);
	break;
case 3:
	cout<<"ENTER THE ELEMENT TO ENQUEUE AT FRONT:";
	cin>>element;
	enQueueF(element);
	break;
case 4:
	deQueueR();
	break;
case 5:
	deQueueF();
	break;

case 6:
	return 0;
		
default :
	cout<<"INVALID CHOICE";
	break;
}
}while(ch<=6);	


}
