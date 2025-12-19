#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string bigNumMux(string str1, string str2) {
    // 12345 -> 54321
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    vector<int> result(str1.length() + str2.length(), 0);
    for(int i=0; i<str1.length(); i++) {
        for(int j=0; j<str2.length(); j++) {
            int a = str1[i] - '0';
            int b = str2[j] - '0';
            result[i+j] += a * b;
        }
    }

    // carry 구현
    int carry = 0;
    for(int i=0; i<result.size(); i++) {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }

    // 최고자리 0이 아닌곳 찾기
    reverse(result.begin(), result.end()); // 54321 -> 12345
    int biggest_index = 0;
    while(biggest_index < result.size() && result[biggest_index]==0) biggest_index++;
   
    // biggest index까지만 string 출력하기
    string result_str = "";
    for(int i=biggest_index; i<result.size(); i++) {
        string temp = to_string(result[i]);
        result_str += temp;
    }
    // for(const auto& c : result) {
    //     result_str += to_string(c);
    // }

    return result_str;
}

int main() {
    int n;
    cin >> n;

    string result = "1";
    for(int i=1; i<=n; i++) {
        string temp = to_string(i);
        result = bigNumMux(result, temp);
        // cout << "This is " << i << " Factorial " << " : " << result << "\n";
    }

    // 순서 역순으로 만들고 0갯수 세기
    reverse(result.begin(), result.end());

    int count = 0;
    for(char c : result) {
        if(c != '0') break;
        count++;
    }

    cout << count << "\n";

    return 0;
}