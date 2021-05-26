#include<iostream>
using namespace std;
#define MAX  100
int  queue[MAX];
int front = -1, rear = -1;  

int  enqueueFRONT(int );
int enqueueREAR(int );
int  dequeueFRONT();
int  dequeueREAR();
void Display();
int main()
{
    int ch, key;
do
 { 
cout<<"......MENU........"<<endl;
cout<<"1.ENQUEQE FROM FRONT"<<endl<<"2.ENQUEUE FROM REAR "<<endl<<"3.DEQUEUE FROM FRONT "<<endl<<"4.DEQUEUE FROM REAR "<<endl<<"5.DISPLAY"<<endl<<"6.EXIT"<<endl;
cout<<"_________________________"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>ch;
switch (ch)
        {
 case 1:
    cout<<"ENTER THE ELELENT TO ENQUEUE FROM FRONT :";
    cin>>key;
    if (enqueueFRONT(key))
    cout<<"ELEMENT IS SUCCESSFULLY ADDED"<<endl;
    else
    cout<<"THE QUEUE IS FULL"<<endl;
    break;
case 2:
    cout<<"ENTER THE ELELENT TO ENQUEUE FROM REAR :";
    cin>>key;
    if (enqueueREAR(key))
    cout<<"ELEMENT IS SUCCESSFULLY ADDED"<<endl;
    else
    cout<<"THE QUEUE IS FULL"<<endl;
    break;
case 3:
   dequeueFRONT();
    break;
    
case 4:
    dequeueREAR();
    break;

case 5: Display();
        break;
case 6: 
    return 0;
default :
	cout<<"INVALID CHOICE:";	
}}
while(ch<=6);
}

   
int  enqueueFRONT(int key)
{
    if(rear == MAX-1)
    {
        cout <<"QUEUE IS FULL"<<endl;
    }
    else
    {
    	if(front == -1)
    		front = rear =0;
        else if(front == 0)
            front = MAX-1; 
        else
        	--front;
        queue[front] = key;
    }
}
int  enqueueREAR(int key)
{
    if(rear == MAX-1){
        cout << "QUEUE IS FULL"<<endl;
    }
    else {
    	   if(front == -1)
    		  front = rear = 0;
        else if(rear == MAX-1)
            rear = 0;
        
        else
        	++rear;     
        queue[rear] = key;
    }    
}
int  dequeueFRONT()
{
    if(front == -1)
    {
        cout << "QUEUE IS EMPTY"<<endl;
    }
    else
    {
        if(front == rear)
        	front = rear = -1;
        else if(front == MAX-1)
        	front = 0;
        else
        	++front;		
    }
    cout<<"DEQUE SUCCESSFUL FROM FRONT "<<endl;
    
}
int  dequeueREAR()
{
    if(front == -1)
    {
        cout << "QUEUE IS EMPTY"<<endl;
    }
    else
    {
        if(front == rear)
        	front = rear = -1;
        else if(rear == 0)
        	rear = MAX-1;

        else
        	--rear;		
    }
    cout<<"DEQUE SUCCESSFUL FROM REAR "<<endl;
}
void Display() 
    { 
        int i; 
        if (front == -1) { 
        cout<<"QUEUE IS EMPTY"<<endl;    
            return; 
        } 
        else
        for (i = front; i <=rear; i++) { 
        cout<<"ELEMENT "<<i+1<<" OF QUEUE IS : " <<queue[i]<<endl; 
        } 
         cout<<"REAR END IS : "<<queue[rear]<<endl;
         cout<<"FRONT END IS : "<<queue[front]<<endl;
        return; 
    } 
  

