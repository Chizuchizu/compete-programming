#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        char s[1001];
        cin >> s;
        if (s[0] == '0') {
            break;
        }

        int ans = 0;
        for (char x: s) {
            ans += x - '0';
        }

        cout << ans << endl;
    }

    return 0;
}
