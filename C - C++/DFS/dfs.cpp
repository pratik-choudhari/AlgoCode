#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(ll startingVertex, unordered_map<ll, vector<ll>> graph, vector<bool> &visited, vector<ll> &dfsTraversal){
    visited[startingVertex] = true; // visiting a vertex so that not to repeat
    dfsTraversal.push_back(startingVertex);
    for(ll i = 0, n = graph[startingVertex].size(); i < n ; ++i){ // for all the neighbours of a vertex
        if(!visited[graph[startingVertex][i]]){
            // if not visited only then add
            dfs(graph[startingVertex][i], graph, visited, dfsTraversal);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m; // vertices and edges
    vector<bool> visited(n, false); // initializing visited array to be all false.
    vector<ll> dfsTraversal;
    ll u,v;
    unordered_map<ll, vector<ll>> graph;
    for(ll i = 0;  i < m; ++i){
        cin >> u >> v; // edge between u and v.
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll startingVertex;
    cin >> startingVertex; // starting vertex
    startingVertex--; 
    dfs(startingVertex, graph, visited, dfsTraversal);
    for(ll i = 0, n = dfsTraversal.size(); i < n - 1; ++i){ // iterating to n-1 so that we don't have to print extra ->
        cout << dfsTraversal[i] + 1 << "->"; // add 1 to the value so that output will be 1-indexed.
    }
    cout << dfsTraversal[dfsTraversal.size()-1] + 1 << endl; 
    return 0;
}