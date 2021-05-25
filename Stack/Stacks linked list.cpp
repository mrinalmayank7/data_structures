#include<iostream>
using namespace std;
#define MAX 1000
struct stack 
{
    int data;
    struct stack *next;
} *top;
int size = 0;
void push(int element);
int  pop();


int main()
{
    int ch, data;
    do
 { 
cout<<"......MENU........"<<endl;
cout<<"1.PUSH"<<endl<<"2.POP "<<endl<<"3.SIZE"<<endl<<"4.EXIT"<<endl;
cout<<"_________________________"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>ch;
        switch(ch) 
        {
            case 1: 
                cout<<"ENTER THE ELEMENT TO PUSH IN THE STACK : ";
                cin>>data;
                push(data);
                break;

            case 2: 
                data = pop();
                if (data != INT_MIN)
                    cout<< "THE ELEMENT "<<data<<" IS LAST PUSHED SO IT IS POPPED OUT"<<endl;
                break;

            case 3: 
                cout<<"THE SIZE OF THE STACK IS  :"<<size<<endl;
                break;
            case 4: 
               return 0;
                break;
            default: 
               cout<<"YOUR CHOICE IS INVALID "<<endl;
        }
    }while(ch<=4);
  
}

void push(int element)
{
    if (size >= MAX)
    {
        cout<<"OVERFLOW ! CAN'T ADD MORE ELEMENTS '"<<endl;;
        return;
    }
    struct stack * newNode = new stack;
    newNode->data = element;
    newNode->next = top;    // Next element after new node should be current top element     
    top = newNode; // Make sure new node is always at top
    size++;
    cout<<"ELEMENT IS SUCCESSFULLY PUSHED "<<endl;
}

int pop()
{
    int data = 0;
    struct stack * topNode;
    if (size <= 0 || !top)
    {
       cout<<"STACK IS ALREADY EMPTY"<<endl;
        return INT_MIN;
    }
    topNode = top;
    data = top->data;// Copy data from stack's top element
    top = top->next; // Move top to its next element

    delete(topNode);// Delete the previous top most stack element from memory
    size--;

    return data;
}
