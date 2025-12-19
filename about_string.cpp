#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;
    cout << input.length();   
    return 0;
}

/*
    note about stoi. string -> int
*/
#include <iostream>

using namespace std;

int main() {
    string A, B, C;
    cin >> A >> B >> C;
    int a = stoi(A);
    int b = stoi(B);
    int c = stoi(C);
    cout << a + b - c << endl;

    string concat = A + B;
    cout << stoi(concat) - c;

    return 0;
}