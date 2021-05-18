#include<iostream>
using namespace std;
void BubbleSort(int[],int);
void SelSort(int[],int);
void InsSort(int[],int);
void quick_sort(int[],int,int);
int partition(int[],int,int);
void merge(int *,int, int , int );
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;                 //divide the array at mid and sort independently using merge sort
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);       //merge or conquer sorted arrays
    }}
int main()
{
	int A[50] , item ,n,index,i,ch;
	cout<<"enter the size of the array:";
	cin>>n;
	cout<<"enter array elements :"<<endl;

  for(i = 0; i<n; i++) {
	cin>>A[i];

}
do
 { 
cout<<"......MENU........"<<endl;
cout<<"1.BUBBLE SORT"<<endl<<"2.SELECTION SORT "<<endl<<"3.INSERTION SORT"<<endl<<"4.QUICK SORT"<<endl<<"5.MERGE SORT"<<endl<<"6.EXIT"<<endl;
cout<<"_________________________"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>ch;
switch(ch)
{
case 1 :
   BubbleSort(A,n);
   cout<<"The sorted array is:"<<endl;
     for(i = 0; i<n; i++) {
      cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
   }
   break;
case 2 :
 SelSort(A,n);
   cout<<"The sorted array is:"<<endl;
     for(i = 0; i<n; i++) {
      cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
   }
   break;
case 3 :
InsSort(A,n);
  cout<<"The sorted array is:"<<endl;
     for(i = 0; i<n; i++) {
      cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
   }
   break;
case 4 :
 quick_sort(A,0,n-1);
    cout<<"The sorted array is:"<<endl;
     for(i = 0; i<n; i++) {
      cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
  }
      break;
case 5 :
 merge_sort(A, 0, n-1);
 cout<<"The sorted array is:"<<endl;
     for(i = 0; i<n; i++) {
      cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
  }
  break;
case 6 :
   return 0;
default :
	cout<<"INVALID CHOICE:";
}}while(ch<=6);
}
//Bubble sort function below 
void BubbleSort(int A[],int size)
{
	int tmp , ctr=0,j,k,i;
	for (i=0;i<size;i++){
	for(j=0;j<(size-1);j++){
		
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
//selection sort function below 
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

//Insertion  sort function below 
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
cout<<"array after Pass "<<i+1<<" is :"<<endl;
for(int k =0;k<size;k++)
cout<<A[k]<<" ";
cout<<endl;		
	}
}

//quick sort
void quick_sort(int A[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(A,l,u);
        quick_sort(A,l,j-1);
        quick_sort(A,j+1,u);
    }
}
int partition(int A[],int l,int u)
{
    int v,i,j,temp;
    v=A[l];
    i=l;
    j=u+1;
    do {
    do
    i++;
             while(A[i]<v&&i<=u);
        do
        j--;
        while(v<A[j]);
        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<j);
    
    A[l]=A[j];
    A[j]=v;
    return(j);
}
    


// Merge sort 
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}


