/*
5 2
1 4 2 5 1*/
#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int curV = 0;
    
    // 초기값 설정
    for(int i = 0; i < x; i++) {
        curV += arr[i];
    }
    
    // 최댓값, 최대카운트 설정
    int maxV = curV;
    int maxC = 1;

    // 배열을 순회하면서 maxV와 계속 비교
    for(int i = x; i < n; i++) {
        curV = curV + arr[i] - arr[i - x];

        if(curV > maxV) {
            maxV = curV;
            maxC = 1;
        } else if(curV == maxV) {
            maxC++;
        }
    }

    if(maxV == 0) {
        cout << "SAD\n";
        return 0;
    }

    cout << maxV << '\n' << maxC << '\n';

    return 0;
}