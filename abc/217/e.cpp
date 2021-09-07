#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int L, Q;
    cin >> L >> Q;
    set<int> B;
    B.insert(0);
    B.insert(L);

    rep(i, Q) {
        int c, x;
        cin >> c >> x;
        if (c == 1) {
            B.insert(x);
        } else {

            int ans = 0;
            auto memo = B.lower_bound(x);
            ans = *memo;
            memo--;
            ans -= *memo;

            cout << ans << endl;
        }
    }

    return 0;
}
