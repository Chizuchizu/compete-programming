#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] = x;
    }
    // reverse(a, a+n);
    for (int i = n - 1; i >= 0; i--){
        cout << a[i];
        if (i != 0){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
