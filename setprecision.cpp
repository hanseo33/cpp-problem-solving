#include <iostream>
#include <iomanip> // setprecision

using namespace std;

int main() {
	double A, B;
    
    cin >> A >> B;
    
    // 실제 값을 변경하는 것이 아닌 출력방식만 그렇게 만드는 것이다.
    
    cout << fixed; // 소수점 표기 방식을 고정
    cout << setprecision(9); // 소수점 9자리까지 반올림해서 출력
    cout << A/B << '\n'; 
    
    return 0;
}