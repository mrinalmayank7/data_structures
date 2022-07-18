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

void radixsort(vector<int> &A){
	int max=*max_element(A.begin(),A.end());
	int m=to_string(max).length(),division_constant=1;
	struct Node *H[10];
	for	(int i =0; i<10;i++){
	H[i]=NULL;
    }
for(int digit=0;digit<m;digit++){

    for(int i=0;i<A.size();i++){
    	int place=(A[i]/division_constant)%10;
	    insert(H,A[i],place);
    }
    
    struct Node *p,*todelete=NULL;
    int k=0;
	for(int j=0;j<10;j++){
		p=H[j];
		while(p!=NULL){
		A[k++]=p->data;
	   	todelete=p;
	    H[j]=H[j]->next;
	    p=p->next;
	    delete(todelete);	
	}
}
    
	division_constant=division_constant*10;	
	
	}

}
int main(){
	vector<int> A={56,456,345,123,108,199,156,178,234,234};
	radixsort(A);
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
}
