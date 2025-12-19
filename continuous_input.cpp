#include <iostream>

using namespace std;

int main() {
    string input;
    while(getline(cin, input)) {
        cout << input << '\n';
    }
    // EOF on mac is command+D
    return 0;
}