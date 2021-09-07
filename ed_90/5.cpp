#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

long long mod = 1000000007;
long long N, K, B;
long long C[11];

long long dp[100009][33];

int main() {

    cin >> N >> B >> K;

    rep(i, K) {
        cin >> C[i];
    }

    dp[0][0] = 1;
    rep(i, N) {
        rep(j, B) {
            rep(k, K) {
                int nex = (10 * j + C[k]) % B;
                dp[i + 1][nex] += dp[i][j];
                dp[i + 1][nex] %= mod;
            }
        }
    }

    cout << dp[N][0] << endl;
    return 0;
}
