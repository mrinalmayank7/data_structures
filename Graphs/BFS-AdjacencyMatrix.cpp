#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//requirement:
//queue: to store the current vertex for vising all adjacent vertices
//visited array for storing visited vertices
//empty queue signifies BFS is complete

void BFS(vector<vector<int>> A, int v){
	queue<int> q;
	int u,n=A[v].size();
	vector<int> visited;
	visited.resize(n);
	cout<<v<<" "; 
	//cout<<"VISIT START : "<<v<< "\n";
	visited[v]=1;
	q.push(v);	
	while(!q.empty()){
		u=q.front();
		q.pop();
		//cout<<"CURRENT VERTEX TO EXPLORE : "<<u<< "\n";
		for(int i=0;i<n;i++){
			if(A[u][i]==1 && visited[i]==0){ //u is current vertex and i s for iterating through all adjancent vertex of u
				//cout<<"VISIT "<<i<<" ";
				cout<<i<<" ";
	            visited[i]=1;
	            q.push(i);				
			}
		}
	}
		
}


int main(){
	cout<<"SAMPLE BFS TRAVERSAL DEFINED IN MAIN\n";
	vector<vector<int>> A;
    A = {{0,1,1,0,0},
         {1,0,1,0,1},
         {1,1,0,1,0},
         {0,0,1,0,1},
         {0,1,0,1,0}};	
    BFS(A,0);
    
    cout<<endl;
    cout<<"BFS : GRAPH INPUT FROM THE USER\n";
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
	
	cout<<"ENTER THE START VERTEX FOR TRAVERSAL : ";
	cin>>v;
	BFS(B,0);   
}
