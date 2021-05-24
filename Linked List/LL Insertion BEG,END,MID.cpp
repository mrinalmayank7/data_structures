#include<iostream>
using namespace std;
struct node {
    int data;         
    struct node *next;  
}*head;

void createList(int n);
void insertNodeAtBeginning(int data);
void insertNodeAtEnd(int data);
void insertNodeAtMiddle(int data, int position);
void displayList();

int main()
{
int n, data , position;
cout<<"Enter the total number of elements : ";
cin>>n;
createList(n);
cout<<"DATA IN THE LIST"<<endl;
    displayList();
 //Take data to insert at beg 
cout<<"Enter data at the beginning of the list : ";
cin>>data;
    insertNodeAtBeginning(data);
cout<<"DATA IN THE LIST AFTER INSERTION AT THE BEGINNING "<<endl;
    displayList();  
//take data to insert at end	
cout<<"Enter data at the end of the list : ";
cin>>data;
    insertNodeAtEnd(data);
cout<<"DATA IN THE LIST AFTER INSERTION AT THE END "<<endl;
    displayList();
//Take data  at user specified location
cout<<"Enter data to insert at any position  of the list: ";
cin>>data;
cout<<"Enter the position to insert new node: ";
cin>>position;
    insertNodeAtMiddle(data, position);
    cout<<"DATA IN THE LIST AFTER INSERTION AT POSITION  "<< position<<endl;
    displayList();

    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;
    head = new node; //DYNAMIC MEMORY ALLOCATION 
    if(head == NULL){
    	cout<<"unable to allocate memory";
    }
    else{
    cout<<"Enter the data of node 1 : ";
    cin>>data;
        head->data = data; 
        head->next = NULL;
        temp = head;
        for(i=2; i<=n; i++)
        {
            newNode = new node;
            if(newNode == NULL)
            {
              cout<<"unable to allocate memory";
                break;
            }
            else{
               cout<<"enter the data of node "<<i<<" : ";
               cin>>data;
                newNode->data = data; 
                newNode->next = NULL; 
                temp->next = newNode; 
                temp = temp->next; 
              }
        }
        cout<<"SINGLY LINKED LIST CREATED"<<endl;
    }
}
void displayList()
{
    struct node *temp;
    if(head == NULL){
        cout<<"empty";
    }
    else{
        temp = head;
        while(temp != NULL)
        {
            cout<< temp->data<<endl; 
            temp = temp->next;             
        }
    }
}

void insertNodeAtBeginning(int data)
{
    struct node *newNode;
    newNode = new node;
    if(newNode == NULL){
    cout<<"Unable to allocate memory.";
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->next = head; // Link address part
        head = newNode;          // Make newNode as first node
       cout<<"DATA INSERTED SUCCESSFULLY AT THE BEGINNING"<<endl;
    }
}
void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;
    newNode = new node;

    if(newNode == NULL)
    {
    cout<<"Unable to allocate memory.";
    }
    else
    {
        newNode->data = data; 
        newNode->next = NULL; 
        temp = head;
        
        while(temp->next != NULL)
        temp = temp->next;
        temp->next = newNode;

        cout<<"DATA INSERTED SUCCESSFULLY AT THE END"<<endl;
    }
}

void insertNodeAtMiddle(int data, int position)
{
    int i;
    struct node *newNode, *temp;

    newNode =new node;

    if(newNode == NULL)
    {
        cout<<"Unable to allocate memory.";
    }
    else
    {
        newNode->data = data; 
        newNode->next = NULL;
        temp = head;
        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }
        if(temp != NULL)
        {
            newNode->next = temp->next; 
            temp->next = newNode;
            cout<<"DATA INSERTED SUCCESSFULLY"<<endl;
        }
        else
        {
            cout<<"UNABLE TO INSERT DATA AT THE GIVEN POSITION";
        }
    }
}

