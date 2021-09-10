#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

vector<vector<int>> G;
vector<int> C;

void dfs(int root, int parent) {
    int deg = G[root].size();
    rep(i, deg) {
        int u = G[root][i];
        if (u == parent) continue;
        dfs(u, root);
        C[root] += C[u];
    }
}

int main() {
    int N;
    cin >> N;

    G.resize(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    int Q;
    cin >> Q;
    C.resize(N);
    rep(i, Q) {
        int K;
        cin >> K;
        fill(C.begin(), C.end(), 0);

        rep(j, K) {
            int v;
            cin >> v;
            v--;
            C[v] += 1;
        }
        dfs(0, -1);

        int ans = 0;
        rep(j, N) {
            if (C[j] != 0 && C[j] < K) {
                ans++;
            }
        }
        cout << ans << endl;
    }


    return 0;
}
