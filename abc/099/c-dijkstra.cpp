#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

const int INF = 110000;
int dp[INF];

int main() {
    int N;
    cin >> N;
    fill(dp, dp + INF, INF);

    dp[0] = 0;
    rep(i, N) {
        //if (i == 0) continue;
        for (int pow6 = 1; pow6 + i <= N; pow6 *= 6) {
            dp[i + pow6] = min(dp[i + pow6], dp[i] + 1);
        }
        for (int pow9 = 1; pow9 + i <= N; pow9 *= 9) {
            dp[i + pow9] = min(dp[i + pow9], dp[i] + 1);
        }
    }
    cout << dp[N] << endl;

    return 0;
}
