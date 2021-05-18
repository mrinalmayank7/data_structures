#include <iostream>                                           
using namespace std;
int main()
{
int A[25],n,i,ch , element , k,j;
do
 { 
cout<<"......MENU........"<<endl;
cout<<"1.CREATE"<<endl<<"2.DISPLAY "<<endl<<"3.INSERT"<<endl<<"4.DELETE "<<endl<<"5.EXIT"<<endl;
cout<<"_________________________"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>ch;
switch(ch)
{
case 1: 
	cout<<"enter the size of the array:";
    cin>>n;
    for(i=0;i<n;i++){
	cout<<"enter the array elements:";
	cin>>A[i];
    } 
	break;  
case 2 :
	cout<<"The array elements are:"<<endl ;
    for(i = 0; i<n; i++) {
    cout<<"["<<i<<"]"<<"="<<A[i]<<endl;
    }
    break;
case 3 :
	j=n;
    cout<<"enter the element to insert:";
    cin>>element;	
    cout<<"enter the position of the element:";
    cin>>k;
    while( j >= k) {
      A[j+1] = A[j];
      j = j - 1;
    }
    n = n + 1;
    A[k] = element;
   break;  
case 4 :   
   cout<<"enter the position of the element to delete :";
   cin>>k;
   j=k+1;	
   while( j < n) {
      A[j-1] = A[j];
      j = j + 1;
   }	
   n = n -1;
   cout<<"Deleted element is "<<A[k]<<endl;
   break;  
case 5 :
	return 0;
default :
	cout<<"INVALID CHOICE:";	
}}
while(ch<=5);
}


