#include<iostream>
using namespace std;
struct node {
    int data;
    struct node * back;
    struct node * next;
}*head,*end;

void create(int n);
void display();
void insertAtBeg(int data);
void insertAtEnd(int data);
void insertAtanyposition(int data, int pos);



int main()
{
    int n, ch,data,pos;
    head = NULL;
    end = NULL;    
cout<<"How many nodes do you want to create : ";
cin>>n;
create(n); 
do
 {
cout<<"......MENU........"<<endl;
cout<<"1.DISPLAY"<<endl<<"2.INSERT AT BEGINNING "<<endl<<"3.INSERT AT THE END  "<<endl<<"4.INSERT AT ANY POSITION"<<endl<<"5.EXIT"<<endl;
cout<<"_________________________"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>ch;
switch(ch)
{
case 1:	
    display();
    break;
case 2 :
cout<<"Enter the data to insert at the beginning  :" ;
cin>>data;
 insertAtBeg(data);
    break;
case 3:
cout<<"Enter the data to insert at the end :" ;
cin>>data; 
 insertAtEnd(data);
   break;
case 4:
cout<<"enter the position to insert the new node :";
cin>>pos;
cout<<"Enter the data to insert at the entered position  :" ;
cin>>data;
 insertAtanyposition( data,  pos);
   break;
case 5:       
    return 0;
    
default : cout<<"OOP's ,NOT A VALID CHOICE!";
}}
while(ch<=5);
  
    return 0;
}


void create(int n)
{
    int i, data;
    struct node *newNode;
    if(n >= 1)
    {
        head = new node;

        if(head != NULL)
        {
            cout<<"Enter value  of node 1 :";
            cin>>data;

            head->data = data;
            head->back = NULL;
            head->next = NULL;

            end = head;
            for(i=2; i<=n; i++)
            {
                newNode = new node;

                if(newNode != NULL)
                {
                    cout<<"Enter value  of node "<< i<<" :";
                    cin>>data;

                    newNode->data = data;
                    newNode->back = end ; // Link new node with the previous node
                    newNode->next = NULL;

                    end->next = newNode; // Link previous node with the new node
                    end = newNode;          // Make new node as last/previous node
                }
                else
                {
                     cout<<"MEMORY NOT ALLOCATED";
                    break;
                }
            }

            cout<<"DOUBLY LINKED LIST CREATED"<<endl;
        }
        else
        {
             cout<<"MEMORY NOT ALLOCATED ";
        }}}


void display()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        cout<<"empty";
    }
    else
    {
        temp = head;
        cout<<"DATA IN THE LIST:"<<endl;

        while(temp != NULL)
        {
            cout<<n<<" : " << temp->data<<endl; 
            n++;
            
            /* Move the current pointer to next node */
            temp = temp->next;
        }
    }
}

    void insertAtBeg(int data)
{
    struct node * newNode;

    if(head == NULL)
    {
     cout<<"empty";
    }
    else
    {
        newNode = new node;

        newNode->data = data;
        newNode->next = head; // Point to next node which is currently head
        newNode->back = NULL; // Previous node of first node is NULL

        /* Link previous address field of head with newnode */
        head->back = newNode;

        /* Make the new node as head node */
        head = newNode;
     cout<<"successfully inserted at the beginning "<<endl;
    }
}


void insertAtEnd(int data)
{
 struct node * newNode;
if(end == NULL)
    {
    cout<<"enpty";
    }
    else
    {
        newNode = new node;

        newNode->data = data;
        newNode->next = NULL;
        newNode->back = end;

        end->next = newNode;
        end = newNode;
    cout<<"SUCESS IN INSERTION AT THE END "<<endl;
    }
}



void insertAtanyposition(int data, int pos)
{
    int i;
    struct node * newNode, *temp;
    if(head == NULL)
    {
    cout<<"enpty";
    }
    else
    {
        temp = head;
        i=1;
        while(i<pos-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }
        if(pos == 1)
        {
            insertAtBeg(data);
        }
        else if(temp == end)
        {
            insertAtEnd(data);
        }
        else if(temp!=NULL)
        {
            newNode = new node;
            newNode->data = data;
            newNode->next = temp->next; // Connect new node with n+1th node
            newNode->back = temp;          // Connect new node with n-1th node

            if(temp->next != NULL)
            {
                /* Connect n+1th node with new node */
                temp->next->back = newNode;
            }
            /* Connect n-1th node with new node */
            temp->next = newNode;
            cout<<"Successfully inserted at the entered position "<<endl;
			        }
        else
        {
            cout<<	"INVALID POSITION "<<endl;
	        }
    }
}
