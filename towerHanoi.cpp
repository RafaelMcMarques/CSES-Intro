#include <bits/stdc++.h>
using namespace std;

void solve(int n, int a, int b)
{
    if (n == 1) {
        cout << a << " " << b << "\n";
        return;
    }
    
    solve(n - 1, a, 6 - (a + b));
    cout << a << " " << b << "\n";
    solve(n - 1, 6 - (a + b), b);
}

int main() {
    int n;
    cin >> n;
    cout << pow(2,n) - 1 << endl; 
    solve(n, 1, 3);
}
