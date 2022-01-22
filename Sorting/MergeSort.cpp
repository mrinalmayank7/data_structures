#include<iostream>
using namespace std;

void merge(int A[],int l, int mid, int h){ 
//lets assume A[] is dividede in 2 parts, one from l to mid and other from mid to high
int i=l,j=mid+1,k=l;
int B[100];
//i<=m (equals mid) (size of first list in 2 way merge ) , j<=n (equals h ) (size of second list 2 way merge )
while(i<=mid && j<=h){
if(A[i]<A[j]){ //A[i] is first list and A[j] is second list, here we copy the smallest element and place it in merged list
B[k++]=A[i++]; 
}
else{
B[k++]=A[j++]; 	
}	
}
//any one of the for loop below will execute if thr element is left in any of the list then directly copy after smallest element
for(;i<=mid;i++){
B[k++]=A[i];	
}
for(;j<=h;j++){
B[k++]=A[j];	
}
//copy merged list into original list
for(i=l;i<=h;i++){
	A[i]=B[i];
}
}
void mergesort(int A[],int l, int h){
	int mid;
	if(l<h){
		mid=(l+h)/2;
		mergesort(A,l,mid); //list 1
		mergesort(A,mid+1,h); // list 2
		merge(A,l,mid,h);
	}
}

int main(){
	int A[100],n;
	cout<<"ENTER ARRAY SIZE : ";
	cin>>n;
	cout<<"ENTER ARRAY ELEMENTS"<<endl;
	for(int i=0;i<n;i++){
	cin>>A[i];
	}
	mergesort(A,0,n-1);
	for(int i=0;i<n;i++){
	cout<<A[i]<<" ";
	}
		
}
