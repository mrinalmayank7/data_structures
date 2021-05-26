#include<iostream>
using namespace std;
int queue[5], MAX = 5,front = - 1 ,rear = - 1;

void enqueue() {
   int val;
   if (rear == MAX - 1)
   cout<<"OVERFLOW"<<endl;
   else {
      if (front == - 1)
      front = 0;
      cout<<"ENQUEUE ELEMENT IN THE QUEUE: ";
      cin>>val;
      rear++;
      queue[rear] = val;
   }}
   
void dequeue() {
   if (front == - 1 || front > rear) {
      cout<<"UNDERFLOW"<<endl;
      return ;
   } else {
      cout<<"DELETED ELEMENT IS  : "<< queue[front] <<endl;
      front++;
   }}
   
void Display(){
   if (front == - 1)
   cout<<"EMPTY!"<<endl;
   else {
      cout<<"ELEMENTS OF QUEUE ARE  : ";
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }}
   
void reverse(){
	int i,j,temp;
	for(i=front,j=rear;i<j;i++,j--){
		temp = queue[i];
		queue[i] = queue[j];
		queue[j] = temp;
	  }
	  Display();
}


int Binarysearch(int element){
int low = front;
int high = rear;
int mid = (low+high)/2;
while (low <= high){
	 if (queue[mid]==element){
	cout<<element<<" found at position "<<mid<<endl;
	break;
	}
	else if (queue[mid]<element){
		low=mid+1;
	}
	else{
		high=mid-1;		
	}
	mid=(low+high)/2;	
}
if(low > high)
cout<<"element not found"<<endl;

}
void InsSort()
{
int tmp,j,i;
for (int i=front ; i<=rear;i++){
	tmp=queue[i];
	j=i-1;
	while(tmp<queue[j])
	{
		queue[j+1]=queue[j];
		j--;
	}
queue[j+1]=tmp;		
	}
	cout<<"The sorted queue is:"<<endl;
     for(i = front; i<=rear; i++) {
      cout<<"["<<i<<"]"<<"="<<queue[i]<<endl;
   }
}

int main() 
{
   int ch,element,found,i;
   cout<<"1) ENQUEUE"<<endl;
   cout<<"2) DEQUEUE"<<endl;
   cout<<"3) DISPLAY"<<endl;
   cout<<"4) DISPLAY IN REVERSE ORDER"<<endl;
   cout<<"5) LINEAR SEARCH"<<endl;
   cout<<"6) BINARY SEARCH"<<endl;
   cout<<"7) INSERTION SORT"<<endl;
   cout<<"8) Exit"<<endl;
   do {
      cout<<"Enter your choice : ";
      cin>>ch;
      switch (ch) {
         case 1: enqueue();
         break;
         case 2: dequeue();
         break;
         case 3: Display();
         break;
         case 4: reverse();
         break;
         case 5 : 
		 cout<<"enter the queue element to search:";
         cin>>element;
         for ( i = front; i < rear; i++) {
         if (queue[i] == element ) {
         found=1; 
         break;
     }  
}
if (found==1) 
cout<<element <<" found at index "<<i<<endl;
else
cout<<"OOP's element not found!"<<endl;
		 ;
		 break;
		 case 6 : 
		 cout<<"enter the  element in the queue  to search :";
         cin>>element;
		 Binarysearch(element);
		 break;
		 case 7: 
		 InsSort();
         break;
         case 8: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=8);
   return 0;
}

