#include<iostream>
using namespace std;
struct node {
    int data;         
    struct node *next;  
}*head;

void createList(int n);
void deleteLastNode();
void deleteFirstNode();
void deleteMiddleNode(int position);
void displayList();

int main()
{
int n, data ,choice,position;
cout<<"Enter the total number of elements : ";
cin>>n;
createList(n);
cout<<"DATA IN THE LIST"<<endl;
    displayList();
 //delete last node    
cout<<"Press 1 to delete last node: ";
cin>>choice;
if(choice == 1)
    deleteLastNode();
cout<<"DATA IN THE LIST AFTER DELETION OF LAST NODE"<<endl; 
    displayList();
//delete first node     
cout<<"Press 2 to delete first node: ";
cin>>choice;
if(choice == 2)
    deleteFirstNode();
cout<<"DATA IN THE LIST AFTER DELETION OF FIRST NODE"<<endl; 
    displayList(); 
//delete specified node
cout<<"Enter the node position you want to delete : ";
    cin>>position;
  deleteMiddleNode(position); 
cout<<"DATA IN THE LIST AFTER DELETION OF" << position<<" NODE"<<endl; 
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
void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;
    if(head == NULL)
    {
        cout<<"List is already empty.";
    }
    else
    {
        toDelete = head;
        secondLastNode = head;
        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == head){
            head = NULL;
        }
        else{
            secondLastNode->next = NULL;
            delete(toDelete);
        }
        cout<<"SUCCESSFULLY DELETED LAST NODE OF LIST"<<endl;
    }}

void deleteFirstNode()
{
    struct node *toDelete;
    if(head == NULL)
    {
        cout<<"List is already empty.";
    }
    else
    {
        toDelete = head;
        head = head->next;
        delete(toDelete);

       cout<<"SUCCESSFULLY DELETED FIRST NODE OF LIST"<<endl;
    }
}

void deleteMiddleNode(int position)
{
    int i;
    struct node *toDelete, *prevNode;
    if(head == NULL) {
        cout<<"List is already empty.";
    }
    else{
        toDelete = head;
        prevNode = head;
        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;
            if(toDelete == NULL)
                break;
        }
        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->next;
                
            prevNode->next = toDelete->next;
            toDelete->next = NULL;
            delete(toDelete);

            cout<<"SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST"<<endl;
        }
        else
        {
            cout<<"Invalid position unable to delete.";
        }
    }
}

