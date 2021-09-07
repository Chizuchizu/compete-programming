#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    double r;
    cin >> r;

    double ans1, ans2;
    ans1 = r * r * M_PI;
    ans2 = 2 * r * M_PI;
    cout << fixed << setprecision(15) << ans1 << " " << ans2 << endl;


    return 0;
}
