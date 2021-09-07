#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

long long mod = 1000000007;

long long dp[100009][8]{0};

int main() {
    int N;
    string S;
    cin >> N >> S;

    string atcoder = "atcoder";

    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 7; j++) {
            dp[i + 1][j] += dp[i][j];

            if (S[i] == atcoder[j]) {
                dp[i + 1][j + 1] += dp[i][j];
            }

            dp[i + 1][j] %= mod;
        }
        dp[i + 1][7] += dp[i][7];

    }

    cout << dp[N][7] % mod << endl;

    return 0;
}
