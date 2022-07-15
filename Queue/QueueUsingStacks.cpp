#include<iostream>
#include<stack>
using namespace std;
stack<int>S1;
stack<int>S2;

void enqueue(int element){
	S1.push(element);
	cout<<S1.top()<<" ENQUEUED"<<endl;
}
void dequeue(){
	if(S1.empty() && S2.empty()){
	cout<<"OVERFLOW"<<endl;	
	}
	else{
	if(S2.empty()){
		while(S1.empty()==false){
			S2.push(S1.top());
			S1.pop();
		}
	}
	int x=S2.top();
	S2.pop();
	cout<<x<<" DEQUEUED"<<endl;		
	}
}

void getsize(){
	cout<<"SIZE OF THR QUEUE IS "<<S1.size()+S2.size();
}



int main(){
	enqueue(12);
	enqueue(13);
	enqueue(15);
	enqueue(17);
	enqueue(19);
	dequeue();
	dequeue();	
	dequeue();
	dequeue();
	dequeue();
	dequeue();
}

