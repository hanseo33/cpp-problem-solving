#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // 경로가 없는 경우를 나타내는 무한대 값

struct Edge {
    int to;
    int weight;

    // 우선순위 큐에서 가중치를 기준으로 비교하기 위한 연산자 오버로딩
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

void dijkstra(int start, int v_count, const vector<vector<Edge>>& graph, vector<int>& dist) {
    // 시작점부터의 최단 거리를 저장할 배열 초기화
    dist.assign(v_count + 1, INF);
    dist[start] = 0;

    // 우선순위 큐 선언 (가중치가 낮은 순으로 정렬)
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    // 시작 노드를 우선순위 큐에 추가
    pq.push({start, 0});

    while (!pq.empty()) {
        // 현재 가장 거리가 짧은 노드 정보를 가져옴
        Edge current = pq.top();
        pq.pop();

        int u = current.to;
        int current_dist = current.weight;

        // 이미 처리된 노드라면 (더 짧은 경로를 이미 찾았다면) 무시
        if (current_dist > dist[u]) {
            continue;
        }

        // 현재 노드와 연결된 다른 노드들을 확인
        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // 현재 노드를 거쳐 가는 것이 더 빠르다면 거리 갱신
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({v, dist[v]});
            }
        }
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E; // 정점의 개수, 간선의 개수
    cin >> V >> E;

    int K; // 시작 정점
    cin >> K;

    // 그래프를 인접 리스트 형태로 표현
    vector<vector<Edge>> graph(V + 1);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> dist; // 최단 거리를 저장할 벡터
    dijkstra(K, V, graph, dist);

    // 결과 출력
    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}