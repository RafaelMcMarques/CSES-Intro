#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,j,i,sol;
    cin >> n;

    for (int k = 0; k < n; k++) {
        cin >> i >> j;
        if ( i > j) {
            // linha
            if (i%2)
                sol = (i - 1) * (i - 1) + j;
            else
                sol = i*i - (j - 1);
        } else {
            if (j%2)
                sol = j*j - (i - 1);
            else
                sol = (j - 1) * (j - 1) + i;
        }
        cout << sol << endl;
    }
}
