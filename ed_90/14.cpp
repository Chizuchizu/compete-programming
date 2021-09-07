#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int N;

    cin >> N;
    vector<int> A(N);
    vector<int> B(N);

    rep(i, N) {
        cin >> A[i];
    }
    rep(i, N) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long ans = 0;
    rep(i, N) {
        ans += abs(A[i] - B[i]);
    }
    cout << ans << endl;

    return 0;
}
