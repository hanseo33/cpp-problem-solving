//"YYYY-MM-DD"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    time_t timer = time(nullptr);
    struct tm* t = localtime(&timer);
    
    cout << t->tm_year+1900 << "-" << t->tm_mon+1 << "-" << t->tm_mday;

    return 0;
}
/*
    ctime안에 time_t라는 시간을 담기위한 타입이 있고, time()은 이것을 가져오기 위한 함수이다.
    localtime()이라는 함수는 1900년부터 지금까지의 초(sec)을 보기좋게 struct tm 이라는 구조체에 넣는 것이다.
    주의할 점은 1900년부터이기 때문에 년에는 +1900을, 1월을 0으로 보기때문에 +1달을 해줘야 한다는 점이다.
*/