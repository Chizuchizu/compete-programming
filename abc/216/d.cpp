#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    queue<int> que;
    vector<queue<int>> A(M);
    vector<vector<int>> mem(N);

    // A[i] | 筒iに入っているボール(queue)
    // mem[i][j] | ボールiが筒jに入っているという意味

    rep(i, M) {
        int k;
        cin >> k;
        rep(j, k) {
            int a;
            cin >> a;
            A[i].push(a-1);
        }
        mem[A[i].front()].push_back(i);  //  mem[i][j] | ボールiは筒jに入っている
    }

    rep(i, N) {
        if (mem[i].size() == 2) {
            que.push(i);  // 大きさが2ならば捨てられるのでqueueに追加
        }
    }
    // ボールは2個ずつ入っているからmemをクリアする必要がない

    while (!que.empty()) {  // queueがなくなるまで
        int now = que.front();
        que.pop();

        for (auto p: mem[now]) {  // ボールが2つ入っている筒
            A[p].pop();  // 筒pのボールをpop
            if (!A[p].empty()) {  //  まだボールが残っていれば
                mem[A[p].front()].push_back(p);  // キューにボールを追加
                if (mem[A[p].front()].size() == 2) {  // もし筒の大きさが2であればqueueに追加
                    que.push(A[p].front());
                }
            }
        }
    }

    for (auto p: A) {
        if (!p.empty()) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
