#include <iostream>                                           
using namespace std;
int main()
{
   int A[20];
   int item , n ;
   int i, j = 0;
   
   
   cout<<"enter the size of the array:";
   cin>>n;
   for(i=0;i<n;i++)
{
	cout<<"enter the array elements:";
	cin>>A[i];
   }    
   
  cout<<"array elements are "<<endl ;
  for(i = 0; i<n; i++) {
      cout<<"="<<A[i]<<endl;
  }
      
 cout<<"enter the element to find the position";
 cin>>item;
  while( j < n){
      if( A[j] == item ){
      	 cout<<" element " <<item<<" is at position "<< j<<endl;
	  }
 	j=j+1;
   }  
}
 
