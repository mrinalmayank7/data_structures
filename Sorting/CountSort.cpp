#include<iostream>
#include<algorithm>
using namespace std;
//COMPLEXITY : O(n+m) where n is size of input array and m is count of count array
//THIS SORTING TAKES EXTRA COUNT SPACE, IF MAX ELEMENT IS VERY LARGE THE SPACE REQUIRED IS HUGE
int CountSort(vector<int> &A){
	int max=*max_element(A.begin(),A.end()),k=0;
	vector<int> B(max+1,0); //Initizlize count array with max element +1 since index start from 0
	for(int i=0;i<A.size();i++){ // LOOP to store count of element A[i] at index of B where index=A[i]
		B[A[i]]= B[A[i]]+1;
	}
	for(int i=0;i<B.size();i++){ // LOOP TO TRAVERSE COUNT ARRAY
		if(B[i]!=0){
			for(int j=B[i];j>0;j--){ // LOOP TO COPY ELEMENTS BACK TO A REPRESENTED BY INDEX AND COUNT AS ELEMENT 
				A[k]=i;              // AFTER COPYING ELEMENT DECREMENT COUNT AND MOVE TO NEXT INDEX TILL IT IS 0
				k++;
			}
		}
	}
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	 }
}
int main(){
vector<int> A={6,3,9,10,15,6,8,12,3,6};
CountSort(A);	
}
