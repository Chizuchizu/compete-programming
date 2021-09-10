#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

map<int, int> Map;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) {
        cin >> a[i];
    }
    //sort(a.begin(), a.end());

    int max_r = 0;
    int r = 0;
    int cnt = 0;

    rep(i, N) {
        //int local_k = 0;
        while (r < N) {
            if (Map[a[r]] == 0 && cnt == K) break;  // cnt==Kだけでは最大にはならないので不十分
            if (Map[a[r]] == 0) cnt++;  // 新たな種類ならば+1
            Map[a[r]] += 1;  // mapにも要素を追加
            r++;  // 最大indexも追加
        }

        max_r = max(r - i, max_r);

        if (Map[a[i]] == 1) cnt--;  // 1つ移動して種類が減る場合
        Map[a[i]]--;  // remove
    }

    cout << max_r << endl;

    return 0;
}
