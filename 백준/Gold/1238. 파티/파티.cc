#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
typedef pair<int, int> ci;
const int INF = numeric_limits<int>::max(); // 무한대 값

vector<int> dijkstra(int start, int v, vector<vector<ci>>& graph) {
    vector<int> dist(v + 1, INF);
    priority_queue<ci, vector<ci>, greater<ci>> pq;

    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) {
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;
            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<ci>> graph(n + 1, vector<ci>());
    while (m--) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
    }

    vector<int> from = dijkstra(x, n, graph);
    vector<vector<ci>> reverse(n + 1, vector<ci>());
    
    
    for (int i = 1; i <= n; ++i) {
        for (auto edge : graph[i]) {
            reverse[edge.first].push_back({i, edge.second});
        }
    }
    vector<int> to = dijkstra(x, n, reverse);

    int max_time = 0;
    for (int i = 1; i <= n; ++i) {
        int total = from[i] + to[i];
        max_time = max(max_time, total);
    }

    cout << max_time << '\n';

    return 0;
}
