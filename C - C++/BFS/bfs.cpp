#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void bfs(ll startingVertex, unordered_map<ll, vector<ll>> graph, vector<bool> &visited, vector<ll> &bfsTraversal){
    queue<ll> bfs; // bfs requires queue data structure
    bfs.push(startingVertex);  
    while(!bfs.empty()){
        ll frontVertex = bfs.front();
        bfsTraversal.push_back(frontVertex); // adding the vertex to the traversal array
        bfs.pop();
        visited[frontVertex] = true;
        for(ll i = 0, n = graph[frontVertex].size(); i < n; ++i){
            if(!visited[graph[frontVertex][i]])
            bfs.push(graph[frontVertex][i]); // adding the vertex only if the vertex is not visited
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m; // number of vertices and edges
    ll u, v;    
    vector<bool> visited(n, false);
    vector<ll> bfsTraversal;
    unordered_map<ll, vector<ll>> graph;
    for(ll i = 0; i < m; ++i){
        cin >> u >> v; // edge between u and v
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll startingVertex;
    cin >> startingVertex; // starting Vertex
    startingVertex--;
    bfs(startingVertex, graph, visited, bfsTraversal);
    for(ll i = 0, n = bfsTraversal.size(); i < n - 1;++i){ // iterating to n-1 to avoid printing extra ->
        cout << bfsTraversal[i] + 1 << "->"; // adding 1 to the value to get 1-index values
    }
    cout << bfsTraversal[bfsTraversal.size()-1] + 1 << endl;
    return 0;
}