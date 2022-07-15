#include<iostream>
#include<vector>

#define SIZE 10
using namespace std;
bool isprime(int n){
	for(int i=2;i<n/2;i++){
		if(n%i == 0){
			return false;
			break;
		}
	}
	return true;
}
int nearestprime(){
	int i=0;
	for(i=SIZE;i>0;i--){
		if(isprime(i)){
			break;
		}
	}
	return i;
}
int Hash(int key){
	return key%SIZE;
}
int Hash2(int key){
	int R=nearestprime();
	return R-(key%R);
}
int DoubleHashing(vector<int> &HT,int key){
	int H1=Hash(key),H2=Hash2(key),i=0;
	while(HT[(H1 + i*H2)%SIZE]!=0){
		i++;
	}
	return (H1 + i*H2)%SIZE;
}
void insert(vector<int> &HT,int key){
	int index=Hash(key);
	if(HT[index]!=0){
		index=DoubleHashing(HT,key);
	}
	HT[index]=key;
	
}
void search(vector<int> &HT,int key){
	int H1=Hash(key),H2=Hash2(key),i=0,flag=0;
	while(i<SIZE){
		if(HT[(H1 + i*H2)%SIZE]==key){
			flag=1;
			break;
		}
		i++;
	}
	if(flag==1){
		cout<<"ELEMENT FOUND AT INDEX "<<(H1 + i*H2)%SIZE<<endl;
	}
	else{
		cout<<"ELEMENT NOT FOUND"<<endl;
	}	
}
int main(){
	vector<int> HT(SIZE,0);
	insert(HT,5);
	insert(HT,25);
	insert(HT,15);
	insert(HT,35);
	for(int i=0;i<HT.size();i++){
		cout<<HT[i]<<" ";
	}
	cout<<endl;
	search(HT,35);


}
