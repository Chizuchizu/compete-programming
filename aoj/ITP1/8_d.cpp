#include <iostream>
#include <vector>
#include <cmath>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int n, m, l;
    cin >> n >> m >> l;

    long long  a[100][100] = {{}};
    long long  b[100][100] = {{}};
    //int c[100][100] = {{}};

    rep(i, n) {
        rep(j, m) {
            int t;
            cin >> t;
            a[i][j] = t;
        }
    }

    rep(i, m) {
        rep(j, l) {
            int t;
            cin >> t;
            b[i][j] = t;
        }
    }

    rep(i, n) {
        rep(j, l) {
            long long t = 0;
            rep(k, m) {
                t += a[i][k] * b[k][j];
            }
            //c[i][j] = t;

            cout << t;
            if (j != l-1){
                cout << " ";
            }
        }
        cout << endl;
    }


    return 0;
}
