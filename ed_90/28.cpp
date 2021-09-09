#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

vector<vector<int>> cnt(1001, vector<int>(1001, 0));

int main() {
    int N;
    cin >> N;

    // fill(cnt, cnt + sizeof(cnt), 0);

    rep(i, N) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        cnt[lx][ry] -= 1;
        cnt[lx][ly] += 1;
        cnt[rx][ry] += 1;
        cnt[rx][ly] -= 1;
    }
    rep(i, 1001) {
        rep(j, 1000) {
            cnt[i][j + 1] += cnt[i][j];
        }
    }
    rep(j, 1001) {
        rep(i, 1000) {
            cnt[i + 1][j] += cnt[i][j];
        }
    }

    vector<int> ans(N);
    rep(i, 1001) {
        rep(j, 1001) {
            if (cnt[i][j] >= 1) ans[cnt[i][j] - 1] += 1;
        }
    }

    for (int a: ans) {
        cout << a << endl;
    }

    return 0;
}
