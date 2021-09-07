#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    // 1始まりは混乱の元
    x--;
    y--;
    vector<string> s(h);
    vector<vector<string>> ss(h, vector<string>(w));

    for (int i = 0; i < h; i++) {
        string st;
        cin >> st;
        for (int j = 0; j < w; j++) {
            ss[i][j] = st[j];
        }
    }

    int result = 1;
    for (int i = x + 1; i < h && ss[i][y] == "."; i++)result++;
    for (int i = x - 1; i >= 0 && ss[i][y] == "."; i--)result++;
    for (int i = y + 1; i < w && ss[x][i] == "."; i++)result++;
    for (int i = y - 1; i >= 0 && ss[x][i] == "."; i--)result++;


    cout << result << endl;

    return 0;
}
