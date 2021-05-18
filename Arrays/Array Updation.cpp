#include <iostream>                                           
using namespace std;
int main()
{
   int A[] = {1,3,5,7,8};
   int k = 3, n = 5, item = 10;
   int i, j;
   cout<<"array elements before updation "<<endl ;
  for(i = 0; i<n; i++) {
      cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
   }
    
   A[k-1] = item;

   cout<<"The array elements after updation "<<endl;
	for(i = 0; i<n; i++) {
    cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
   }  
}

//Algorithm
//Start
//Set A[K-1] = ITEM
//Stop
