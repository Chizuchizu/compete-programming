#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
long long n, l, k;
vector<long long int> A;


// index が条件を満たすかどうか
bool isOK(long long index) {
    long long bnkt = 0;
    long long tmp = 0;
    // long long last = 0;
    rep(i, n+1) {
        tmp += A[i + 1] - A[i];
        //cout << i << " " << tmp << " " << bnkt << endl;
        if ((tmp >= index) && (i != n) && (bnkt < k)) {
            tmp = 0;
            bnkt++;
        }else if ((i == n) && (tmp < index)){
            //cout << tmp << endl;
            bnkt = -1;
        }
    }
    //cout << bnkt << " " << index  << " " << (bool)(bnkt >= k + 1 )<< endl;

    if (bnkt < k) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
long long binary_search() {
    long long ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    long long ok = l + 1; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;

        if (isOK(mid)) ok = mid;
        else ng = mid;
        //cout << ng << " " << ok << endl;
        //cout << "--" << endl;
    }
    return ng;
}

int main() {
    cin >> n >> l >> k;

    A.resize(n);

    for (long long &a : A) {
        cin >> a;
    }
    A.insert(A.begin(), 0);
    A.push_back(l);


    cout << binary_search() << endl;

    return 0;
}
