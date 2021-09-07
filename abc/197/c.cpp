#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    int result = pow(2, 30);
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // bit全探索でリストを分割
    for (int bit = 0; bit < (1 << (n - 1)); ++bit) {
        int xor_=0;
        int or_memo = 0;

        // orをとっていく
        for (int i = 0; i < n; i++) {
            or_memo |= a[i];
            // フラグが立ってるかみる
            if (bit & (1 << (i))) {
                // 更新
                xor_ ^= or_memo;
                // 初期化
                or_memo = 0;
            }
        }
        xor_ ^= or_memo;
        // 最小に更新していく
        result = min(xor_, result);
    }

    cout << result << endl;

    return 0;
}
