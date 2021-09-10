#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

const int INF = 110000;
int memo[INF];

int rec(int n) {
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];

    int res = n;

    for (int pow6 = 1; pow6 <= n; pow6 *= 6) {
        res = min(res, rec(n - pow6) + 1);
    }
    for (int pow9 = 1; pow9 <= n; pow9 *= 9) {
        res = min(res, rec(n - pow9) + 1);
    }
    return memo[n] = res;
}

int main() {
    int N;
    cin >> N;
    fill(memo, memo + INF, -1);

    cout << rec(N) << endl;

    return 0;
}
