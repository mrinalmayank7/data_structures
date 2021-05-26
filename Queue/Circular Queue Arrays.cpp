#include <iostream>
using namespace std;

int queue[4];
int front = -1, rear = -1, MAX=4;

void enqueue(int);
void  dequeue();
void display();
int main()
{
    int ch, val;
do
 { 
cout<<"......MENU........"<<endl;
cout<<"1.ENQUEQE"<<endl<<"2.DEQUE "<<endl<<"3.DISPLAY"<<endl<<"4. EXIT"<<endl;
cout<<"_________________________"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>ch;
switch (ch)
        {
 case 1:
    cout<<"ENTER THE ELELENT TO ENQUEUE :";
    cin>>val;
    enqueue(val);
    break;

case 2: dequeue();
        break;    
case 3: display();
        break;
case 4: 
    return 0;
default :
	cout<<"INVALID CHOICE:";	
}}
while(ch<=4);
}
void enqueue(int val) {
   if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
      cout<<"OVERFLOW! QUEUE IS FULL"<<endl;
      return;
   }
   if (front == -1) {
      front = 0;
      rear = 0;
   } else {
      if (rear == MAX - 1)
      rear = 0;
      else
      rear = rear + 1;
   }
   queue[rear] =val ;
}
void dequeue() {
   if (front == -1) {
      cout<<"QUEUE IS EMPTY!"<<endl;
      return ;
   }
   cout<<"DELETED ELEMENT IS : "<<queue[front]<<endl;
   if (front == rear) {
      front = -1;
      rear = -1;
   } else {
      if (front == MAX - 1)
      front = 0;
      else
      front = front + 1;
   }
}
void display() {
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

