#include<stdio.h> 
#include<stdlib.h> 
int a[30],b[30],c[30] , n,p,val,i,pos,item,j;
void insert(); 
void Delete(); 
void Findpos(); 
void create(); 
void display(); 

int main() 
{ 
int ch; 
do{ 
printf("\n\n .................M E N U ..................\n"); 
printf("1.Create\n2.Display\n3.Insert\n4.Delete\n5.Find Position\n6.Exit\n"); 
printf("____________________________________"); 
printf("\nENTER YOUR DESIRED CHOICE TO PERFORM OPERATION ON ARRAYS:"); 
scanf("%d",&ch); 
switch(ch) 
{ 
case 1:create(); 
       break; 
case 2:display(); 
       break; 
case 3:insert(); 
       break; 
case 4:Delete(); 
       break; 
case 5:Findpos(); 
       break; 
case 6:exit(0); 
       break;
default: 
       printf("\nOOP'S ! YOU HAD NOT ENTERED A VALID CHOICE \n"); 
       break; 
                } 
        }while(ch!=6); 
return 0; 
} 
void insert()      
{          
    printf("\nENTER THE POSITION TO INSERT ELEMENT :\t");          
    scanf("%d",&pos);          
    printf("\nENTER THE ARRAY ELEMENT TO INSERT :\t");          
    scanf("%d",&val);          
    for(i=n-1;i>=pos;i--) 
        { 
                a[i+1]=a[i]; 
        } 
        a[pos]=val; 
        n=n+1; 
}
void Delete() 
{ 
        printf("\nENTER THE POSITION OF THE ELEMENT YOU WANT TO DELETE :\t"); 
        scanf("%d",&pos); 
        val=a[pos]; 
        for(i=pos;i<n-1;i++) 
        { 
                a[i]=a[i+1]; 
        } 
        n=n-1; 
        printf("\nDELETED ELEMENT : %d",val); 
}
void Findpos()
{
printf("\nENTER THE ELEMENT TO FIND THE POSITION : ");
scanf("%d",&item);
  while( j < n){
      if( a[j] == item ){
      	 printf("\nELEMENT FOUND AT POSITION : %d",j);
	  }
 	j=j+1;
   } 
}
void create() 
{ 
        printf("\nENTER THE ARRAY SIZE:\t"); 
        scanf("%d",&n); 
        printf("\nENTER THE ARRAY ELEMENTS  :\n"); 
        for(i=0;i<n;i++) 
        { 
                scanf("%d",&a[i]); 
        } 
}
void display()  
{ 
        int i; 
        printf("\nHERE ARE THE ARRAY ELEMENTS :\n"); 
        for(i=0;i<n;i++){ 
                 printf("%d\t",a[i]);          
         } 
 } 

 
