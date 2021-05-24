#include<iostream>
using namespace std ;
struct node {
    int data;         
    struct node *next;  
}*head;

void createList(int n);
void insertNode(int data, int position);
int  search(int key);
void displayList();

int main()
{
int n, data ,keyToSearch,index,position,ch;
cout<<"ENTER THE NUMBER OF NODES IN THE LIST : ";
cin>>n;
createList(n);
do
 {
cout<<"......MENU........"<<endl;
cout<<"1.DISPLAY"<<endl<<"2.INSERT "<<endl<<"3.SEARCH "<<endl<<"4.EXIT"<<endl;
cout<<"_________________________"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>ch;
switch(ch)
{
case 1:	
cout<<"DATA IN THE LIST"<<endl;
    displayList();
    break;
case 2 :
cout<<"Enter the position to insert new node: ";
cin>>position;
cout<<"Enter data to insert at  position "<<position<<"   of the list: ";
cin>>data;
    insertNode(data, position);
    break;
case 3:
    cout<<"Enter element to search: ";
    cin>>keyToSearch;
    index = search(keyToSearch);
    if (index >= 0)
        cout<<keyToSearch<<" Found in the list at position  :"<< index + 1<<endl;
    else
        cout<< "not FOUND!"<<endl;
   break;
case 4:       
    return 0;
    
default : cout<<"OOP's ,NOT A VALID CHOICE!";
}}
while(ch<=4);
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;
    head = new node;
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
               cout<<"Enter the data of node "<<i<<" : ";
               cin>>data;
                newNode->data = data; 
                newNode->next = NULL; 
                temp->next = newNode; 
                temp = temp->next; 
              }
}}}

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
            cout<< temp->data<<" "; 
            temp = temp->next; 
			            
        }
		cout<<endl;
		}}
        
int search(int key)
{
    int index;
    struct node *curNode;
    index = 0;
    curNode = head;
    while (curNode != NULL && curNode->data != key)
    {
        index++;
        curNode = curNode->next;
    }
    return (curNode != NULL) ? index : -1;
}

void insertNode(int data, int position)
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
            cout<<data<<" INSERTED SUCCESSFULLY AT POSITION "<<position<<endl;
        }
        else
        {
            cout<<"UNABLE TO INSERT DATA AT THE GIVEN POSITION"<<endl;
        }}}


