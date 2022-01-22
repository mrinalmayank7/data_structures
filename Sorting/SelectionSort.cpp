#include<iostream>
using namespace std;

void swap(int *a, int *b){
int temp;
temp= *a;
*a=*b;
*b=temp;
}
void selectionsort(int A[],int n){
	int i,j,k;
	for(i=0;i<n-1;i++){ //i for each pass
		for(j=k=i;j<n;j++){ //j for comparison , k for holding smallest element
		if(A[j]<A[k]){ //if A[j]>=A[k] , k will remail at previous smallest position
			k=j; //assign k to samllest position
		}
       swap(&A[i],&A[k]); //swap A[i] with smallest element = A[k] and move pointer to next element( i++)
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
	selectionsort(A,n);
	for(int i=0;i<n;i++){
	cout<<A[i]<<" ";
	}
		
}
