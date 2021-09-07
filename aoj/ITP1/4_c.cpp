#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    string c;
    while (true) {
        cin >> a >> c >> b;


        if (c == "+") {
            cout << a + b << endl;
        } else if (c == "-") {
            cout << a - b << endl;
        } else if (c == "*") {
            cout << a * b << endl;
        } else if (c == "/") {
            cout << a / b << endl;
        } else {
            break;
        }
    }

    return 0;
}
