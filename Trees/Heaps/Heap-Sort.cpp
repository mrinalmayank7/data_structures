#include <iostream>
#include <vector>
#include<queue>
using namespace std;
 

void insert(vector<int>& A, int key){  
    auto i = A.size();                 
    A.emplace_back(key);
    while (i > 0 && key > A[i % 2 == 0 ? (i-2)/2 : (i-1)/2]){
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
void HeapSort(vector<int>& A){
	int n = A.size();
	for(int k=n;k>0;k--){
	int temp=A[0];
	A[0]=A[k-1];	
	//A.resize(A.size()-1);
	int i=0;
    int j=2*i+1; //since index starting from 0
    while(j<k-2){
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
	A[k-1]=temp;
	}			
}
		
	  
int main() {
    vector<int> A;
    int n,element,i;
    cout<<"ENTER NUMBER OF ELEMENTS TO SORT :";
    cin>>n;
    for(i=0;i<n;i++){
    cout<<"ENTER ELEMENT "<<i+1<<" : ";
     cin>>element;
     insert(A,element);
    }
    HeapSort(A); 
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
		}
	return 0;
}
