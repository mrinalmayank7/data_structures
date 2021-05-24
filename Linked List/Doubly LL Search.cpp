#include<iostream>
using namespace std;
struct node {
    int data;
    struct node * back;
    struct node * next;
}*head,*end;

void create(int n);
void display();
int  search(int key);

int main()
{
    int n ,data ,keyToSearch,index;
    head = NULL;
    end = NULL;    
cout<<"How many nodes do you want to create : ";
cin>>n;
    create(n); 
    display();
    
    cout<<"Enter element to search: ";
    cin>>keyToSearch;
    index = search(keyToSearch);
    if (index >= 0)
        cout<<keyToSearch<<" found in the list at position "<< index + 1;
    else
        cout<< "not FOUND!";
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


