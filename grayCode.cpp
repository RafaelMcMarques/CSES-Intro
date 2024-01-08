#include <bits/stdc++.h>
using namespace std;

void solve(int i, int n, vector<int>& sol, int b1, int b2)
{
    if (i == n) {
        for (auto x : sol)  
            cout << x;
        cout << endl;
        return;
    }
    
    sol[i] = b1;
    solve(i + 1, n, sol, 0, 1);
    sol[i] = b2;
    solve(i + 1, n, sol, 1, 0);
}

int main() {
    int n;
    cin >> n;
    vector<int> sol(n);
    solve(0, n, sol, 0, 1);
}
