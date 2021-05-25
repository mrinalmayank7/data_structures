#include<iostream>
using namespace std;
#define MAX 100
int stack[MAX];
int top = -1; 
void push(int element);
int  pop();
void display();

int main()
{
 int ch, data;
do
 { 
cout<<"......MENU........"<<endl;
cout<<"1.PUSH"<<endl<<"2.POP "<<endl<<"3.DISPLAY STACK "<<endl<<"4.EXIT"<<endl;
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
                cout<<"THE SIZE OF THE STACK IS  :"<< top + 1<<endl;
                display();
                
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
     if (top>= MAX)
    {
        cout<<"OVERFLOW ! CAN'T ADD MORE ELEMENTS '"<<endl;
        return;
    }
    top++;
    stack[top] = element;
    cout<<"ELEMENT IS SUCCESSFULLY PUSHED "<<endl;
}

int pop()
{
    if (top < 0)
    {
        cout<<"STACK IS ALREADY EMPTY"<<endl;
        return INT_MIN;
    }
    return stack[top--];
}
void display() {
   if(top>=0) {
    cout<<"ELEMENTS OF THE STACK ARE :";
    for(int i=top; i>=0; i--)
    cout<<stack[i]<<" ";
     cout<<endl;
   }else
   cout<<"THE STACK IS EMPTY!" <<endl;
}

