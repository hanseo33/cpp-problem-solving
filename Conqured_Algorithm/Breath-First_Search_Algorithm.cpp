// BFS 알고리즘 연습
// https://www.acmicpc.net/problem/2178
/*
4 6
110110
110110
111111
111101*/
#include <iostream>
#include <queue>
#include <utility>
#define MAX 101

using namespace std;

int N, M;
int maze[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];

int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;

void BFS(int start_x, int start_y) {
    visited[start_x][start_y] = true;   // 시작점 방문 기록
    q.emplace(start_x, start_y);        // 시작좌표 큐에 삽입
    dist[start_x][start_y]++;           // 문제에서 시작칸을 1칸으로 치기때문에 거리++

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i=0; i<4; i++) {
            // 상하좌우 이동한 후의 좌표값
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            // 그 좌표가 maze안에 있는지, 방문안한 좌표인지, 값이 1인지 확인
            if( (0<=x_new && x_new<N) && (0<=y_new && y_new<M)
            && !visited[x_new][y_new] && maze[x_new][y_new]==1) {
                
                // 조건을 만족하면 값 갱신
                visited[x_new][y_new] = true;
                q.emplace(x_new, y_new);
                dist[x_new][y_new] = dist[x][y] + 1;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    // N, M을 x,y 그대로 사용한다. 사실상 고등수학때 풀던 좌표평면이랑 방향이 다른 셈.
    for(int i=0; i<N; i++) {
        string input;
        cin >> input;

        for(int j=0; j<M; j++) {
            maze[i][j] = input[j] - '0';
        }
    }
    
    BFS(0, 0);

    cout << dist[N-1][M-1];

    return 0;
}