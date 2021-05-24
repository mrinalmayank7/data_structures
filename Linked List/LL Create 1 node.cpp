#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
  };	
int main()
{
node *head, *tail , *temp ;
int value,n;

      head=NULL;
      tail=NULL;
      
      cout<<"enter the value";
      cin>>value;
      
  
      temp=new node; //dynamic memory allocation 
      temp->data=value;
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {	
        tail->next=temp;
        tail=temp;
      }
    temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<"\t";
      temp=temp->next;
    }
    
  }
