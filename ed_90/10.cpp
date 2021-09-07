#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int N, Q;
    cin >> N;

    vector<int> A(N + 1, 0);
    vector<int> B(N + 1, 0);

    rep(i, N) {
        int c, p;
        cin >> c >> p;
        if (c == 1) {
            A[i + 1] = p + A[i];
            B[i + 1] = B[i];
        } else {
            B[i + 1] = p + B[i];
            A[i + 1] = A[i];
        }
    }

    cin >> Q;

    rep(i, Q) {
        int l, r;
        cin >> l >> r;

        cout << A[r] - A[l - 1] << " " << B[r] - B[l - 1] << endl;
    }


    return 0;
}
