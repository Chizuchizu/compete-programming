#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

long long gcd(long long x, long long y) {
    while ((x != 0) && (y != 0)) {
        if (x >= y) {
            x %= y;
        } else {
            y %= x;
        }
    }
    return x + y;
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    long long R;
    R = gcd(A, B);
    R = gcd(R, C);

    long long ans = 0;

    ans += A / R - 1;
    ans += B / R - 1;
    ans += C / R - 1;
    cout << ans << endl;

    return 0;
}
