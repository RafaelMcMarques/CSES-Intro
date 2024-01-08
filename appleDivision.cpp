#include <bits/stdc++.h>

using namespace std;


void bitMaskSums(vector<long long> nums, int n, long long opt, long long &sol)
{
    for (int b = 0; b < (1 << n); b++) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if ((1<<i & b))
                sum += nums[i];
        }
        if (abs(sum - opt) < abs(sol - opt)) 
            sol = sum;
    }
}

void backTrackSums(vector<long long> &nums, vector<int> &bins, int i, int n, long long opt, long long &sol)
{
    // generate sum and compare it to sol
    if (i == n) {
       long long sum = 0;
        for (int j = 0; j < n; j++) {
            if (bins[j])
                sum += nums[j];
        }
        if (abs(sum - opt) < abs(sol - opt)) 
            sol = sum;
        return;
    }

    //backtrack
    bins[i] = 0;
    backTrackSums(nums, bins, i + 1, n, opt, sol);
    bins[i] = 1;
    backTrackSums(nums, bins, i + 1, n, opt, sol);
}

void backTrackSum2(vector<long long> &nums, long long &sum, int n, int i, long long opt, long long &sol)
{
    if (n == i) {
        if (abs(sum - opt) < abs(sol - opt)) 
            sol = sum;
        return;
    }

    backTrackSum2(nums, sum, n, i + 1, opt, sol);
    sum += nums[i];
    backTrackSum2(nums, sum, n, i + 1, opt, sol);
    sum -= nums[i];
}

int main() {
    int n;
    cin >> n;
    vector <long long> nums(n);
    vector <int> bins(n);
    long long ts = 0;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        ts += nums[i];
    }

    long long opt = ts/2;
    long long sol;
    
    // brute force all possible sums
    long long sum = 0;
    backTrackSum2(nums, sum, n, 0, opt, sol);
    cout << abs((ts - sol) - sol) << endl;
}
