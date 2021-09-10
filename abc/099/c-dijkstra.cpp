#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

template<class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

typedef pair<int, int> P;

const int INF = 110000;
int dp[INF];

int main() {
    int N;
    cin >> N;
    fill(dp, dp + INF, INF);

    dp[0] = 0;

    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, 0));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (dp[v] < p.first) continue;  // 枝刈り?

        for (int pow6 = 1; v + pow6 <= N; pow6 *= 6) {
            if (chmin(dp[v+pow6], dp[v] + 1)) {
                que.push(P(dp[v + pow6], v + pow6));
            }

//            if (dp[v + pow6] > dp[v] + 1) {
//                dp[v + pow6] = dp[v] + 1;
//                que.push(P(dp[v + pow6], v + pow6));
//            }
        }
        for (int pow9 = 1; v + pow9 <= N; pow9 *= 9) {

            if (chmin(dp[v+pow9], dp[v] + 1)) {
                que.push(P(dp[v + pow9], v + pow9));
            }

//            if (dp[v + pow9] > dp[v] + 1) {
//                dp[v + pow9] = dp[v] + 1;
//                que.push(P(dp[v + pow9], v + pow9));
//            }
        }
    }

    cout << dp[N] << endl;

    return 0;
}
