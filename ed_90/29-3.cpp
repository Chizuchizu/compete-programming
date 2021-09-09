#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

class segment_tree {
private:
    int sz;
    std::vector<int> seg;
    std::vector<int> lazy;

    void push(int k) {
        if (k < sz) {
            lazy[k * 2] = max(lazy[k * 2], lazy[k]);
            lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
        }
        seg[k] = max(seg[k], lazy[k]);
        lazy[k] = 0;
    }

    void update(int a, int b, int x, int k, int l, int r) {
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

    int range_max(int a, int b, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return seg[k];
        int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
        int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
        return max(lc, rc);
    }

public:
    segment_tree() : sz(0), seg(), lazy() {};

    explicit segment_tree(int N) {
        sz = 1;
        while (sz < N) {
            sz *= 2;
        }
        seg = std::vector<int>(sz * 2, 0);
        lazy = std::vector<int>(sz * 2, 0);
    }

    void update(int l, int r, int x) {
        update(l, r, x, 1, 0, sz);
    }

    int range_max(int l, int r) {
        return range_max(l, r, 1, 0, sz);
    }
};

int main() {
    int W, N;
    cin >> W >> N;

    segment_tree seg(W);

    rep(i, N) {
        int L, R;
        cin >> L >> R;
        int height = seg.range_max(L - 1, R) + 1;
        seg.update(L - 1, R, height);
        cout << height << endl;
    }


    return 0;
}
