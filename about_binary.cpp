#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main() {
    long long n;
    cin >> n;

    // 64bit binary
    bitset<64> b(n);
    string str = b.to_string();

    // find where 1 start
    cout << str.substr(str.find('1')) << '\n';

    return 0;
}