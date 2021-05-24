#include<iostream>
using namespace std;
struct node {
    int data;
    struct node * back;
    struct node * next;
}*head,*end;

void create(int n);
void display();
void deleteFromBeg();
void deleteFromEnd();
void deleteFromanyposition(int pos);


int main()
{
     int n, ch,pos;
    head = NULL;
    end = NULL;    
cout<<"How many nodes do you want to create : ";
cin>>n;
create(n); 
do
 {
cout<<"......MENU........"<<endl;
cout<<"1.DISPLAY"<<endl<<"2.DELETE AT BEGINNING "<<endl<<"3.DELETE AT THE END  "<<endl<<"4.DELETE AT ANY POSITION"<<endl<<"5.EXIT"<<endl;
cout<<"_________________________"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>ch;
switch(ch)
{
case 1:	
    display();
    break;
case 2 :
 deleteFromBeg();
    break;
case 3:
deleteFromEnd();;
   break;
case 4:
cout<<"enter the position to delete the  node :";
cin>>pos;
deleteFromanyposition( pos);
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
            
            temp = temp->next;
        }
    }
}


void deleteFromBeg()
{
struct node * toDelete;
    if(head == NULL)
    {
    cout<<"empty";
    }
    else
    {
        toDelete = head;
        head = head->next; 
        if (head != NULL)
            head->back = NULL; 
        delete(toDelete); 
        cout<<"DELETION SUCCESSFUL FROM THE BEGINNING"<<endl;
    }
}

void deleteFromEnd()
{
    struct node * toDelete;
    if(end == NULL)
    {
    cout<<"empty";
    }
    else
    {
        toDelete = end;
        end = end->back; 
        if (end != NULL)
            end->next = NULL; 

        delete(toDelete);      
          cout<<"DELETION SUCCESSFUL FROM THE END"<<endl;
    }
}

void deleteFromanyposition(int pos)
{
    struct node *current;
    int i;
    current = head;
    for(i=1; i<pos && current!=NULL; i++)
    {
        current = current->next;
    }

    if(pos == 1)
    {
        deleteFromBeg();
    }
    else if(current == end)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->back->next = current->next;
        current->next->back = current->back;

        delete(current); // Delete the n node
     cout<<"DELETION SUCCESSFUL FROM THE ENTERED POSITION"<<endl;
    }
    else
    {
        cout<<"INVALID POSITION"<<endl;
    }
}
