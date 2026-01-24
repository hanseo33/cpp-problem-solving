#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    int count = 0;
    string target = "joke"; // 찾고자 하는 문자열

    while(getline(cin, line)) { // 한줄 입력받을때 마다
        size_t pos = 0; // 찾기 시작하는 위치
        while((pos = line.find(target, pos)) != string::npos) { // 찾고자 하는 게 있을 때까지
            count++;
            pos += 4; // joke 만큼 pos 갱신
        }
    }
    
    cout << count << '\n';

    return 0;
}