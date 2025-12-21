#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N, r, c;
    cin >> N >> r >> c;

    long long pow2n = (1 << N);
    long long ret, x_low, x_high, y_low, y_high;
    ret = x_low = y_low = 0;
    x_high = y_high = pow2n - 1;

    for(int i = 0; i < N; i++) {
        pow2n = pow2n >> 1;

        long long x_mid = (x_low + x_high) >> 1;
        long long y_mid = (y_low + y_high) >> 1;
        
        long long xbit = r <= x_mid ? 0 : 2;
        long long ybit = c <= y_mid ? 0 : 1;
        
        if(!xbit) x_high = x_mid;
        else x_low = x_mid + 1;
        
        if(!ybit) y_high = y_mid;
        else y_low = y_mid + 1;
    
        ret += pow2n * pow2n * (xbit + ybit);
    }

    cout << ret << '\n';

    return 0;
}