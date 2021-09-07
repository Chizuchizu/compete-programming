#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

using namespace std;


template<class T>T tosa_sum(T a, T d, ll n) {
    return (a * 2 + d * (n - 1)) * n / 2;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (ll &a: A) {
        cin >> a;
    }

    A.push_back(0);

    sort(A.begin(), A.end(), greater<ll>());

    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        ll diff = A[i] - A[i + 1];
        ll cnt = 1LL * diff * (i + 1);
        if (cnt <= k) {
            k -= cnt;
            ans += tosa_sum(A[i], -1LL, diff) * (i + 1);
            //ans += (diff * A[i] - (diff - 1) * diff / 2) * (i + 1);
        } else {
            ll d = k / (i + 1);
            ll m = k % (i + 1);
            // cout << d << " " << m << endl;
            ans += tosa_sum(A[i], -1LL, d) * (i + 1);
            // cout << ans << endl;
            // ans += (diff * A[i] - (diff - 1 + d) * (diff - d) / 2) * (i + 1);
            ans += (A[i] - d) * m;
            k = 0;
            break;
        }
        // cout << ans  << " " << k  << endl;
    }

    cout << ans << endl;

    return 0;
}
