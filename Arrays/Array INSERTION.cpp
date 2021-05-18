#include <iostream>                                           
using namespace std;
int main()
{
   int A[20] , element , n , i , k , j;
   cout<<"enter the size of the array:";
   cin>>n;
   for(i=0;i<n;i++){
	cout<<"enter the array elements:";
	cin>>A[i];
   }
   cout<<"array elements before insertion "<<endl ;
  for(i = 0; i<n; i++) {
      cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
   }
    cout<<"enter the element to insert:";
   cin>>element;
   cout<<"enter the position of the element";
   cin>>k; 
   j=n-1;
   while( j >= k) {
      A[j+1] = A[j];
      j = j - 1;
   } 
 n = n + 1;
   A[k] = element;
   cout<<"The array elements after insertion "<<endl;
 for(i = 0; i<n; i++) {
      cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
   }  
}
