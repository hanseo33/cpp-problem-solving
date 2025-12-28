#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> card;
    for(int i=1; i<=n; i++) {
        card.emplace(i);
    }

    while(card.size() > 1) {
        card.pop();
        int temp = card.front();
        card.pop();
        card.emplace(temp);
    }

    cout << card.front() << "\n";

    return 0;
}

// 최대힙을 구현할때에 priority_queue를 사용한다.
// 최소힙은 3번째 인자에 cmp로 바꿔서 해야한다.
// 다음은 절댓값힙 코드이다.
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

// return에서 true면 b가 top으로 온다. (true일때 a를 뒤로 보낸다.)
struct cmp {
    bool operator()(int a, int b) {
        // 절댓값이 같을 경우를 먼저 작성.
        if(abs(a) == abs(b)) {
            return a > b;
        }
        // 절댓값이 다를 때.
        return abs(a) > abs(b);
    }
};

int main() {
    int N;
    cin >> N;

    priority_queue<int, vector<int>, cmp> pq;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if(x == 0) {
            if(pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.emplace(x);
        }
    }

    return 0;
}