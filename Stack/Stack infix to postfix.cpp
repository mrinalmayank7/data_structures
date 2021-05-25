#include<iostream>
#include<stack>
using namespace std; 
  
int preceed(char a) 
{ 
    if(a == '+' || a == '-') 
    return 1;
    else if(a == '*' || a == '/') 
    return 2;  
    else if(a == '^') 
    return 3;
    else
    return -1; 
} 
void conversion (string infix) { 
    stack<char> o; 
    o.push('N'); //one character to avoid underflow 
    string post; 
    for(int i = 0; i < infix.length(); i++) 
    { 
        if((infix[i] >= 'a' && infix[i] <= 'z')||(infix[i] >= 'A' && infix[i] <= 'Z')) 
        post+=infix[i];  
        else if(infix[i] == '(')   
        o.push('('); 
        else if(infix[i] == ')') 
        { 
            while(o.top() != 'N' && o.top() != '(') { 
               post= post + o.top(); 
                o.pop();
            } 
            if(o.top() == '(') 
            { 
                char c = o.top(); 
                o.pop(); 
            } 
        } 
        else{ 
            while(o.top() != 'N' && preceed(infix[i]) <= preceed(o.top())) { 
                post=post +  o.top();
				o.pop();  
            } 
            o.push(infix[i]); 
        }}  
    while(o.top() != 'N') {  
        post = post +o.top();  
        o.pop();
    }    
    cout <<"POSTFIX EXPRESSION IS : "<< post << endl; 
}
int main() 
{ 
    string infix;
	cout<<"ENTER THE INFIX EXPRESSION: ";
	cin>>infix; 
    conversion (infix); 
    return 0; 
} 

