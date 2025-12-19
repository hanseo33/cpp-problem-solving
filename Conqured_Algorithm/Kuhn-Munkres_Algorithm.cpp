#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();
const int MAX_COST = 10000;
const int MAXN = 505;

int N;
// weight[i][j]는 i번 사람(X)이 j번 일(Y)을 할 때의 가중치 (C_max - cost)
long long weight[MAXN][MAXN];

// lx[i], ly[j]: 꼭짓점 x_i, y_j의 라벨
long long lx[MAXN], ly[MAXN];

// match_x[i]: i번 사람(X)과 매칭된 일(Y)의 번호
// match_y[j]: j번 일(Y)과 매칭된 사람(X)의 번호
int match_x[MAXN], match_y[MAXN];

// parent_y[j]: 교호 트리에서 y_j의 부모 (x_i)
int parent_y[MAXN];

// slack[j]: j번 일(Y)에 대한 슬랙 값. min(lx[i] + ly[j] - weight[i][j]) for i in S
long long slack[MAXN];

// slack_parent[j]: j번 일(Y)에 대해 최소 슬랙 값을 갖게 하는 x_i
int slack_parent[MAXN];

// visited_x[i]: i번 사람(X)이 S 집합에 포함되었는지 (교호 트리에 포함)
bool visited_x[MAXN];
// visited_y[j]: j번 일(Y)이 T 집합에 포함되었는지 (교호 트리에 포함)
bool visited_y[MAXN];

// 헝가리안 알고리즘 (Kuhn-Munkres)
long long hungarian() {
    // 0. 초기화 (Start)
    // 모든 y의 라벨을 0으로 설정 
    fill(ly, ly + N, 0);
    fill(match_x, match_x + N, -1);
    fill(match_y, match_y + N, -1);

    // x의 라벨을 연결된 간선 가중치의 최댓값으로 설정 
    for (int i = 0; i < N; ++i) {
        lx[i] = -INF;
        for (int j = 0; j < N; ++j) {
            lx[i] = max(lx[i], weight[i][j]);
        }
    }

    // 1. 매칭 상태 확인 (Step 1)
    // 각 x_i에 대해 매칭을 찾는다.
    for (int x_root = 0; x_root < N; ++x_root) {
        
        // 새 교호 트리를 만들기 위해 방문 배열 및 슬랙 초기화
        fill(visited_x, visited_x + N, false);
        fill(visited_y, visited_y + N, false);
        fill(parent_y, parent_y + N, -1);
        fill(slack, slack + N, INF);

        // x_root를 S에 추가하고 트리의 뿌리로 설정 
        visited_x[x_root] = true;

        // x_root에 연결된 모든 y에 대해 초기 슬랙 값 계산
        for (int y = 0; y < N; ++y) {
            slack[y] = lx[x_root] + ly[y] - weight[x_root][y];
            slack_parent[y] = x_root;
        }

        int x_match = -1; // 증가 경로의 마지막 x
        int y_match = -1; // 증가 경로의 마지막 y (매칭되지 않은 y)

        // 2 & 3. 교호 트리 탐색 및 라벨 수정 (Step 2 & 3)
        while (true) {
            long long alpha = INF;
            int y_best = -1;

            // (Step 2 검사 준비) T에 없는 y 중 최소 슬랙(alpha) 찾기 
            for (int y = 0; y < N; ++y) {
                if (!visited_y[y] && slack[y] < alpha) {
                    alpha = slack[y];
                    y_best = y;
                }
            }
            
            // (Step 2) 찾은 alpha > 0 이면 라벨 수정 
            if (alpha > 0) {
                for (int i = 0; i < N; ++i) {
                    if (visited_x[i]) lx[i] -= alpha; // S에 속한 x는 라벨 감소
                }
                for (int j = 0; j < N; ++j) {
                    if (visited_y[j]) ly[j] += alpha; // T에 속한 y는 라벨 증가
                    else slack[j] -= alpha; // T에 없는 y는 슬랙 감소
                }
            }

            // 이제 y_best는 G_l에 포함됨 (slack[y_best] == 0)
            // (Step 3) y_best (y)를 T에 추가 
            visited_y[y_best] = true;
            parent_y[y_best] = slack_parent[y_best];

            // (Step 3) y_best가 매칭되지 않은 경우 (M-unsaturated)
            if (match_y[y_best] == -1) {
                // M-증가 경로 발견! 
                y_match = y_best;
                break; // while(true) 루프 탈출
            } 
            // (Step 3) y_best가 매칭된 경우 (M-saturated)
            else {
                // 트리를 확장. y_best와 매칭된 x_new를 S에 추가 
                int x_new = match_y[y_best];
                visited_x[x_new] = true;

                // 새로 S에 추가된 x_new에 대해 슬랙 값들 갱신
                for (int y = 0; y < N; ++y) {
                    if (!visited_y[y]) {
                        long long new_slack = lx[x_new] + ly[y] - weight[x_new][y];
                        if (new_slack < slack[y]) {
                            slack[y] = new_slack;
                            slack_parent[y] = x_new;
                        }
                    }
                }
            }
        } // while (true)

        // 4. 매칭 개선 (M = M-delta-E(P)) 
        // 찾은 증가 경로를 따라 매칭을 뒤집는다.
        while (y_match != -1) {
            int x = parent_y[y_match];
            int prev_y = match_x[x];
            
            match_x[x] = y_match;
            match_y[y_match] = x;
            
            y_match = prev_y;
        }
    } // for (x_root)

    // 5. 종료 (Stop)
    // 모든 x가 매칭됨 (M-saturated) 
    // Theorem 5.5에 의해 현재 매칭이 최적 매칭 
    long long total_weight = 0;
    for (int i = 0; i < N; ++i) {
        total_weight += weight[i][match_x[i]];
    }
    return total_weight;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            long long cost;
            cin >> cost;
            // 최소 비용 -> 최대 가중치 변환
            weight[i][j] = MAX_COST - cost;
        }
    }

    long long max_total_weight = hungarian();

    // 최대 가중치 -> 최소 비용 변환
    long long min_total_cost = (long long)N * MAX_COST - max_total_weight;

    cout << min_total_cost << "\n";

    return 0;
}