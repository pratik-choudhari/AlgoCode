#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void bfs(ll startingVertex, unordered_map<ll, vector<ll>> graph, vector<bool> &visited, vector<ll> &bfsTraversal){
    queue<ll> bfs;
    bfs.push(startingVertex);
    while(!bfs.empty()){
        ll frontVertex = bfs.front();
        bfsTraversal.push_back(frontVertex);
        bfs.pop();
        visited[frontVertex] = true;
        for(ll i = 0, n = graph[frontVertex].size(); i < n; ++i){
            if(!visited[graph[frontVertex][i]])
            bfs.push(graph[frontVertex][i]);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    ll u, v;
    vector<bool> visited(n, false);
    vector<ll> bfsTraversal;
    unordered_map<ll, vector<ll>> graph;
    for(ll i = 0; i < m; ++i){
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll startingVertex;
    cin >> startingVertex;
    startingVertex--;
    bfs(startingVertex, graph, visited, bfsTraversal);
    for(ll i = 0, n = bfsTraversal.size(); i < n - 1;++i){
        cout << bfsTraversal[i] + 1 << "->";
    }
    cout << bfsTraversal[bfsTraversal.size()-1] + 1 << endl;
    return 0;
}