#include <iostream>

using namespace std;

int main() {
    int n; 
    cin >> n;

    int card[n][3];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> card[i][j];
        }
    }

    int score[n] = {0, };
    for(int t = 0; t < 3; t++) {
        int check[101] = {0, };
        for(int i = 0; i < n; i++) {
            check[card[i][t]]++;
        }

        for(int i = 0; i < n; i++) {
            if(check[card[i][t]] == 1) {
                score[i] += card[i][t];
            }
        }
    }

    for(int n : score) {
        cout << n << '\n';
    }

    return 0;
}