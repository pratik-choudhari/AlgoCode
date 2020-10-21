/*
Dijkstra's algorithm in C++ using adjacency lists and priority queue
*/
#include <bits/stdc++.h>
#define INF INT_MAX
#define S second
#define F first

using namespace std;

vector<vector< pair<int, int> > > g; //graph
vector<int> dist, par; //distance and parent

void dijk(int p)
{
    priority_queue<pair<int, int> > q;
    dist[p]=0;
    par[p]=p; // parent of source is itself

    q.push({0,p});
    while(!q.empty())
    {
        int a = q.top().S, d = q.top().F;
        q.pop();
        
        if(-d != dist[a]){continue;} //checking is visited and assigned
 
        for(auto v: g[a]) //visit neighbours of a
        {
            int b=v.F, w=v.S;
            
            if(dist[a]+w < dist[b]) // if lesser distance possible
            {
                dist[b] = dist[a]+w; //update distance
                par[b] = a;
                q.push({-dist[b],b}); // push -ve distance as pq sorts by greater. 
            }
        }
    }
}

int main()
{
    int n,m,s;

    cin>>n>>m;
    g.resize(n+1);
    dist.resize(n+1,INF);
    par.resize(n+1);

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    cin>>s; //source vertex

    dijk(s);

    for(int i=1; i<n+1; i++)
    {
        cout<<"Distance of vertex "<<i<<" from source "<<s<<" : "<<dist[i]<<endl;
    }

    return 0;
}