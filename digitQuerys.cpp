#include <bits/stdc++.h>

using namespace std;

long long xpow(long long x, unsigned int y){
    long long res=1;
    while(y>0){
        if (y&1) res= (res*x); y=y>>1; x=(x*x);
    }
    return res;
}

void solve() {
    long long n;
    cin >> n;
    long long d = 1;
    long long i = 9;
    while (n - i > 0) {
        n -= i;
        d++; 
        i = d * 9 * xpow(10, d - 1);
    }

    n--; 
    long long num = n / d;
    long long dig = (n%d);
    num = xpow(10, d - 1) + num;
    
    string sol = to_string(num);
    cout << sol[dig] << endl;
}



int main() {
    int q;
    cin >> q;
    while (q--)
        solve();
}
