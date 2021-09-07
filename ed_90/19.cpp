#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long d;
    d = c;
    for(int i = 1; i <= b; b++) {
        d *= i;
    }

    if (a < d) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
