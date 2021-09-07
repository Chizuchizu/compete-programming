#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

using Graph = vector<vector<int>>;

vector<int> bfs(const Graph &G, int s) {
    int N = (int)G.size();

    // ある頂点sからの距離
    vector<int> dist(N, -1);
    queue<int> que({s});
    // 自分自身に対しては0
    dist[s] = 0;

    // queueがなくなるまで
    while (!que.empty()) {
        int v;
        v = que.front();
        que.pop();

        // vから辿れる頂点を探索
        for (auto nv: G[v]) {
            if (dist[nv] == -1) {
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }

    return dist;
}

int main() {
    int N;
    cin >> N;

    Graph G(N);

    rep(i, N-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    auto dist0 = bfs(G, 0);

    // 頂点0から最も遠い頂点とその距離を調べる
    int mx = -1, mv = -1;
    rep(v, N) {
        if (mx < dist0[v]) {
            mx = dist0[v];
            mv = v;
        }
    }
    // cout << endl;

    auto distmv = bfs(G, mv);

    mx = -1;
    rep(v, N) {
        if (mx < distmv[v]) {
            mx = distmv[v];
        }
    }

    cout << mx + 1 << endl;

    return 0;
}
