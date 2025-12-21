#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    HTT, THT, TTH를 구분하기 위해서
    각 자릿수마다 다른 가중치를 부여하여 차별화한다.

    나올 수 있는 가중치의 합 갯수와 배열 칸수를 맞추면

    cnt[val]++ 이 가능해진다.
*/

void solve() {
    string s;
    cin >> s;

    // 0칸을 0으로 설정, 뒷칸들은 값 미입력으로 0으로 초기화. 
    // " , " 는 있어도 되고 없어도 되고. 있으면 뒤에 값들이 더 있다는 것을 내포
    int cnt[8] = {0, }; 

    for(int i = 0; i < 38; i++) {
        int val = 0;
        
        // 쉽고 직관적인 방법
        // if(s[i] == 'H') val += 4;
        // if(s[i + 1] == 'H') val += 2;
        // if(s[i + 2] == 'H') val += 1;

        // 쉬프트, OR 연산자 활용
        val |= (s[i] == 'H') << 2;
        val |= (s[i + 1] == 'H') << 1;
        val |= (s[i + 2] == 'H');

        cnt[val]++;
    }

    for(const auto& i : cnt) {
        cout << i << " ";
    }
    cout << '\n';
}

int main() {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        solve();
    }

    return 0;
}