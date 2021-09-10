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

    queue<int> que;
    que.push(0);

    // BFSだったらminを使わず直接代入してOK

    while (!que.empty()) {
        int v = que.front(); que.pop();

        for (int pow6 = 1; v + pow6 <= N; pow6 *= 6) {
            if (dp[v + pow6] == INF) {
                dp[v + pow6] = dp[v] + 1;
                que.push(v + pow6);
            }
        }
        for (int pow9 = 1; v + pow9 <= N; pow9 *= 9) {
            if (dp[v + pow9] == INF) {
                dp[v + pow9] = dp[v] + 1;
                que.push(v + pow9);
            }
        }
    }

    cout << dp[N] << endl;

    return 0;
}
