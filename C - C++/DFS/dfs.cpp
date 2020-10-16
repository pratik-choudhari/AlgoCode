#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(ll startingVertex, unordered_map<ll, vector<ll>> graph, vector<bool> &visited, vector<ll> &dfsTraversal){
    visited[startingVertex] = true;
    dfsTraversal.push_back(startingVertex);
    for(ll i = 0, n = graph[startingVertex].size(); i < n ; ++i){
        if(!visited[graph[startingVertex][i]]){
            dfs(graph[startingVertex][i], graph, visited, dfsTraversal);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<bool> visited(n, false);
    vector<ll> dfsTraversal;
    ll u,v;
    unordered_map<ll, vector<ll>> graph;
    for(ll i = 0;  i < m; ++i){
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll startingVertex;
    cin >> startingVertex;
    startingVertex--;
    dfs(startingVertex, graph, visited, dfsTraversal);
    for(ll i = 0, n = dfsTraversal.size(); i < n - 1; ++i){
        cout << dfsTraversal[i] + 1 << "->";
    }
    cout << dfsTraversal[dfsTraversal.size()-1] + 1 << endl;
    return 0;
}