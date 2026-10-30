#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
int n, m;
cout << "Enter number of locations: ";
cin >> n;

vector<vector<pair<int, int>>> graph(n);  

cout << "Enter number of roads: ";  
cin >> m;  

cout << "Enter roads (source destination cost):\n";  
for (int i = 0; i < m; i++) {  
    int u, v, w;  
    cin >> u >> v >> w;  

    graph[u].push_back({v, w});  
    graph[v].push_back({u, w});  
}  

int source;  
cout << "Enter warehouse location: ";  
cin >> source;  

vector<int> dist(n, INT_MAX);  
vector<int> parent(n, -1);  

priority_queue<pair<int, int>,  
    vector<pair<int, int>>,  
    greater<pair<int, int>>> pq;  

dist[source] = 0;  
pq.push({0, source});  

while (!pq.empty()) {  
    int d = pq.top().first;  
    int u = pq.top().second;  
    pq.pop();  

    if (d != dist[u])  
        continue;  

    for (auto edge : graph[u]) {  
        int v = edge.first;  
        int cost = edge.second;  

        if (dist[u] + cost < dist[v]) {  
            dist[v] = dist[u] + cost;  
            parent[v] = u;  
            pq.push({dist[v], v});  
        }  
    }  
}  

cout << "\nMinimum cost from warehouse:\n";  
for (int i = 0; i < n; i++) {  
    cout << "Location " << i << ": ";  
    if (dist[i] == INT_MAX)  
        cout << "Unreachable\n";  
    else  
        cout << dist[i] << "\n";  
}  

int dest;  
cout << "\nEnter delivery location to show route: ";  
cin >> dest;  

if (dest < 0 || dest >= n || dist[dest] == INT_MAX) {  
    cout << "Invalid or unreachable destination.\n";  
} else {  
    vector<int> path;  

    for (int v = dest; v != -1; v = parent[v])  
        path.push_back(v);  

    reverse(path.begin(), path.end());  

    cout << "Route: ";  
    for (int i = 0; i < (int)path.size(); i++) {  
        cout << path[i];  
        if (i < (int)path.size() - 1)  
            cout << " -> ";  
    }  

    cout << "\nMinimum travel cost: " << dist[dest] << "\n";  
}  

return 0;

}
Explain code in simple language
