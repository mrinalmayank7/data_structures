#include<iostream>
using namespace std;
struct node {
    int data;         
    struct node *next;  
}*head;

void createList(int n);
int  search(int key);
void displayList();

int main()
{
int n, data ,keyToSearch,index;
cout<<"Enter the total number of elements : ";
cin>>n;
createList(n);
cout<<"DATA IN THE LIST"<<endl;
    displayList();
    
    
    cout<<"Enter element to search: ";
    cin>>keyToSearch;
    index = search(keyToSearch);
    if (index >= 0)
        cout<<keyToSearch<<" found in the list at position "<< index + 1;
    else
        cout<< "not FOUND!";
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

