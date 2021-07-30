#include<iostream>
using namespace std;
int matrix[10][10],i,j,k,totalNODES,queue[10],front,rear,v,visit[10],visited[10];
int main()
{
    int totalEDGES;
    cout <<"ENTER THE NUMBER OF VERTICES:";
    cin >> totalNODES;
    cout <<"ENTER THE NUMBER OF EDGES  :";
    cin >> totalEDGES;
    cout <<"ADD EDGES "<<endl;
    for(k=1; k<=totalEDGES; k++){
        cin >>i>>j;
        	matrix[i][j]=1;   //this is the repesentation in adjacency matrix 
    }
    cout <<"ENTER THE VERTEX YOU WANT TO START TRAVERSAL  :";
    cin >>v;
    cout <<"THE VISITED VERTICES AFTER BFS TRAVERSAL ARE :";
    cout <<v<<" ";
    visited[v]=1;
    k=1;
    while(k<totalNODES) {
        for(j=1; j<=totalNODES; j++)
            if(matrix[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                queue[rear++]=j;
            }
        v=queue[front++];
        cout<<v <<" ";
        k++;
        visit[v]=0;
        visited[v]=1;
    }
    return 0;
}
