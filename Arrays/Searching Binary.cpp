#include <iostream>
using namespace std;
int main()
{
int i, low, high, mid, n, x, a[18];
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
cin>>x;
low = 0;
high = n-1;
mid = (low+high)/2;

while (low <= high)
{
	 if (a[mid]==x)
 {
	cout<<x<<" found at position "<<mid;
	break;
	
	}
	else if (a[mid]<x)
	{
		low=mid+1;
	}
  
	else
	{
		high=mid-1;
			
	}
	mid=(low+high)/2;	
}

if(low > high)
cout<<"element not found";
return 0;
}



//Algorithm
//1. START
//2.SET LOW =0, HIGH = N-1
//3.PUT (LOW+HIGH)/2 IN MID
//4. IF LOW>HIGH GO TO STEP 11 , ELSE GO TO STEP 5
//5.IF A[MID]<X GO TO STEP 8 ELSE GO TO STEP 6
//6.IF A[MID]=X GO TO STEP 9 ELSE GO TO STEP 7
//7.IF A[MID]>X GO TO STEP 10 
//8.WRITE LOW = MID+1
//9. WRITE MID
//10. WRITE HIGH=MID+1
//11.PRINT ELEMENT NOT FOUND
//12. END
