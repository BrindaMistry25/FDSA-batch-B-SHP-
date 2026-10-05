#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void DFS(int start, vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(start);

    cout << "DFS: ";

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (visited[current])
            continue;

        visited[current] = true;
        cout << current << " ";

        // Add adjacent buildings
        for (int i = n - 1; i >= 0; i--) {
            if (graph[current][i] && !visited[i]) {
                s.push(i);
            }
        }
    }

    cout << endl;
}
void BFS(int start, vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;
}

int main() {
    int n, edges;

    cout << "Enter number of buildings: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter number of roads: ";
    cin >> edges;

    cout << "Enter roads (building1 building2):\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    cout << "Enter starting building: ";
    cin >> start;

    DFS(start, graph, n);
    BFS(start, graph, n);

    return 0;
}