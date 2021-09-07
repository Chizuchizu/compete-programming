#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int w, h;
    while (true) {
        cin >> h >> w;
        if ((w == 0) && (h == 0)) {
            break;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if ((i == 0) || (j == 0) || (i == h - 1) || (j == w - 1)) {
                    cout << "#";
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
