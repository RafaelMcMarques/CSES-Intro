#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
    int n; cin >> n;
    long long ans {1};

    // saida: 2*2*2*2*2 ... mod 10⁹ + 7
    // (a * b)mod x = ((a mod x) * (b mod x)) mod x
    
    for (int i = 0; i < n; i++) {
        //ans = ((prevAns mod x) * (2 mod x)) mod x = 2^i mod x;
        ans = ans * 2;
        ans %= MOD;
    }
    cout << ans << "\n";
}
