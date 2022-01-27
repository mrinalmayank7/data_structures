#include<iostream>
using namespace std;
#define MAX 5
int S[MAX];
int top=-1;

bool isEmpty();
bool isFull();


void display(){
int i;
if(isEmpty()){
cout<<"UNDERFLOW"<<endl;
}
else{
for(i=top;i>=0;i--){
cout<<S[i]<<" ";	
}
cout<<endl;	
}

}
void push(int element){
	if(isFull()){
		cout<<"OVERFLOW"<<endl;
	}
	else{
		top++;
		S[top]=element;
	}
}

void pop(){
	if(isEmpty()){
		cout<<"UNDERFLOW"<<endl;
	}
	else{
		cout<<S[top]<<" Deleted"<<endl;
		top--;
	}
}
	
bool isEmpty(){
	if(top==-1){
		return true;
	}
	else{
		return false;
	}	
}
bool isFull(){
	if(top==MAX-1){
		return true;
	}
	else{
		return false;
	}
}

void peek(){
	
	cout<<"TOP : "<<S[top]<<endl;
}
int main(){
int ch, element;
do{
cout<<"\n1.DISPLAY"<<endl<<"2.PUSH"<<endl<<"3.POP"<<endl<<"4.PEEK"<<endl
    <<"5.EXIT"<<endl;
cout<<"ENTER YOUR CHOICE :";
cin>>ch;
cout<<"\n";
switch(ch){
case 1:
	display();
	break;
case 2:
	cout<<"ENTER THE ELEMENT TO PUSH :";
	cin>>element;
	push(element);
	break;
case 3:
	pop();
	break;
case 4:
    peek();
	break;
case 5:
	return 0;
		
default :
	cout<<"INVALID CHOICE";
	break;
}
}while(ch<=5);	


}
