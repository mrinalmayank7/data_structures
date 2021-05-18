#include<iostream>
using namespace std;
void SelSort(int[],int);
int main()
{
	int A[50] , item ,n,index,i;
	cout<<"enter the size of the array:";
	cin>>n;
	cout<<"enter array elements :"<<endl;

  for(i = 0; i<n; i++) {
	cin>>A[i];

}
   SelSort(A,n);
   cout<<"The sorted array is:"<<endl;
     for(i = 0; i<n; i++) {
      cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
   }
   return 0;
}
//Selection sort function below 
void SelSort(int A[],int size)
{
	int small , pos , tmp ,i ,j;
	for (i=0;i<size;i++){
		
		small=A[i];
		pos=i;
		for(j=i+1;j<size;j++){
			if(A[j]<small){
				small=A[j];
				pos=j;
			}
		}
tmp=A[i];
A[i]=A[pos];
A[pos]=tmp;
	}
cout<<"array after iteration "<<A[j]<<" is :"<<endl;
for(int k =0;k<size;k++)
cout<<A[k]<<" ";
cout<<endl;		
	}

     
