#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
double pi = 3.141592653589793238;

int main() {
    float n, x_0, y_0, x_n_2, y_n_2;
    cin >> n >> x_0 >> y_0 >> x_n_2 >> y_n_2;

    float x_c, y_c;
    x_c = (x_0 + x_n_2) / 2;
    y_c = (y_0 + y_n_2) / 2;

    float x_n, y_n;
    x_n = x_0 - x_c;
    y_n = y_0 - y_c;

    float theta, x_1, y_1;
    theta = 360 / n / 180.0 * pi;

    x_1 = x_n * cos(theta) - y_n * sin(theta) + x_c;
    y_1 = x_n * sin(theta) + y_n * cos(theta) + y_c;


    cout << x_1 << " " << y_1 << endl;

    return 0;
}
