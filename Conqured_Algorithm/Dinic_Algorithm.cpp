#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 500;
const int MAX_V = MAX_N + 2;
const int S = MAX_V - 2;
const int E = MAX_V - 1;
const int INF = 1000000000;

int N;
int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int level[MAX_V];
int work[MAX_V];
vector<int> adj[MAX_V];

// 디닉 전용 BFS 함수
bool BFS() {
    // 레벨값 초기화
    fill(level, level + MAX_V, -1);
    level[S] = 0;

    queue<int> q;
    q.push(S); 
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        // u에서 v로 갈 때에, level이 정해지지않았고 간선에 residual이 남아있는 경우에만 이동
        for(int v : adj[u]) {
            if((level[v] == -1) && (capacity[u][v] - flow[u][v] > 0)) {
                level[v] = level[u] + 1;
                q.emplace(v);
            }
        }
    }
    // sink에 도착 가능하면 true, 아니면 false를 return
    return level[E] != -1;
}

// 디닉 전용 DFS 함수 : u에서 v로 최대 flow만큼 유량 보낼 것
int DFS(int u, int dest, int f) { // f는 최종적으로 추가할 유량을 뜻함.
    // base case : dest에 도달함
    if(u == dest) return f;

    // 현재 정점에서 인접한 정점들을 탐색
    // 이때, 이번 단계에서 이미 쓸모없다고 판단한 간선은 다시 볼 필요가 없으므로
    // work 배열로 간선 인덱스를 저장해 둠
    for(int &i = work[u]; i < adj[u].size(); i++) {
        int v = adj[u][i];
        // v의 level이 u의 level +1이고, 간선에 residual(잔여유량)이 있어야만 이동
        if((level[v] == level[u] + 1) && (capacity[u][v] - flow[u][v] > 0)) {
            // df : DFS함수를 여러번 실행하면서 찾은 경로 중 가장 작은 residual을 저장
            int df = DFS(v, dest, min((capacity[u][v] - flow[u][v]), f));
            // Augumenting Path가 없다면, 유량을 df만큼 흘리고 DFS함수 종료
            if(df > 0) {
                flow[u][v] += df;
                flow[v][u] -= df;
                return df; // u -> dest의 경로를 찾고 각 간선마다 df를 추가했으면 바로 DFS함수 종료.
            }
        }
    }
    // Augumenting Path가 없다면 : 유량 0 흘림
    return 0;
}

int main() {
    // 그래프 정보 입력받기
    cin >> N;
    // 사람들의 진영선호 입력받기
    for(int i = 0; i < N; i++) {
        int team;
        cin >> team;
        if(team == 1) {
            capacity[S][i] = INF;
            adj[S].emplace_back(i);
            adj[i].emplace_back(S);
        }
        else if(team == 2) {
            capacity[i][E] = INF;
            adj[i].emplace_back(E);
            adj[E].emplace_back(i);
        }
    }
    // 사람들의 "슬픔" 입력받기. 어흐흑ㅠㅠ
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> capacity[i][j];
            if(i != j) adj[i].emplace_back(j);
        }
    }

    // Dinic Algorithm 수행
    int total = 0;
    // level 그래프를 만들어, 싱크에 도착가능한 동안 반복
    while(BFS()) {
        fill(work, work + MAX_V, 0);
        // Augumentin Path 구하기
        while(1) {
            int f = DFS(S, E, INF);
            if(f == 0) break;
            total += f;
        }
    }
    cout << total << '\n';

    // 각 진영에 속한 사람들을 판단히기 위해 S에서의 도달가능성 판별
    bool visited[MAX_V] = {false, };
    visited[S] = true;
    queue<int> q;
    q.emplace(S);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            // 여유 용량이 있는 남아있는 간선만을 이용
            if(!visited[v] && (capacity[u][v] - flow[u][v] > 0)) {
                visited[v] = true;
                q.emplace(v);
            }
        }
    }

    // A진영에 속한 사람들 : S에서 도달 가능
    for(int i = 0; i < N; i++) {
        if(visited[i]) cout << i + 1 << " ";
    } cout << '\n';
    // B진영에 속한 사람들 : S에서 도달 불가능
    for(int i = 0; i < N; i++) {
        if(!visited[i]) cout << i + 1 << " ";
    } cout << '\n';
    
	return 0;
}
/*
	### Dinic Algorithm

	먼저 BFS로 level을 찾고, DFS로 Augmenting Path를 찾는다.

	내가 알고 있던 BFS, DFS 코드랑은 좀 달랐다. Dinic Algorithm 전용이라서 리턴하는 거라 던가 형태가 좀 다르다. 사실상 방법이 BFS, DFS와 일치하는 것 같다. 심지어 DFS 함수는 stack을 사용하지도 않았다.

	[] augmenting path가 항상 최단거리?

	DFS에서 int &i = work[curr]은 함수 특성상 curr == dest가 될 때까지 계속 재귀함수를 호출하는 데, 그 때마다 동일하게 이미 시도해본 간선은 skip해야하기 때문에 전역변수로 사용하는 것이다. 각 정점에 대해서 어느 간선까지 시도해보았는 지를 기록하는 것이다. 
	단순히 work[curr]++;하면 되는 이유는 어처피 간선은 한 번 저장 해놓으면 그 자리 그대로 있을 것이기 때문에 단순히 += 1 하는 것만으로 알아서 간선이 구분된다. 이 저장하는 행위를 모든 정점, V번 해야하기 때문에 work[MAX_V]로 선언하는 것이다.
	그런다음 BFS로 새로운 level그래프를 그렸을 때에는 work배열을 0으로 초기화해주어야 한다.
*/