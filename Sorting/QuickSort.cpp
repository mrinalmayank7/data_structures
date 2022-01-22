#include<iostream>
using namespace std;

void swap(int *a, int *b){
int temp;
temp= *a;
*a=*b;
*b=temp;
}
int partition(int A[], int l,int h){// partition the array where partitioning elemment returned is sorted
	int pivot=A[l]; //pivot is set at low 
	int i=l,j=h;
	do{
		do{i++;}while(A[i]<=pivot); // find element greater than pivot , stop when A[i]>pivot
		do{j--;}while(A[j]>pivot); // find element smaller than pivot ,stop when A[j]<=pivot
		if(i<j){
			swap(&A[i],&A[j]); //swap till i>=j
		}
		
	}while(i<j);
	swap(&A[l],&A[j]); //when i>=j interchange j with pivot and pivot is now at sorted position 
	return j; //return the sorted/partitioning element
}
void quicksort(int A[],int l, int h){
if(l<h){
int j=partition(A,l,h); //PARTITION POSITION
quicksort(A,l,j); //Recursive quicksort on left part of the partition
quicksort(A,j+1,h); //Recursive quicksort on right part of the partition
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
	quicksort(A,0,n);
	for(int i=0;i<n;i++){
	cout<<A[i]<<" ";
	}
		
}
