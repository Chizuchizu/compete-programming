#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int a, b, c, ans;
    cin >> a >> b >> c;
    ans = 0;
    for (int i = a; i <= b; i++){
        if (c % i == 0){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
