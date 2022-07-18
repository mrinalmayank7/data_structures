#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};
void insert(struct Node *H[],int key,int index){
	struct Node *temp, *q=NULL,*p=H[index]; // H[INDEX] IS THE POINTER TO THE LIST INDEX
	temp=new Node;
	temp->data=key;
	temp->next=NULL;
	if( H[index] == NULL){ //IF THE INDEX IS EMPTY OR NULL THEN INSERT AT FIRST PLACE
		H[index]=temp;
	}
	else{
		while(p!=NULL){
		q=p;
		p=p->next; 	
		}
		q->next=temp;	
	}
}


void bucketsort(vector<int> &A){
	int max=*max_element(A.begin(),A.end()),k=0;
	int sizeBucket=max+1;
	struct Node *H[sizeBucket];
	for	(int i =0; i<sizeBucket;i++){
	H[i]=NULL;
}
for(int i=0;i<A.size();i++){
	insert(H,A[i],A[i]);
}
struct Node *p;
	for(int i=0;i<sizeBucket;i++){
		p=H[i];
		while(p!=NULL){
		A[k++]=p->data;
		struct Node *todelete=NULL;
	   	todelete=p;
	    H[i]=H[i]->next;
	    p=p->next;
	    delete(todelete);	
	}
}
}
int main(){
	vector<int> A={12,12,12,11,1,1,4,4,4,3,3,12,11,5,5,5,8,8,7,9,2,2};
	bucketsort(A);
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
}
