#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int N, M[3];
    cin >> N >> M[0] >> M[1] >> M[2];

    sort(M, M + 3, greater<int>());

    int memo;
    int cnt[3] = {9999, 9999, 9999};

    rep(i, N / M[0] + 1) {
        int next_max = (N - i * M[0]) / M[1];
        rep(j, next_max + 1) {
            memo = i * M[0] + j * M[1];
//            cout << i << " " << j << " " << endl;
            if ((N - memo) % M[2] == 0) {
                if (i + j + (N - memo) / M[2] < cnt[0] + cnt[1] + cnt[2]) {
                    cnt[0] = i;
                    cnt[1] = j;
                    cnt[2] = (N - memo) / M[2];
                }

            }
        }
    }

    cout << cnt[0] + cnt[1] + cnt[2] << endl;

    return 0;
}
