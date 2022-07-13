#include<iostream>
#include<vector>
#define I INT_MAX
using namespace std;
vector<vector<int>> edgeset(vector<vector<int>> A, int n, vector<vector<int>> edges){
	int k=0,count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i+1;j++){
		if(A[i][j]!=INT_MAX){
		count++;
		}	
		}
	}
	edges.resize(3,vector<int>(count));
	for(int i=0;i<n;i++){
		for(int j=0;j<i+1;j++){
		if(A[i][j]!=INT_MAX){
		edges[0][k]=i;
		edges[1][k]=j;
		edges[2][k]= A[i][j];
		k++;
		}	
		}
	}
	return edges;
}
                       
void Union(int u,int v, int S[]){
	if(S[u]<S[v]){
		S[u]=S[u]+S[v];
		S[v]=u;
	}
	else{
		S[v]=S[u]+S[v];
		S[u]=v;		
	}
}
int find(int u, int S[]){
	int x=u,v=0;
	while(S[x]>0){
		x=S[x];
	}
	
	while(u!=x){
		v=S[u];
		S[u]=x;
		u=v;
	}
	return x;
}
void kruskals(vector<vector<int>>A ,int n){
vector<vector<int>> edges; 
edges=edgeset(A,n,edges);
int i=0,u,v,k;
int set[n];
for(int x=0;x<n;x++){
	set[x]=-1;
}
vector<int> visited(edges[0].size(),0);
vector<vector<int>> MST(3,vector<int>(n-1));

while(i<n-1){
	int min = INT_MAX;
	//LOOP TO FIND MINIMUM COST EDGE IN EDGES WHICH IS NOT VISITED
	for(int j=0;j<edges[0].size();j++){
	if(visited[j] == 0 && edges[2][j]<min){
		min= edges[2][j];
		u =  edges[0][j];
		v =  edges[1][j];
		k=j;
	}
}
	//Check if the minimum edge forms a cycle or not
	// use the find function, if there parent are same then it forms a cycle
	if(find(u,set)!=find(v,set)){
	MST[0][i]=u;
	MST[1][i]=v;
	MST[2][i]=min;
	Union(find(u,set),find(v,set), set);//perform union on parent of u and v after including it in the mst	
	i++;
	}
	visited[k]=1;
	}


for(int i=0;i<n-1;i++){
	cout<<"EDGE : "<<MST[0][i]<<" "<<MST[1][i]<<" | WEIGHT : "<<MST[2][i]<<endl;
}
	
}
int main(){
	int n,i,j,w;
	vector <vector<int>> B;
	cout<<"ENTER NUMBER OF VERTICES : ";
	cin>>n;
	B= vector<vector<int>>(n,vector<int>(n,I));
	int maxEdges = (n*(n-1))/2;
	cout<<"ADD EDGES |Format: 3 1 (Enter -1 & -1 in both vertices to end adding edges)\n";
	for(int e=0; e<maxEdges;e++){
		cout<<"ENTER START AND END  POINT OF EDGE "<<e+1<<" : ";
		cin>>i>>j;
		if(i<0 || j<0 || i>n-1 || j> n-1){
			break;
		}
		else{
		cout<<"ENTER WEIGHT OF THE EDGE "<<i<<" "<<j<<" : ";
		cin>>w;
			B[i][j]=w;
			B[j][i]=w;
		}
	}

	
	kruskals(B,B[0].size());
	
}
