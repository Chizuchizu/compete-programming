#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    long long diff_s = 0;

    //vector<int> A(N), B(N);
    int A[N], B[N];

    for (int &a: A) {
        cin >> a;
    }
    for (int &b: B) {
        cin >> b;
    }

    rep(i, N) {
        diff_s += abs(A[i] - B[i]);
    }

    if ((diff_s <= K) && ((diff_s - K) % 2 == 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }



    return 0;
}
