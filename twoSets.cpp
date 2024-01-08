#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    unsigned long long n;
    cin >> n;
    unsigned long long sum = (n * n + n)/2;
    if (sum%2 || n == 1)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        if (n == 3) {
            cout << 1 << "\n" << 3 << "\n";
            cout << 2 << "\n" << "1 2" << endl;
        }
        else {
            unordered_set <unsigned long long> s1;
            unordered_set <unsigned long long> s2;

            for (unsigned long long i = 1; i <= (unsigned long long)n; i++)
                s2.insert(i);

            unsigned long long s = 0;
            for (unsigned long long i = (unsigned long long)n; i >= 1; i--) {
                s += i;
                if (s >= sum/2) { 
                    s1.insert(sum/2 - (s - i));
                    s2.erase(sum/2 - (s - i));
                    break;
                }
                else {
                    s1.insert(i);
                    s2.erase(i);
                }
            }
            
            cout << s1.size() << endl;
            for (auto x : s1)
                cout << x << " ";
            cout << endl;
            
            cout << s2.size() << endl;
            for (auto x : s2)
                cout << x << " ";
            cout << endl;
        }
    }
}
