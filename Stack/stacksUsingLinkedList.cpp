#include<iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
}*top=NULL; 


//since insertion & deletion at head takes O(1) time as compared to tail O(n)
//therefore we will select top as head node
//if top =NULL , stack is empty
//size of linked list is unlimited, taking fixed size is our choice

void push(int DATA){
struct Node *temp;
temp =new Node;
if(temp==NULL){
cout<<"STACK IS FULL / OVERFLOW"<<endl;
}
else{
temp->data=DATA;
temp->next=top;
top=temp;
}
}

void pop(){
struct Node *temp;
temp=top;
if(top==NULL){
cout<<"STACK IS EMPTY / UNDERFLOW"<<endl;
}
else{
top=top->next;
cout<<temp->data<<" DELETED"<<endl;
delete(temp);
}
}
void getTop(struct Node *p){
cout<<"TOP NODE IS : "<<p->data<<endl;
}

void getElement(int pos){
struct Node *p=top;
for(int i=0;i<pos-1 && p!=NULL;i++){
p=p->next;	
}
cout<<"ELEMENT AT POSITION "<<pos<<" IS :"<<p->data<<endl;
}
void display(struct Node *p){
while(p!=NULL){
	cout<<p->data<<" ";
	p=p->next;
}
}

void getSize(struct Node *p){
	int count=0;
while(p!=NULL){
	count++;
	p=p->next;
}
cout<<"SIZE OF THE STACK IS : "<<count<<endl;
}

int main(){
int ch,DATA, pos;
do{
cout<<"\n1.PUSH"<<endl<<"2.POP"<<endl<<"3.DISPLAY"<<endl<<"4.GET SIZE"<<endl
    <<"5.GET TOP"<<endl<<"6.GET ELEMENT"<<endl<<"7.EXIT"<<endl;
cout<<"ENTER YOUR CHOICE :";
cin>>ch;
cout<<"\n";
switch(ch){
case 1:
	cout<<"ENTER ELEMENT TO PUSH :";
	cin>>DATA;
	push(DATA);
    break;
case 2:
	pop();
    break;
case 3:
    display(top);
    break;
case 4:
	getSize(top);
	break;
case 5:
	getTop(top);
	break;
case 6:
	cout<<"ENTER THE POSITION TO GET THE ELEMENT :";
	cin>>pos;
    getElement(pos);
	break;
case 7:
	return 0;
		
default :
	cout<<"INVALID CHOICE";
	break;
}
}while(ch<=7);
}




