#include <iostream> 
#include <stack> 
using namespace std; 
  
bool Operator(char x) { 
  return (x=='+'||x=='-'||x=='/'||x=='*'||x=='^');
} 
  
string conversion(string prefix) { 
  stack<string> o; 

  for (int i = prefix.size() - 1; i >= 0; i--){ // reading from right to left  
    if (Operator(prefix[i])) { 
 
      string op1 = o.top(); 
	  o.pop(); 
      string op2 = o.top();   
	  o.pop();  
      string temp = "(" + op1 + prefix[i] + op2 + ")"; 
      o.push(temp); 
    } 
    else { 
      o.push(string(1, prefix[i])); 
    } 
  } 
  return o.top(); 
} 

int main() { 
  string prefix;
	cout<<"ENTER THE PREFIX EXPRESSION :"; 
	cin>>prefix;
    cout<<"INFIX EXPRESSION IS :"<<conversion(prefix); 
    return 0; 
} 
