#include<bits/stdc++.h>

using namespace std;

bool solve () {
    long long a;
    long long b;

    cin >> a >> b;

    if ((a+b) % 3)
        return false;

    if (2*min(a,b) < max(a,b))
        return false;

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << endl;
}
