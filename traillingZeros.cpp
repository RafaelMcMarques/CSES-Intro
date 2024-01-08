#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long sol = 0;
    
    // para cada multiplo de 5 em [1..n] adiciona um zero
    // para cada multiplo de 25 adiciona 2 zeros
    // cada mult de 125 adiciona 3
    // ...
    for (long long i = 5; n / i > 0; i *= 5)
        sol += n / i;

    cout << sol << endl;
}
