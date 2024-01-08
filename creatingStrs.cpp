#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort (s.begin(), s.end());
    vector <string> sol;

    do {
        sol.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << sol.size() << endl;
    for (auto x : sol)
        cout << x << endl;
}
