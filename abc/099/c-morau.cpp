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
    rep(i, N+1) {
        if (i == 0) continue;
        for (int pow6 = 1; pow6 <= i; pow6 *= 6) {
            dp[i] = min(dp[i], dp[i - pow6] + 1);
        }
        for (int pow9 = 1; pow9 <= i; pow9 *= 9) {
            dp[i] = min(dp[i], dp[i - pow9] + 1);
        }
    }
    cout << dp[N] << endl;

    return 0;
}
