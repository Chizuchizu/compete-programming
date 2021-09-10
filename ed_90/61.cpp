#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int Q;
    cin >> Q;

    deque<int> que;

    rep(i, Q) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            que.push_front(x);
        } else if (t == 2) {
            que.push_back(x);
        } else {
            cout << que[x-1] << endl;
        }
    }

    return 0;
}
