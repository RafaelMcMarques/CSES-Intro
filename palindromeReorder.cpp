#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int len = s.size();
    vector<char> sol (len, '*');
    sort(s.begin(), s.end());

    int i;
    int j{0};
    for (i = 0 ; i < len ; i+=2) {
        if (s[i] != s[i + 1]) {
            if (len%2) {
                if (sol[len/2] != '*') {
                    cout << "NO SOLUTION" << endl;
                    return 0;
                }
                else {
                    sol[len/2] = s[i];
                    i--;
                    continue;
                }
            }
            else {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
        sol[j] = s[i];
        sol[len - j - 1] = s[i + 1];
        j++;
    }
    
    for (int k = 0; k < len; k++)
        cout << sol[k];
    cout << endl;
}
