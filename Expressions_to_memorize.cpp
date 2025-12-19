#include <iostream>
#include <vector>

using namespace std;

// 소수찾기
bool isPrime(int n) {
    if(n<=1) return false;
    for(int i=2; i<n; i++) {
        if(n%i==0) return false;
    }
    return true;
}

// 제곱근을 이용한 소수찾기
// i*i <= n 에 "="가 있어야한다.
bool isPrime_squrt(int n) {
    if(n<=1) return false;
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) return false;
    }
    return true;
}

int main() {
    int Tcount, p ,T;
    // 나눈 수를 무조건 올림하고 싶을때 쓰는 표현이다.
    Tcount += (p + T - 1) / T;
    
    return 0;
}

// 우유 찾기 문제. 0 -> 1 -> 2 -> 0... 이런식으로 계속바꾸고 싶을때
int main() {
    // 입출력 속도 향상 (습관적으로 넣어주면 좋습니다)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int count = 0;      // 마신 우유 개수
    int next_milk = 0;  // 다음에 마셔야 할 우유 (0: 딸기부터 시작)

    for (int i = 0; i < n; i++) {
        int milk;
        cin >> milk;

        // 현재 가게의 우유가 내가 기다리던 우유와 같다면
        if (milk == next_milk) {
            count++;                 // 마신다
            next_milk = (next_milk + 1) % 3; // 다음 순서로 변경 (0->1->2->0...)
        }
    }

    cout << count << "\n";

    return 0;
}