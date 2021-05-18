#include<iostream>
using namespace std;
void BubbleSort(int[],int);
int main()
{
	int A[]={8,22,7,9,31,19,5,13}, item ,n=8,index,i;

   BubbleSort(A,n);
   cout<<"The sorted array is:"<<endl;
     for(i = 0; i<n; i++) {
      cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
   }
   return 0;
}
//Bubble sort function below 
void BubbleSort(int A[],int size)
{
	int tmp , ctr=0,j,k,i;
	for (i=0;i<size;i++){
	for(j=0;j<(size-1-i);j++){
		
		if (A[j]>A[j+1])
		{
		tmp=A[j];
		A[j]=A[j+1];
		A[j+1]=tmp;	
		}
	}
cout<<"array after iteration "<<++ctr<<" is :"<<endl;
for(int k =0;k<size;k++)
cout<<A[k]<<" ";
cout<<endl;		
	}
}
     
