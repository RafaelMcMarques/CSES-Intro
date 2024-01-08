#include <bits/stdc++.h>

using namespace std;

unsigned long long solve(long long k) {
    if (k == 1)
        return 0;
    
    if (k == 2)
        return  6;
 
    if (k == 3)
        return 28;

    unsigned long long sum{0};
    unsigned long long s{0};
    sum += 48;
    sum += (k - 4) * (k - 4) * 8;
    sum += (k - 4) * 6 * 4;
    sum += (k - 4) * 4 * 4;
    s = ((k * k) * (k * k - 1) - sum)/2;
    return s;
}


int main() {
    long long k;
    cin >> k;
    for (long long i = 1; i <= k; i++)
        printf("%lld\n", solve(i));
}
