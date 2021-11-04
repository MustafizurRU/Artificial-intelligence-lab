#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1003];
int dist[1003],parent[1003];
#define INF 1000000000
void dfs(int source)
{
    for(int i=0;i<graph[source].size();i++)
    {
        int v=graph[source][i];
        if((dist[source]+1)<dist[v])
        {
            dist[v]=dist[source]+1;
            dfs(v);
            parent[v]=source;
        }
    }
}

void path(int node)
{
    if(parent[node]==node)
    {
        printf("%d ",node);
        return ;
    }
    path(parent[node]);
    printf("%d ",node);
}

int main()
{
    int n,a,b;
    printf("Enter Number of vertex: ");
    scanf("%d",&n);
    printf("Edges: Input will be terminated by 0 0.\n");
    while(1)
    {
        scanf("%d %d",&a,&b);
        if(a==0&&b==0)
            break;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    printf("Print Adjacent List\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d: ",i);
        for(int j=0;j<graph[i].size();j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    printf("Enter source and destination: Input will be terminated by 0 0.\n");
    int source,destination;
    while(1)
    {
        scanf("%d %d",&source,&destination);
        if(source==0&&destination==0)
            break;
        for(int i=0;i<1003;i++)
        {
            dist[i]=INF;
            parent[i]=i;
        }
        dist[source]=0;
        dfs(source);
        printf("The distance from %d to %d is: ",source,destination);
        printf("%d\n",dist[destination]);
        printf("A shortest path from %d to %d is: ",source,destination);
        path(destination);
        printf("\n");
    }
}

