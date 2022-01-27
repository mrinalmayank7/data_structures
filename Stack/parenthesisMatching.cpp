#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string exp, char open,char close){
	stack<char>s;
 	for(int i=0;i<exp.length();i++){ //'\0' is string terminator
 	 if(exp[i]==open){
 	 	cout<<exp[i]<<" PUSHED"<<endl;
 	 	s.push(exp[i]);
	  }	
	 else if(exp[i]==close){                      //exp[i]==')'
	     if(s.empty()){ 
	        cout<<"EXTRA CLOSING BRACKET"<<endl;
            // if empty and closing parentheis is encountered then there is extra closing parenthesis
	     	return false;
		 }
		 else{
		 	cout<<exp[i]<<" POPPED"<<endl;
		 	s.pop();        
		 }	
	 }
	 }
	 return s.empty();//if stack is empty after traversing complete expression 
 }
 
 bool parentheisMatch(string exp){
 	return (isBalanced(exp,'(',')') && isBalanced(exp,'[',']') && isBalanced(exp,'{','}')); 
 }

int main(){
string exp;
cout<<"ENTER EXPRESSION :";
cin>>exp;
if(parentheisMatch(exp)){
	cout<<"PARENTHEIS ARE BALANCED";
}
else{
	cout<<"PARENTHEIS ARE NOT BALANCED";	
}
	
}
