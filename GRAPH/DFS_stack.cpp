#include<iostream>
using namespace std;
int cost[10][10],i,j,k,n,stack[10],top,v,visit[10],visited[10];
int main()
{
    int m;
    cout <<"ENTER NUMBER OF NODES:";
    cin >> n;
    cout <<"ENTER NUMBER OF EDGES:";
    cin >> m;
    cout <<"ADD EDGES "<<endl;
    for(k=1; k<=m; k++)
    {
        cin >>i>>j;
        cost[i][j]=1;
    }
    cout <<"ENTER THE VERTEX FROM WHICH YOU WANT TO START DFS TRAVERSAL:";
    cin >>v;
    cout <<"ORDER OF VISITED VERTICES IS :";
    cout << v <<" ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=n; j>=1; j--)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                stack[top]=j;
                top++;
            }
        v=stack[--top];
        cout<<v << " ";
        k++;
        visit[v]=0;
        visited[v]=1;
    }
    return 0;
}
