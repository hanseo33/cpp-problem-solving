/*
두 자연수 A와 B가 있을 때, A%B는 A를 B로 나눈 나머지 이다. 예를 들어, 7, 14, 27, 38을 3으로 나눈 나머지는 1, 2, 0, 2이다. 

수 10개를 입력받은 뒤, 이를 42로 나눈 나머지를 구한다. 그 다음 서로 다른 값이 몇 개 있는지 출력하는 프로그램을 작성하시오.

*/
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> bag;
    int input = 0;
    for(int i=0; i<10; i++) {
        cin >> input;
        bag.insert(input%42);
    }
    
    cout << bag.size();

    return 0;
}

/*
    우선 다른 걸 찾을려면, 나머지 1이 처음에 나왔다가 마지막에 다시 나올 수도 있다.
    이걸 기억해놔야 하지 않을까...? 배열?ㅋㅋㅋㅋㅋ 일단 시도해보자.

    배열로 하다가 너무 어려워서 set이 생각났다. set으로 구현해보겠다.
*/


// set에 넣었는 지 안넣었는지를 구분해서 행동을 결정할 수도 있다.

#include <iostream>
#include <set>

using namespace std;

int main() {
    string input;
    cin >> input;
    int arr[26];
    for(int i=0; i<26; i++) arr[i] = -1;

    set<char> alphabet;
    int index = 0;
    for(int i=0; i<input.length(); i++) {
        auto result = alphabet.insert(input[i]);
        if(result.second) arr[input[i]-65-32] = i;
    }
    
    for(int i=0; i<26; i++) cout << arr[i] << " ";
    return 0;
}

/* iterator를 사용해서, set 처음부터 끝까지 출력 */
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> hw;

    for(int i=1; i<=30; i++) {
        hw.insert(i);
    }
    int me = 0;
    for(int i=0; i<28; i++) {
        cin >> me;
        hw.erase(me);
    }
    for(set<int>::iterator it=hw.begin(); it!=hw.end(); it++) cout << *it << '\n';

    return 0;
}

/* mySet.find(x)에서 x를 못 찾으면, mySet.end() iterator를 리턴하고, 찾으면 해당 x의 iterator를 리턴한다. */
int main() {
    set<int> mySet;
    mySet.insert(333);

    if(mySet.find(33) == mySet.end()) cout << 0 << '\n';
    else cout << 1 << '\n';

    return 0;
}

// clear도 가능하다
int main() {
    set<int> mySet;

    for(int i = 0; i < 10; i++) {
        mySet.insert(i);
    }

    // 공집합으로 초기화
    mySet.clear();

    return 0;
}

// 이중우선순위큐를 multiset으로 푸는 문제
#include <iostream>
#include <set>

using namespace std;

int main() {
    int k;
    cin >> k;

    multiset<int> ms;

    for(int i = 0; i < k; i++) {
        char c;
        int x;
        cin >> c >> x;

        if(c == 'I') {
            ms.insert(x);
        } else {
            if(ms.empty()) continue;

            if(x == 1) {
                ms.erase(prev(ms.end())); // end iterator 하나 전 거를 지우겠다.
            } else{
                ms.erase(ms.begin());
            }
        }
    }

    if(ms.empty()) {
        cout << "EMPTY\n";
    } else {
        cout << *prev(ms.end()) << " " << *ms.begin() << '\n'; // *로 주소안에 있는 값을 출력.
    }
    
    return 0;
}