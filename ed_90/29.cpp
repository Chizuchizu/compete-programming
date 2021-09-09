#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int W, N;
    cin >> W >> N;

    vector<int> L(N), R(N);

    rep(i, N){
        cin >> L[i] >> R[i];
        L[i]--;
    }

    vector<int> compression;
    rep(i, N){
        compression.push_back(L[i]);
        compression.push_back(R[i]);
    }

    sort(compression.begin(), compression.end());
    compression.erase(unique(compression.begin(), compression.end()), compression.end());

    rep(i, N){
        L[i] = lower_bound(compression.begin(), compression.end(), L[i]) - compression.begin();
        R[i] = lower_bound(compression.begin(), compression.end(), R[i]) - compression.begin();
    }
    vector<int> h(compression.size() - 1, 0);  // 初期値は0
    rep(i, N){
        int height = *max_element(h.begin() + L[i], h.begin() + R[i]) + 1;
        fill(h.begin() + L[i], h.begin() + R[i], height);
        cout << height << "\n";
    }


    return 0;
}
