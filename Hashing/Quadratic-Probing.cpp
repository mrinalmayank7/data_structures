#include<iostream>
#include<vector>

#define SIZE 10
using namespace std;
int Hash(int key){
	return key%SIZE;
}
int QuadraticProbing(vector<int> &HT,int key){
	int index=Hash(key),i=0;
	while(HT[(index+(i*i)) % SIZE]!=0){
		i++;
	}
	return (index+(i*i))%SIZE;
}
void insert(vector<int> &HT,int key){
	int index=Hash(key);
	if(HT[index]!=0){
		index=QuadraticProbing(HT,key);
	}
	HT[index]=key;
	
}
void search(vector<int> &HT,int key){
	int index=Hash(key),flag=0,i=0;
	while(i<SIZE){
		if(HT[index+(i*i)]==key){
			flag=1;
			break;
		}
		i++;
	}
	if(flag==1){
		cout<<"ELEMENT FOUND AT INDEX "<<(index+(i*i))%SIZE<<endl;
	}
	else{
		cout<<"ELEMENT NOT FOUND"<<endl;
	}	
}
int main(){
	vector<int> HT(SIZE,0);
	insert(HT,20);
	insert(HT,40);
	insert(HT,10);
	insert(HT,30);
	for(int i=0;i<HT.size();i++){
		cout<<HT[i]<<" ";
	}
	cout<<endl;
	search(HT,30);
	search(HT,4);
	
}
