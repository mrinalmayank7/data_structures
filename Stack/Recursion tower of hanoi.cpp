#include <iostream> 
using namespace std; 
  
void recursion(int n, char first, char end, char middle){  
if (n == 1)  
    {  
    cout << "Move disk 1 from rod " << first << " to rod " << end<<endl;  
    return;  
    }  
    recursion(n - 1, first, middle, end);  
    cout << "Move disk " << n << " from rod " << first << " to rod " << end << endl;  
    recursion(n - 1, middle, end, first);  
}  
   
int main()  
{  
cout<<endl<<" TESTING THE ALGORITHM WITH N = 5"<<endl<<endl;
    int n = 5; // Number of disks  
    recursion(n, 'A', 'C', 'B'); // A, B and C are names of rods  
    return 0;  
}  
