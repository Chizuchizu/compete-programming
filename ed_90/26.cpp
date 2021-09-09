#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

vector<int> G[100009];
int col[100009];
// fill(col, col + 1 << 10, -1)

void dfs(int pos, int cur) {
    col[pos] = cur;
    for (int i: G[pos]) {
        if (col[i] == -1) {
            dfs(i, 1 - cur);
        }
    }
}

int main() {
    int N;
    cin >> N;
    fill(col, col + N + 1, -1);

    rep(i, N - 1) {
        int A, B;
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    dfs(1, 0);

    vector<int> G1, G2;
    rep(i, N) {
        if (col[i + 1] == 0) {
            G1.push_back(i);
        } else {
            G2.push_back(i);
        }
    }

    if (G1.size() > G2.size()) {
        for (int i = 0; i < N / 2; i++) {
            cout << G1[i] + 1 << " ";
        }
    } else {
        for (int i = 0; i < N / 2; i++) {
            cout << G2[i] + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}
