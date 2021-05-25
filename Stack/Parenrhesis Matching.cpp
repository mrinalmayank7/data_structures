#include<iostream>
#include<stack>
using namespace std;
bool parenthesis(string );
main(){
   string data ;
   cout<<"Enter the expression  :";
   cin>>data;
   if (parenthesis(data))
      cout << "The expression BALANCED ";
   else
      cout << "OOP,s ! NOT A BALANCED EXPRESSION ";
}
bool parenthesis(string data) {
stack<char>s;
char ch;
for (int i= 0; i<data.length(); i++) {   
      if (data[i]=='('||data[i]=='['||data[i]=='{') {    //when it is opening bracket, push into     stack
         s.push(data[i]);
         continue;
      }
      if (s.empty())    //stack cannot be empty as it is not opening bracket, there must be closing     bracket
         return false;
         switch (data[i]) {
            case ')':    //for closing parenthesis, pop it and check for braces and square brackets
               ch = s.top();
               s.pop();
               if (ch=='{' || ch=='[')
                  return false;
                  break;
            case '}': //for closing braces, pop it and check for parenthesis and square brackets
               ch = s.top();
               s.pop();
               if (ch=='(' || ch=='[')
                  return false;
                  break;
            case ']': //for closing square bracket, pop it and check for braces and parenthesis
               ch = s.top();
               s.pop();
               if (ch =='(' || ch == '{')
                  return false;
                  break;
         }
      }
      return (s.empty()); //when stack is empty, return true
}

