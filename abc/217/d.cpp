#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int q;
    cin >> q;
    priority_queue<int,vector<int>, greater<int>> que;
    // queue<int> que
    queue<int> memo;
    rep(i, q) {
        int query;
        cin >> query;

        if (query == 1) {
            int x;
            cin >> x;
            memo.push(x);
        } else if (query == 2) {
            int x;
            if (que.empty()) {
                x = memo.front();
                memo.pop();
                cout << x << endl;
            } else {
                int x;
                x = que.top();
                que.pop();
                cout << x << endl;
                // que.erase(que.begin());
            }
        } else {

            while (!memo.empty()) {
                int x;
                x = memo.front();
                memo.pop();
                que.push(x);
            }
        }
    }

    return 0;
}
