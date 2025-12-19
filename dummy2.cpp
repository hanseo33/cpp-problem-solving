#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX 100
#define INF 1000000000

using namespace std;

int capacity[MAX][MAX];
int flow[MAX][MAX];
int visited[MAX];
int result;

vector<int> adj[MAX];

void maxFlow(int source, int sink) {

    while(true) {
        memset(visited, -1, sizeof(visited));

        queue<int> q;
        q.emplace(source);

        // source부터 시작하는 경로찾기
        while(!q.empty()) {
            int start = q.front();
            q.pop();

            for(int i=0; i<adj[start].size(); i++) {
                int end = adj[start][i];

                if(capacity[start][end] - flow[start][end] > 0 && visited[end] == -1 ) {
                    // 왔으면 왔다고 표시
                    visited[end] = start;
                    // 큐에 넣기
                    q.emplace(end);
                    // sink면 break
                    if(end==sink) break;
                }
            }
        }

        if(visited[sink]==-1) break;

        // 찾은 경로의 유량을 찾기 역순으로
        int f = INF;
        for(int i=sink; i!=source; i=visited[i]) {
            f = min(f, capacity[visited[i]][i] - flow[visited[i]][i]);
        }

        // 찾은 유량을 업데이트!
        for(int i=sink; i!=source; i=visited[i]) {
            flow[visited[i]][i] += f;
            flow[i][visited[i]] -= f;
        }

        result += f;
    }
}

int main() {
    int testcase;
    cin >> testcase;

    for(int i=0; i<testcase; i++) {
        char u, v;
        int cap;
        cin >> u >> v >> cap;
        adj[u-65].emplace_back(v-65);
        adj[v-65].emplace_back(u-65);
        capacity[u-65][v-65] += cap;
        capacity[v-65][u-65] += cap;
    }

    maxFlow(0, 25);

    cout << result << "\n";
}
/*
5
A B 3
B C 3
C D 5
D Z 4
B Z 6*/