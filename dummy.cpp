#include <iostream>
#include <string>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        string s;
        cin >> s;

        // 입력이 "0"이면 종료
        if (s == "0") break;

        // 1단계: 문자열의 각 자릿수를 더해서 정수로 변환
        int n = 0;
        for (char c : s) {
            n += (c - '0'); // 문자를 숫자로 변환 ('0'의 아스키코드 값을 뺌)
        }

        // 2단계: 결과가 두 자리 수 이상이면 계속 각 자릿수를 더함
        // 예: 24 -> 2+4 = 6 (종료)
        // 예: 39 -> 3+9 = 12 -> 1+2 = 3 (종료)
        while (n >= 10) {
            int temp_sum = 0;
            int temp_n = n;
            
            while (temp_n > 0) {
                temp_sum += temp_n % 10; // 마지막 자릿수 더하기
                temp_n /= 10;            // 마지막 자릿수 제거
            }
            n = temp_sum; // 새로운 합으로 갱신
        }

        cout << n << "\n";
    }

    return 0;
}