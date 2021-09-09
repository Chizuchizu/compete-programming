#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N][N];

    rep(i, N) {
        rep(j, N) {
            cin >> A[i][j];
        }
    }

    int M;
    cin >> M;
    bool bad[N][N];
    rep(i, N) rep(j, N)bad[i][j] = false;
    // fill(bad, bad + sizeof(bad), false);
    rep(i, M) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        bad[x][y] = true;
        bad[y][x] = true;
    }

    int Answer = 1 << 30;

    vector<int> P(N, 0);
    rep(i, N) P[i] = i;

    do {
        int sum = 0;
        rep(i, N) {
            // 区間iをP[i]さんが走る
            sum += A[P[i]][i];
            if (i < N - 1) {
                if (bad[P[i]][P[i + 1]]) {
                    // cout << P[i] << " " << P[i + 1] << " ";
                    sum = 1 << 30;
                }
            }
        }
        // rep(i, N) sum += A[P[i]][i];
        Answer = min(Answer, sum);
        //cout << sum << endl;
    } while (next_permutation(P.begin(), P.end()));

    if (Answer == 1 << 30) Answer = -1;

    cout << Answer << endl;

    return 0;
}
