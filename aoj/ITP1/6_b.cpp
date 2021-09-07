#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> mark;
    mark["S"] = 0;
    mark["H"] = 1;
    mark["C"] = 2;
    mark["D"] = 3;

    map<int, string> re_mark;
    re_mark[0] = "S";
    re_mark[1] = "H";
    re_mark[2] = "C";
    re_mark[3] = "D";


    bool card[4][13];
    fill_n(card, sizeof(bool) * 4 * 13, false);

    for (int i = 0; i < n; i++) {
        string x;
        int y;

        cin >> x >> y;
        card[mark[x]][y - 1] = true;

    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            if (card[i][j]) {
                continue;
            } else {
                cout << re_mark[i] << " " << j + 1 << endl;
            }
        }
    }


    return 0;
}
