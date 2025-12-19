#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);

    while(getline(ss, token, delimiter)) {
        if(!token.empty()) {
            tokens.emplace_back(token);
        }
    }

    return tokens;
}

int main() {
    string input;
    cin >> input;

    vector<string> result = split(input, '/');

    int K = stoi(result[0]);
    int D = stoi(result[1]);
    int A = stoi(result[2]);

    if(K+A<D || D==0) cout << "hasu" << endl;
    else cout << "gosu" << endl;

    return 0;
}

/*
    getline(stringstream객체, 변수이름, 구분자)
*/

// 덧셈으로만 이루어진 문자열을 계산하는 함수
int calculate_sum(const string& s) {
    int sum = 0;
    string number_str;
    stringstream ss(s);

    // '+' 기호를 기준으로 숫자들을 분리
    while (getline(ss, number_str, '+')) {
        // 분리된 문자열을 정수로 변환하여 더함
        sum += stoi(number_str);
    }
    return sum;
}