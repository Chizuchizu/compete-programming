#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

vector<int> B;

// index が条件を満たすかどうか
bool isOK(int index, int key) {
    auto num_idx = B.end() - lower_bound(B.begin(), B.end(), index);
    // cout << index << " " << key << " " << num_idx << endl;


    if (num_idx <= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key) {
    int ng = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int) B[B.end() - B.begin() - 1]; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int &a: A) {
        cin >> a;
    }

    for (int a: A) {
        rep(i, a) {
            B.push_back(i + 1);
        }
    }
    sort(B.begin(), B.end());

    int ans_idx;
    ans_idx = binary_search(k);

    int num_idx = lower_bound(B.begin(), B.end(), ans_idx) - B.begin();
    int ans = 0;
    for (int i = num_idx; i < B.size(); i++) {
        ans += B[i];
    }
    //cout << num_idx << endl;
    //cout << (B.size() - num_idx) << " " << k << endl;

    if (num_idx == 0) {
        cout << ans << endl;
        return 0;
    }

    int i = num_idx - 1;
    int cnt = 1;
    while ((B.size() - num_idx) + cnt <= k) {
        if (B[i] > 0) {
            ans += B[i];
        } else {
            break;
        }
        i--;
        cnt++;
    }
    cout << ans << endl;

    return 0;
}
