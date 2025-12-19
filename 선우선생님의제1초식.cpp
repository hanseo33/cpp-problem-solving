#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <utility>
#include <cmath>
#include <cstdint>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <iomanip>
#include <limits>
#include <numeric>

//#include "atcoder/segtree.hpp"
// #include <atcoder/modint.hpp>

#define LMAX 9223372036854775807
#define IMAX 2147483647
#define INF 2e17
#define MOD 998244353
#define endl '\n'
#define END "0"
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<long long,long long>
#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
template<typename T>
void kill(T end) { cout << end; exit(0); }
// using mint = atcoder::modint998244353;

int main() {
    FASTIO
    int n; cin>>n;

    int temp=n;
    bool flag=1;
    cout<<temp<<" ";
    for(int i=n-1;i>=1;i--) {
        if (flag) {
            temp-=i;
        } else {
            temp+=i;
        }
        cout<<temp<<" ";
        flag=!flag;
    }


    return 0;
}
//n-1, n-2 ... 1이런식으로 줄어들어야함
//5 1 4 2 3