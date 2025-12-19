#include <iostream>
#include <queue>
#include <vector>
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

        while(!q.empty()) {
            int start = q.front();
            q.pop();

            for(int i=0; i<adj[start].size(); i++) {
                int end = adj[start][i];

                if(capacity[start][end] - flow[start][end] > 0
                && visited[end] == -1) {
                    visited[end] = start;
                    q.emplace(end);
                    
                    if(end==sink) break;
                }
            }
        }

        if(visited[sink]==-1) break;

        // 유량 구하기
        int f = INF;
        for(int i=sink; i!=source; i=visited[i]) {
            f = min(f, capacity[visited[i]][i] - flow[visited[i]][i]);
        }

        // 유량 적용하기
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

    return 0;
}