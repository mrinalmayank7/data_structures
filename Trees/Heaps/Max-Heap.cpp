#include <iostream>
#include <vector>
#include<queue>
using namespace std;
 

void insert(vector<int>& A, int key){  //since index starting from 0 so children of i are 2i+1 (odd), 2i+2 (even)
    auto i = A.size();                 //example : children of 0 are 1 and 2, children of 2 are 5 and 6
    A.emplace_back(key);
    while (i > 0 && key > A[i % 2 == 0 ? (i-2)/2 : (i-1)/2]){//  even children = (i-2)/2 :odd children (i-1)/2
        A[i] = A[i % 2 == 0 ? (i-2)/2 : (i-1)/2];
        i = i % 2 == 0 ? (i-2)/2 : (i-1)/2;    
    }
    A[i] = key;
}
void swap(int *a, int *b){
int temp;
temp= *a;
*a=*b;
*b=temp;
}

void Delete(vector<int>& A){
	auto n = A.size();
	A[0]=A[n-1];
	A.resize(A.size()-1);
	int i=0;
    int j=2*i+1; //since index starting from 0
    while(j<n-2){
     if(A[j+1]>A[j]){
     	j=j+1;
	 }
	 if(A[i]<A[j]){
	 	swap(&A[i],&A[j]);
	 	i=j; //make j as new parent
	 	j=2*j+1; // set new child
	 }
	 else{
	 	break; //if parent A[i] > children A[j] then end the loop
	 }
	}
}
		
	


void create(vector<int>& A){
int n,element;
cout<<"IF ALREADY CREATED, NEW ELEMENTS WILL BE ADDED IN THE HEAP"<<endl;
cout<<"HOW MANY ELEMENTS YOU WANT TO INSERT IN THE HEAP ? ";
cin>>n;
for(int i=0;i<n;i++){
cout<<"ENTER ELEMENT "<<i+1<<" : ";
cin>>element;
insert(A,element);
}
}

  
int main() {
    vector<int> A;
    int ch,key;
    do{
    	cout<<"\n1.CREATE"<<endl<<"2.INSERT"<<endl<<"3.DELETE"<<endl<<"4.DISPLAY"<<endl<<"5.EXIT"<<endl;
    	cout<<"ENTER YOUR CHOICE :";
    	cin>>ch;
    	switch(ch){
    	case 1:create(A);
		       break;
		case 2:
		cout<<"ENTER THE KEY TO INSERT : ";
		cin>>key;	
		insert(A,key);
		       break;
		case 3:
			Delete(A);
			break;
		case 4: 
		for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
		}
		break;
	    case 5:
		    return 0;
			break;
		default : 
		cout<<"INVALID CHOICE"<<endl;
		break;	
		}
	}while(ch<=5);

}
