#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long d;
    d = 1;
    for(int i = 1; i <= b; i++) {
        d *= c;
    }
    // cout << a << " " << d << endl;
    if (a < d) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}