#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        stack<int> parentheses;
        string input;
        cin >> input;

        bool isValid = true;
        for(const char c : input) {
            if(c=='(') {
                parentheses.emplace(333);
            } else if(c==')' && !parentheses.empty()){
                parentheses.pop();
            } else {
                cout << "NO\n";
                isValid = false;
                break;
            }
        }

        if(!isValid) continue;
        if(parentheses.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}