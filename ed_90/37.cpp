#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

// https://atcoder.jp/contests/typical90/submissions/25517823
class segment_tree {
private:
    int sz;
    std::vector<long long> seg;
    std::vector<long long> lazy;

    void push(int k) {
        if (k < sz) {
            lazy[k * 2] = max(lazy[k * 2], lazy[k]);
            lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
        }
        seg[k] = max(seg[k], lazy[k]);
        lazy[k] = 0;
    }

    void update(int a, int b, long long x, int k, int l, int r) {
        push(k);  // k番目の値を初期値にする（上に伝播させる）
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = x;
            push(k);  // 完全に内側なら上に伝播させる（この区間を評価するときにはこの１つ上をみるので）
            return;
        }
        update(a, b, x, k * 2, l, (l + r) >> 1);
        update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
        seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
    }

    long long range_max(int a, int b, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return seg[k];
        long long lc = range_max(a, b, k * 2, l, (l + r) >> 1);
        long long rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
        return max(lc, rc);
    }

public:
    segment_tree() : sz(0), seg(), lazy() {};

//    explicit segment_tree(int N) {
//        sz = 1;
//        while (sz < N) {
//            sz *= 2;
//        }
//        seg = std::vector<long long>(sz * 2, 0);
//        lazy = std::vector<long long>(sz * 2, 0);
//    }

    void init(int N) {
        sz = 1;
        while (sz < N) {
            sz *= 2;
        }
        seg = std::vector<long long>(sz * 2, -INT64_MAX);
        lazy = std::vector<long long>(sz * 2, -INT64_MAX);
    }

    void update(int l, int r, long long x) {
        update(l, r, x, 1, 0, sz);
    }

    long long range_max(int l, int r) {
        return range_max(l, r, 1, 0, sz);
    }
};


int main() {
    long long W, N;
    cin >> W >> N;
    long long L[N], R[N], V[N];
    rep(i, N) {
        //int l, r, v;
        cin >> L[i] >> R[i] >> V[i];
    }
    segment_tree seg[(int) W + 1];
    rep(i, W + 1) {
        seg[i].init(W + 1);
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, -INT64_MAX));
    //fill(dp, dp+sizeof(dp), - 1 << 10);
    rep(i, N + 1) {
        dp[i][0] = 0;
    }
    seg[0].update(0, 1, 0);

    rep(i, N) {  // i番目まで使う
        rep(j, W + 1) {  // 香辛料の合計
            //for (long long  j = 1; j <= W; j++){
            dp[i + 1][j] = dp[i][j];

            int cl = max(0, j - (int) R[i]);
            int cr = max(0, j - (int) L[i] + 1);
            if (cl == cr) continue;

            long long val = seg[i].range_max(cl, cr);
            //cout <<" "<< val <<" "<< V[i] << endl;
            if (val != -INT64_MAX) dp[i + 1][j] = max(dp[i][j], val + V[i]);

            //cout << i << " " << j << " " << val << " " << dp[i + 1][j] << " ";
            //if (flag) cout << dp[i][j - L[i]];
            //cout << endl;
        }
        rep(j, W + 1) {
            seg[i + 1].update(j, j+1, dp[i+1][j]);
        }
    }

    cout << ((dp[N][W] > 0) ? dp[N][W] : -1) << endl;
    return 0;
}
