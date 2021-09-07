#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int ans1, ans2;
    double ans3;

    ans1 = x / y;
    ans2 = x % y;
    ans3 = 1.0 * x / y;

    cout << ans1 << " " << ans2 << " " << fixed << setprecision(15) << ans3;

    return 0;
}
