#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
}*head;

int Hash(int key){
	return key%10;
}

void insert(struct Node *H[],int key ){
	int index = Hash(key); //GET INDEX TO INSERT KEY
	struct Node *temp, *q=NULL,*p=H[index]; // H[INDEX] IS THE POINTER TO THE LIST INDEX
	temp=new Node;
	temp->data=key;
	temp->next=NULL;
	
	if( H[index] == NULL){ //IF THE INDEX IS EMPTY OR NULL THEN INSERT AT FIRST PLACE
		H[index]=temp;
	}
	else{
		while(p!=NULL && p->data<key){
		q=p;//GET PREVIOUS ELEMENT
		p=p->next; 	
		}
		if(p==H[index]){ // IF TO INSERT AT FIRST PLACE BEFORE ONE GREATER ELEMENT
			temp->next=p;
			H[index]=temp;
		}
		else{
			temp->next=p; // INSERT BETWEEN Q & P
			q->next=temp;
		}	
	}
	
}

void search(struct Node *H[],int key){
	int index=Hash(key),flag=0;
	struct Node *p=H[index];
	while(p!=NULL){
		if(key == p->data){
			cout<<p->data<<" FOUND AT INDEX "<<index<<endl;
			flag=1;
			break;
		}
		p=p->next;
	}
	if(flag==0){
		cout<<key<<" NOT FOUND"<<endl;
	}
}

void Delete(struct Node *H[],int key){
int index=Hash(key),flag=0;
struct Node *p=H[index],*q=NULL,*todelete=NULL;
	while(p!=NULL){
		
		if(key == p->data){	
			flag=1;	
			break;
		}
		q=p;	
		p=p->next;
	}
	if(flag==1){
		if(p==H[index]){
		todelete=p;
		H[index]=p->next;
		delete(todelete);
			
		}
		else{
			todelete=p;
			q->next=p->next;
			delete(todelete);
		}
		
	}
	
}

int main(){
	struct Node *H[10], *p;
	for	(int i =0; i<10;i++){
	H[i]=NULL;
}
	insert(H,11);
	insert(H,21);
	insert(H,31);
	insert(H,25);
	insert(H,27);
	insert(H,35);
	insert(H,1);
	insert(H,34);
	insert(H,14);
	Delete(H,1);
	Delete(H,21);
	Delete(H,31);	
	for(int i=0;i<10;i++){
		p=H[i];
		cout<<"INDEX "<<i<<" : ";
		if(H[i]==NULL){
			cout<<"-";
		}
		while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;	
		}
		cout<<endl;
	}
	cout<<endl;
	search(H,11);
	search(H,31);
	search(H,41);
	
		
}
