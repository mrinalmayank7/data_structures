#include <iostream>                                           
using namespace std;
int main()
{
   int A[10];
   int k , n , j ;
   int i;
 cout<<"enter the size of the array:";
   cin>>n;
   for(i=0;i<n;i++)
{
	cout<<"enter the array elements:";
	cin>>A[i];
   }   
   cout<<"array elements before deletion "<<endl ;
  for(i = 0; i<n; i++) {
      cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
   }
   cout<<"enter the position of the element to delete :";
   cin>>k;
   j=k;	
   while( j < n) {
      A[j-1] = A[j];
      j = j + 1;
   }
	
   n = n -1;
   
   cout<<"The array elements after deletion  "<<endl;
 for(i = 0; i<n; i++) {
      cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
   }  
}

//Algorithm
//1. Start
//2. Set J = K
//3. Repeat steps 4 and 5 while J < N
//4. Set A[J-1] = A[J ]
//5. Set J = J+1
//6. Set N = N-1 , it Reset the number N of elements in A
//7. Stop



