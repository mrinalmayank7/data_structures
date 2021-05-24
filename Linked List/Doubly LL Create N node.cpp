#include<iostream>
using namespace std;
struct node {
    int data;
    struct node * back;
    struct node * next;
}*head,*end;

void create(int n);
void displayFirst();
void displayEnd();


int main()
{
    int n, ch;
    head = NULL;
    end = NULL;    
cout<<"How many nodes do you want to create : ";
cin>>n;
    create(n); 
    cout<<"Enter 1 to display list from the beginning "<<endl<<"Enter 2 to display  list from the end  " <<endl;
    cin>>ch;
    if(ch==1)
    {
        displayFirst();
    }
    else if(ch == 2)
    {
        displayEnd();
    }
    else 
    cout<<"invalid choice";

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


void displayFirst()
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


/**
 * Display the content of the list from last to first
 */
void displayEnd()
{
    struct node * temp;
    int n = 0;

    if(end == NULL)
    {
        cout<<"empty";
    }
    else
    {
        temp = end;
        cout<<"DATA IN THE LIST:"<<endl;

        while(temp != NULL)
        {
            
            cout<<n<<" : " <<temp->data<<endl; 
            n++;
            
            /* Move the current pointer to previous node */
            temp = temp->back; 
        }
    }
}
