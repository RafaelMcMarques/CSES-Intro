#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    char ach = s[0];
    int len{1};
    int max{1};
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ach)
            len+=1;
        else {
            if (len > max)
                max = len;
            len = 1;
        }
        ach = s[i];
    }
    if (len > max)
        max = len;
    cout << max << endl;
}
