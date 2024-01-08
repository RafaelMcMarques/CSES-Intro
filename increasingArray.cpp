#include <bits/stdc++.h>

using namespace std;

int main() {
    long n, p, r;
    cin >> n;

    cin >> p;
    long sum{0};
    for (int i = 1; i < n; i++) {
        cin >> r;
        if (r < p) {
            sum += (p - r);
            r += p - r;
        }
        p = r;
    }
    cout << sum << endl;
}
