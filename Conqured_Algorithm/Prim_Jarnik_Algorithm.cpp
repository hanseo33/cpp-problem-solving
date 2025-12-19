#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9; // 무한대를 나타내는 큰 값

// (가중치, 도착 노드) 쌍을 저장하는 구조체
// priority_queue가 min-heap으로 동작하도록 비교 연산자 정의
struct Edge {
    int weight;
    int to;

    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    // 인접 리스트로 그래프 표현
    vector<vector<Edge>> adj(V + 1);
    for (int i = 0; i < E; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].emplace_back(Edge{weight, to});
        adj[to].emplace_back(Edge{weight, from}); // 양방향 그래프
    }

    // 최소 힙(priority_queue)
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    // 방문 여부를 체크하는 배열
    vector<bool> visited(V + 1, false);

    long long total_weight = 0;
    int edge_count = 0;

    // 1번 노드부터 시작
    visited[1] = true;
    for (const auto& edge : adj[1]) {
        pq.push(edge);
    }

    // MST에 V-1개의 간선이 포함될 때까지 반복
    while (!pq.empty() && edge_count < V - 1) {
        Edge current_edge = pq.top();
        pq.pop();

        int weight = current_edge.weight;
        int to = current_edge.to;

        // 이미 방문한 노드라면 건너뛰기 (사이클 방지)
        if (visited[to]) {
            continue;
        }

        // MST에 간선 추가
        visited[to] = true;
        total_weight += weight;
        edge_count++;

        // 새로 추가된 노드와 연결된 간선들을 큐에 추가
        for (const auto& edge : adj[to]) {
            if (!visited[edge.to]) {
                pq.push(edge);
            }
        }
    }

    cout << total_weight << endl;

    return 0;
}
