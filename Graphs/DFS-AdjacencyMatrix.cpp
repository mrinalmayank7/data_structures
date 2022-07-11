#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void DFS(vector<vector<int>> A, int v,int n){
	
	static vector<int> visited(n, 0);// static is mandatory because in DFS recursion if static is not there visited will be remodified
	if(visited[v]==0){
	cout<<v<<" "; 
	visited[v]=1;	
	}
	for(int i=0;i<n;i++){
		if(A[v][i]==1 && visited[i]==0){
		DFS(A,i,n);	
		}	
	}		
}


int main(){

	cout<<"SAMPLE DFS TRAVERSAL DEFINED IN MAIN\n";
	/*vector<vector<int>> A;	
    A = {{0,1,1,0,0},
         {1,0,1,0,1},
         {1,1,0,1,0},
         {0,0,1,0,1},
         {0,1,0,1,0}};	
    DFS(A,0,A[0].size());*/
    
    cout<<endl;
    cout<<"DFS : GRAPH INPUT FROM THE USER\n";
    int n,i,j,v;
    vector<vector<int>>B;
    
    cout<<"ENTER NUMBER OF VERTICES : ";
    cin>>n;
    B= vector<vector<int>>(n,vector<int>(n,0));
    int maxEdges = (n*(n-1))/2;
    
    cout<<"ADD EDGES |Format: 3 1 (Enter -1 & -1 in both vertices to end adding edges)\n";
    
    for(int e=0;e<maxEdges;e++){
    cout<<"ENTER START AND END  POINT OF EDGE "<<e+1<<" : ";
	cin>>i>>j;
	if(i<0 || j<0 || i>n-1 || j>n-1){
		break;
	}
	else{
	B[i][j] = 1;
    B[j][i] = 1;
	}		
	}
	
	for(int p=0;p<n;p++){
		for(int q=0;q<n;q++){
			cout<<B[p][q]<<" ";
		}
		cout<<endl;
	}
	cout<<"ENTER THE START VERTEX FOR TRAVERSAL : ";
	cin>>v; 
	
	DFS(B,v,B[v].size());
}
