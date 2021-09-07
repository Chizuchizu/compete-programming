#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int n;
    cin >> n;


    if (n % 2 == 1) {
        cout << endl;
    } else {
        for (int bit = (1 << n); bit >= 0; bit--) {
            vector<int> kakko;  // (が0 )が1

            int left_ = 0;
            int right_ = 0;
            int flag = 1;

            for (int i = n - 1; i >= 0; i--) {
                if (bit & (1 << i)) {
                    left_++;
                    kakko.push_back(1);
                } else {
                    right_++;
                    kakko.push_back(0);
                }

                if (left_ - right_ < 0) {
                    flag = 0;
                }
            }
            if (left_ != right_) {
                flag = 0;
            }

            if (flag) {

                for (int x: kakko) {
                    if (x == 1) {
                        cout << "(";
                    } else {
                        cout << ")";
                    }
                    // cout << x;
                }
                cout << endl;
            }

        }
    }

    return 0;
}
