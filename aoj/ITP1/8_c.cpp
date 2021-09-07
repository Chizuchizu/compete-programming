#include <iostream>
#include <vector>
#include <cmath>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int r, c;
    int sheet[101][101] = {{}};

    cin >> r >> c;

    rep(i, r) {
        int sum = 0;
        rep(j, c) {
            int x;
            cin >> x;
            sheet[i][j] = x;

            sum += x;
        }
        sheet[i][c] = sum;
    }

    rep(j, c + 1){
        int sum = 0;
        rep(i, r){
            sum += sheet[i][j];
        }
        sheet[r][j] = sum;
    }

    rep(i, r+1){
        rep(j, c+1){
            cout << sheet[i][j];

            if (j != c){
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
