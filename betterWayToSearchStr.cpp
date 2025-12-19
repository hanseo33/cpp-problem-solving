/*
    배열을 안 만들 수 있다면 안 만드는 것이 효율적이다. 
    for(char c : str) 을 꼭 기억하자.
*/

#include <iostream>
#include <iomanip>

using namespace std;

void init() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio(false);
}

int main() {
    init();
    int n = 0;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int times;
        string str;
        cin >> times >> str;
        for(char c : str) {
            for(int j=0; j<times; j++) {
                cout << c;
            }
        }
        cout << '\n';
    }
    

    return 0;
}