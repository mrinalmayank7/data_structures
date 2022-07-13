#include<iostream>
#include<vector>
#define I INT_MAX
using namespace std;

void prims(vector<vector<int>> A,int n){
int min = INT_MAX;
int u,v,k;
static vector<vector<int>> B(2,vector<int>(n-1)); // store MST edges (2 rows for storing end point of edges)
vector<int> temp(n,I);//store all edges near to selected edge vertices

//Loop to find first minimum edge  & store end points in u and v. 
for(int i =0;i<n;i++){
	for(int j=0;j<n;j++){
		if(A[i][j]<min ){
			min= A[i][j];
			u=i;
		    v=j;
		}
	}
}
B[0][0]=u; // store minimum edge end point1 in first col of vector. 
B[1][0]=v; // store minimum edge end point in first col of vector.
temp[u]=temp[v]=0;  // initialize already visited vertex as 0 in temp
//now traverse through all other vertices & find which edge has lowest value from u or v
//since 0 represents non connected edge, so must not comapre with 0
for(int i=0;i<n;i++){
	if(temp[i]!=0){
	if(A[i][u]<A[i][v]){
		temp[i]=u;
	}
	else{
		temp[i]=v;
	}
	}	
}

//now in temp compare all edges where start vertex is index and end vertex is element, and find edge with minimum cost
//include that edge in MST vector B and repeat the process 
//start repeating for loop from index i=1 as i=0 stores the first edge
for(int i=1;i<n-1;i++){ //since B size is n-1
	//compare temp edges
	min =INT_MAX;
	for(int j=0;j<n;j++){
		if(temp[j]!=0 && A[j][temp[j]]<min){
			k=j;//store start index in k to modify temp later
			min=A[j][temp[j]];		
		}
	}
	B[0][i]=k;
	B[1][i]=temp[k];
	temp[k]=0;// set temp[k] as 0 to signify already visited vertex
	
	//Now run a loop to check other vertex is nearer to k or not
	for(int j=0;j<n;j++){
		if(temp[j]!=0 && A[j][k]<A[j][temp[j]]){
			temp[j]=k;
		}
	}
}

int min_cost=0;
cout<<"MINIMUM SPANNING TREE EDGES (IN ORDER) :"<<endl;
for(int i=0;i<n-1;i++){
cout<<"EDGE : "<<B[0][i]<<" "<<B[1][i]<<" | "<<"WEIGHT :"<<A[B[0][i]][B[1][i]]<<endl;
min_cost=min_cost +(A[B[0][i]][B[1][i]]);	
}
cout<<"MINIMUM COST OF ALL EDGES :"<<min_cost;

	
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

	
	prims(B,B[0].size());
	
}
