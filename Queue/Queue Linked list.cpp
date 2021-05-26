#include <iostream>
using namespace std;
struct node {
   int data;
   struct node *next;
};
struct node* front =NULL;
struct node* rear = NULL;
struct node* temp;
void enqueue();
void dequeue();
void display();
int main()
{
    int ch;
do
 { 
cout<<"......MENU........"<<endl;
cout<<"1.ENQUEQE"<<endl<<"2.DEQUE "<<endl<<"3.DISPLAY"<<endl<<"4. EXIT"<<endl;
cout<<"_________________________"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>ch;
switch (ch)
        {
case 1: enqueue();
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
void enqueue() {
   int val;
   cout<<"INSERT THE ELEMENT IN THE QUEUE: "<<endl;
   cin>>val;
   if (rear == NULL) {
      rear = new node;
      rear->next = NULL;
      rear->data = val;
      front = rear;
   } else {
      temp=new node;
      rear->next = temp;
      temp->data = val;
      temp->next = NULL;
      rear = temp;
   }
}
void dequeue() {
   temp = front;
   if (front == NULL) {
      cout<<"UNDERFLOW"<<endl;
      return;
   }
   else if (temp->next != NULL) {
      temp = temp->next;
      cout<<"DELETED ELEMENT IS : "<<front->data<<endl;
      delete(front);
      front = temp;
   } else {
      cout<<"DELETED ELEMENT IS : "<<front->data<<endl;
      delete(front);
      front = NULL;
      rear = NULL;
   }
}
void display() {
   temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"OOP'S ! QUEUE IS EMPTY"<<endl;
      return;
   }
   cout<<"ELEMENTS OF THE QUEUE ARE : ";
   while (temp != NULL) {
      cout<<temp->data<<" ";
      temp = temp->next;
   }
   cout<<endl;
   cout<<"REAR END IS : "<<rear->data<<endl;
   cout<<"FRONT END IS : "<<front->data<<endl;
}



