#include<iostream>
#include<vector>
#define SIZE 10
using namespace std;
int Hash(int key){
	return key%SIZE;
}
int LinearProbing(vector<int> &HT,int key){
	int index=Hash(key),i=0;
	while(HT[(index+i)%SIZE]!=0){
		i++;
	}
	return (index+i)%SIZE;
}
void insert(vector<int> &HT,int key){
	int index=Hash(key);
	if(HT[index]!=0){
		index=LinearProbing(HT,key);
	}
	HT[index]=key;
	
}
void search(vector<int> &HT,int key){
	int index=Hash(key),flag=0,i;
	for(i=index;i<SIZE;i++){
		if(HT[i]==key){
			flag=1;
			break;
		}
	}
	if(flag==1){
		cout<<"ELEMENT FOUND AT INDEX "<<i<<endl;
	}
	else{
		cout<<"ELEMENT NOT FOUND"<<endl;
	}	
}
int main(){
	vector<int> HT(SIZE,0);
	insert(HT,23);
	insert(HT,3);
	insert(HT,1);
	for(int i=0;i<HT.size();i++){
		cout<<HT[i]<<" ";
	}
	cout<<endl;
	search(HT,3);
	search(HT,4);
	
}
