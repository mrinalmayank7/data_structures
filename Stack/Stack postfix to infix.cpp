#include<iostream>
#include<stack>
using namespace std; 
  
bool Operand(char x) 
{ 
   return (x >= 'a' && x <= 'z') ||  (x >= 'A' && x <= 'Z'); 
} 
 
string conversion(string post) { 
stack<string> o; 
for (int i=0; post[i]!='\0'; i++) 
    {  
        if (Operand(post[i])) 
        { 
           string op(1, post[i]); 
           o.push(op); 
        } 
        else
        { 
            string op1 = o.top(); 
            o.pop(); 
            string op2 = o.top(); 
            o.pop(); 
            o.push("(" + op2 + post[i] + op1 + ")"); 
        } 
    } 
    return o.top(); 
} 
 
int main() 
{ 
    string post;
	cout<<"ENTER THE POSTFIX EXPRESSION :"; 
	cin>>post;
    cout<<"INFIX EXPRESSION IS :"<<conversion(post); 
    return 0; 
} 
