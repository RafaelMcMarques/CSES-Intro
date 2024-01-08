#include <bits/stdc++.h>
using namespace std;

vector <char> path(48);
vector <int> moves = {1, -1, 7, -7};
vector <int> visited(49, 0);

void solve(int n, int pos, long long &sol) {
    if (n == 48) {
        if (pos == 42)
            sol++;
        return;
    }

    if (pos == 42)
        return;

    // esquerda e direita ocupadas, cima e baixo livre
    if (((pos%7 == 6 || visited[pos+1]) == 1 && (pos%7 == 0 || visited[pos-1])) 
        && (pos + 7 < 49 && visited[pos + 7] == 0) && (pos - 7 >= 0 && visited[pos - 7] == 0))
        return; 

    // direita e esquerda livres, baixo e cima ocupados
    if ((pos%7 != 6 && visited[pos+1] == 0) && (pos%7 != 0 && visited[pos-1] == 0)
        && (pos + 7 >= 49 || visited[pos + 7]) && (pos - 7 < 0 || visited[pos - 7]))
        return;

    int step;
    if (path[n] == '?') {
        for (int i = 0; i < 4; i++) {
            step = moves[i];
            if (pos + step < 49 && pos + step >= 0 && visited[pos + step] == 0) {
                if (!(step == 1 && pos%7 == 6) && !(step == -1 && pos%7 ==0)) {
                    pos += step;
                    visited[pos] = 1;

                    solve(n + 1, pos, sol);

                    visited[pos] = 0;
                    pos -= step;
                }
            }
        }
    }

    else {
        if (path[n] == 'L')
            step = -1;
        
        else if (path[n] == 'R')
            step = 1;
        
        else if (path[n] == 'D')
            step = 7;

        else 
            step = -7;

        if (pos + step < 49 && pos + step >= 0 && visited[pos + step] == 0) {
            if (!(step == 1 && pos%7 == 6) && !(step == -1 && pos%7 ==0)) {
                pos += step;
                visited[pos] = 1;

                solve(n + 1, pos, sol);

                visited[pos] = 0;
                pos -= step;
            }
        }
    }
}


int main() {
    for (int i = 0; i < 48; i++)
        cin >> path[i];

    long long sol = 0;
    visited[0] = 1;
    solve(0, 0, sol);
    cout << sol << endl;

}
