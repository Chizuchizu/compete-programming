#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    int yoko = (W + 1) / 2;
    int tate = (H + 1) / 2;
    if (H == 1 || W == 1) cout << H * W << endl;
    else cout << yoko * tate << endl;


    return 0;
}
