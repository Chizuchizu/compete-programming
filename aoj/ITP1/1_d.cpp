#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int s;
    cin >> s;
    int h, m, sec;
    h = s / 3600;
    s %= 3600;
    m = s / 60;
    s %= 60;
    sec = s;

    cout << h << ":" << m << ":" << sec << endl;

    return 0;
}
