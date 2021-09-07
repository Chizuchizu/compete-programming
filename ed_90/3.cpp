#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

using Graph = vector<vector<int>>;

vector<int> dfs(const Graph &G, int s) {
    int N = (int)G.size();

    // ある頂点sからの距離
    vector<int> dist(N, -1);
    // 自分自身に対しては0
    dist[s] = 0;

    // まず自分自身をstackに突っ込む
    stack<int> st({s});

    // stackがなくなるまで
    while (!st.empty()) {
        // stackから値を取り出す
        int v = st.top();
        // 取り出したら捨てる
        st.pop();
        // sから伸びる頂点nvを探索する
        for (auto nv: G[v]) {
            if (dist[nv] == -1) {
                // もし探索していないところならば、stackに追加
                st.push(nv);
                // 隣接しているので距離は+1
                dist[nv] = dist[v] + 1;
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

    auto dist0 = dfs(G, 0);

    // 頂点0から最も遠い頂点とその距離を調べる
    int mx = -1, mv = -1;
    rep(v, N) {
        if (mx < dist0[v]) {
            mx = dist0[v];
            mv = v;
        }
    }
    // cout << endl;

    auto distmv = dfs(G, mv);

    mx = -1;
    rep(v, N) {
        if (mx < distmv[v]) {
            mx = distmv[v];
        }
    }

    cout << mx + 1 << endl;

    return 0;
}
