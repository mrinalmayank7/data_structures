#include<iostream>
using namespace std;
void InsSort(int[],int);
int main()
{
	int A[] ={44, 33, 11, 55, 66,77, 90,88, 40}, item ,n=9,index,i;
   InsSort(A,n);
   cout<<"The sorted array is:"<<endl;
     for(i = 0; i<n; i++) {
      cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
   }
   return 0;
}

void InsSort(int A[],int size)
{
int tmp,j,i;
for (int i=0 ; i<size;i++){
	tmp=A[i];
	j=i-1;
	while(tmp<A[j])
	{
		A[j+1]=A[j];
		j--;
	}
A[j+1]=tmp;		
	}
}
