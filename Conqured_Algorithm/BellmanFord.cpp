#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

constexpr long long INF = 60000000000;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
}

int main() {
    init();

    // N, M 선언 후 입력받기
    int N, M;
    cin >> N >> M;

    // 간선 튜플 선언 후 입력받은 값 입력
    vector<tuple<int, int, int>> edges;
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }
    // distance 배열 만들기. INF으로 초기화.
    vector<long long> dist(N+1, INF);
    
    // 처음 시작 위치 dist는 0
    dist[1] = 0;

    // edges를 받아서 거리가 더 작아지면 갱신 (N-1번)
    for(int i=1; i<N; i++) {
        for(const auto& edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;
            if(dist[u]!=INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;   
            }
        }
    }
    // 추가로 순환을 돌려서 음수 싸이클이 있는지 확인
    bool is_minus_cycle = false;
    for(const auto& edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        if(dist[u]!=INF && dist[u] + w < dist[v]) {
            is_minus_cycle = true;
            break;
        }
    }
    // 마지막으로 출력!!!
    if(is_minus_cycle) cout << -1;
    else for(int i=2; i<N+1; i++) {
        if(dist[i]==INF) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}