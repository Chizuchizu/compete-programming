#include <iostream>
#include <vector>
#include <cmath>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


using namespace std;

int main() {
    int n, x;

    while (true) {
        cin >> n >> x;

        if ((n == 0) && (x == 0)) {
            break;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (i + j + k + 3 == x) {
                        ans++;
                    }
                }
            }
        }

        cout << ans << endl;

    }

    return 0;
}
