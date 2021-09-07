#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

struct edge {
    int to;
    int cost;
};
typedef pair<int, int> P;

#define INF 100009
int n, m;
int d[INF];
vector<edge> G[INF];

void dijkstra(int i) {
    fill(d, d + n, pow(10, 9) + 5);

    priority_queue<P, vector<P>, greater<P>> que;

    d[i] = 0;
    que.push(P(0, i));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;  // pを経由すると最短になる可能性がなければ次にすすむ

        for (int j = 0; j < G[v].size(); j++) {
            edge e = G[v][j];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    int d_1[n];  // 始点iからの距離
    int d_2[n];

    dijkstra(0);
    rep(i, n) {
        d_1[i] = d[i];
    }
    dijkstra(n - 1);
    rep(i, n) {
        d_2[i] = d[i];
    }


    rep(j, n) {
        cout << d_1[j] + d_2[j] << endl;
    }


    // return 0;
}
