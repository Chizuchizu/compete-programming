#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
bool used[2009][2009];


struct UnionFind {
    vector<int> par;  // par[a] = b として, aの親がbであることを表す
    void init(int N) {
        par.resize(N);
        rep(i, N) {
            par[i] = i;
        }
    }

    int root(int x) {  // xの根を再帰で調べる
        if (par[x] == x) return x;
        return par[x] = root(par[x]);  // 根に直接繋ぐ
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);

        return rx == ry;
    }
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    UnionFind tree;
    tree.init(H * W);

    for (int i = 1; i <= Q; i++) {
        int ti;
        cin >> ti;

        if (ti == 1) {
            int x, y;
            cin >> x >> y;

            rep(j, 4) {
                int sx = x + dx[j];
                int sy = y + dy[j];
                if (used[sx][sy]) {
                    int hash1 = (x - 1) * W + (y - 1);
                    int hash2 = (sx - 1) * W + (sy - 1);

                    tree.unite(hash1, hash2);
                }
            }
            used[x][y] = true;
        } else {
            int xa, xb, ya, yb;
            cin >> xa >> ya >> xb >> yb;

            int hash1 = (xa - 1) * W + (ya - 1);
            int hash2 = (xb - 1) * W + (yb - 1);

            bool ans = tree.same(hash1, hash2);
            if (!used[xa][ya] || !used[xb][yb]) {
                cout << "No" << endl;
            } else if (ans) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
