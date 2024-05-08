#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

void dfs(int s, map<int, vector<int>>& adj_list, vector<bool>& visited, vector<string>& arr) {
    visited[s] = true;
    cout << arr[s] << " ";
    for (int v : adj_list[s]) {
        if (!visited[v]) {
            dfs(v, adj_list, visited, arr);
        }
    }
}

void bfs(int s, map<int, vector<int>>& adj_list, vector<bool>& visited, vector<string>& arr) {
    queue<int> bfsq;
    bfsq.push(s);
    visited[s] = true;
    while (!bfsq.empty()) {
        int v = bfsq.front();
        bfsq.pop();
        cout << arr[v] << " ";
        for (int u : adj_list[v]) {
            if (!visited[u]) {
                visited[u] = true;
                bfsq.push(u);
            }
        }
    }
}

int main() {
    cout << "Enter no. of cities: ";
    int n, u;
    cin >> n;
    vector<string> cities(n + 1);
    for (int i = 1; i <= n; i++) {
        cout << "Enter city #" << i << ": ";
        cin >> cities[i];
    }

    map<int, vector<int>> adj_list;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int dist;
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << " (in KM): ";
            cin >> dist;
            adj_list[i].push_back(j);
            adj_list[j].push_back(i);
        }
    }

    cout << "Your cities are:" << endl;
    for (int i = 1; i <= n; i++)
        cout << "city #" << i << ": " << cities[i] << endl;

    cout << "Enter Starting Vertex: ";
    cin >> u;

    vector<bool> visited(n + 1, false);

    cout << "DFS: ";
    dfs(u, adj_list, visited, cities);
    cout << endl;

    fill(visited.begin(), visited.end(), false);

    cout << "BFS: ";
    bfs(u, adj_list, visited, cities);
    cout << endl;

    return 0;
}
