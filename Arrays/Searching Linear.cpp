#include <iostream> 
using namespace std; 
int main()
{
int a[20],  n,  element , i=0,found;

cout<<"enter the size of the array:";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"enter the array elements:";
cin>>a[i];
} 
cout<<"array elements are  "<<endl ;
for(i = 0; i<n; i++) 
{
cout<<"["<<i<<"]"<<"="<<a[i]<<endl;
} 
cout<<"enter the array element to search:";
cin>>element;

 for (i = 0; i < n; i++) 
 {
 
    if (a[i] == element ) {
         found=1; 
         break;
     }  
}
if (found==1) 
cout<<element <<" found at index "<<i;
else
cout<<"OOP's element not found!"; 
 
}
//Algorithm
//1.Start
//2.Set i=0
//3.while  i<n GO TO STEP 4 ELSE GO TO STEP 5
//4.IF A[i]=element return true value and go to step 6 
//5.WRITE element not found as error message 
//6. WRITE element found at position i
//7.STOP

  

