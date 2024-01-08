#include <bits/stdc++.h>
using namespace std;

vector<vector <char>> b(8);
unordered_set <int> col;
unordered_set <int> d2;
unordered_set <int> d1;

void putQueen(int i, int j) {
    col.insert(j);
    d1.insert(i + 7 - j);
    d2.insert(i + j);
}

void removeQueen(int i, int j) {
    col.erase(j);
    d1.erase(i + 7 - j);
    d2.erase(i + j);
}

bool isPossible(int i, int j) {
    if (b[i][j] == '*')
        return false;
    if (col.count(j) > 0 || d1.count(i + 7 - j) > 0 || d2.count(i + j) > 0)
        return false;
    return true;
}

void solve(int i, long &sol) {
    if (i == 8) {
        sol++;
        return;
    }

    for (int j = 0; j < 8; j++) {
        if (isPossible(i,j)) {
            putQueen(i,j);
            solve(i + 1, sol);
            removeQueen(i, j);
        }
    }
}

int main() {
    char c;
    for(int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> c;
            b[i].push_back(c);
        }
    }

    long sol = 0;
    solve(0, sol);
    cout << sol << endl;
}
