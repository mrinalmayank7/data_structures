#include<iostream>
using namespace std;

void swap(int *a, int *b){
int temp;
temp= *a;
*a=*b;
*b=temp;
}
void bubblesort(int A[],int n){
	for(int i=0;i<n-1;i++){ //passes = n-1
		for(int j=0;j<n-1-i;j++){ //comparisons =n-i-1
			if(A[j]>A[j+1]){ //swap if next element is smaller than previous element
				swap(&A[j],&A[j+1]);
			}
		}	
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
	bubblesort(A,n);
	for(int i=0;i<n;i++){
	cout<<A[i]<<" ";
	}
		
}
