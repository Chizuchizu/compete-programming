#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> A(h, vector<int>(w));
    vector<int> row_sum(h, 0);
    vector<int> col_sum(w, 0);

    rep(i, h) {
        // 行
        rep(j, w) {
            // 列
            cin >> A[i][j];
            row_sum[i] += A[i][j];
            col_sum[j] += A[i][j];
        }
    }

    rep(i, h) {
        rep(j, w) {
            cout << row_sum[i] + col_sum[j] - A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
