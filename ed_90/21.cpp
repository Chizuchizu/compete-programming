#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int A[1 << 18], B[1 << 18];
bool used[1 << 18];
vector<int> G[1 << 18];
vector<int> H[1 << 18];
vector<int> I;
long long cnts = 0;

void dfs(int pos) {
    used[pos] = true;
    for (int i: G[pos]) {
        if (!used[i]) dfs(i);
    }
    I.push_back(pos);
}

void dfs2(int pos) {
    used[pos] = true;
    cnts++;
    for (int i: H[pos]) {
        if (!used[i]) dfs2(i);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        H[B[i]].push_back(A[i]);
    }
    for (int i = 1; i <= N; i++) {
        if (!used[i]) dfs(i);
    }
    reverse(I.begin(), I.end());

    fill(used, used + N + 2, false);

    long long Answer = 0;

    for (int i: I) {
        if (used[i]) continue;
        cnts = 0;
        dfs2(i);
        Answer += cnts * (cnts - 1LL) / 2LL;
    }
    cout << Answer << endl;
    return 0;
}
