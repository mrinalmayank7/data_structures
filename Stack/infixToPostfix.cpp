#include<iostream>
#include<stack>
using namespace std;


bool isOperand(char op){
	if((op>= 'a' && op <= 'z')||
	   (op>= 'A' && op <= 'Z')){
		return true;
	}
	else {
		return false;
	}
}

int precedence(char op){
	if(op=='+'|| op=='-'){
		return 1;
	}
	else if(op=='*'|| op=='/'){
		return 2;
	}
	else if(op=='^'){
		return 3;
	}
	else {
		return -1;
	}
}

string conversion(string infix){
	stack<char>s;
	string postfix; 
	s.push('N'); //one character to avoid underflow 
	for(int i=0;i<infix.length();i++){
		if(isOperand(infix[i])){
		    postfix=postfix+infix[i];	
		}
		else if(infix[i] == '('){
			s.push(infix[i]);
		}
		else if(infix[i] == ')'){
		while(s.top()!='(' && s.top()!='N'){
			postfix= postfix + s.top(); 
            s.pop();
		}
		if(s.top() == '('){
            s.pop();
		}
		}
		else{
			while(s.top() != 'N' && precedence(infix[i]) <= precedence(s.top())) { 
                postfix=postfix +  s.top();
				s.pop();  
            } 
            s.push(infix[i]);
			}
		}
	
	while(s.top() != 'N') {  
    postfix = postfix +s.top();  
    s.pop();
    }
	return postfix;
}

 


int main(){
string exp;
cout<<"ENTER EXPRESSION :";
cin>>exp;
cout<<conversion(exp);
}
