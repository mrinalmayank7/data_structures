#include<iostream>
using namespace std;


void insertionsort(int A[],int n){
	int tmp,j,i;
	for(int i=1;i<n;i++){ 
	int tmp=A[i];
	j=i-1;
	while(tmp<A[j])
	{
		A[j+1]=A[j];
		j--;
	}
   A[j+1]=tmp;		
	}
	
	
	}	

int main(){
	int A[30],n;
	cout<<"ENTER ARRAY SIZE : ";
	cin>>n;
	cout<<"ENTER ARRAY ELEMENTS"<<endl;
	for(int i=0;i<n;i++){
	cin>>A[i];
	}
	insertionsort(A,n);
	for(int i=0;i<n;i++){
	cout<<A[i]<<" ";
	}
		
}
