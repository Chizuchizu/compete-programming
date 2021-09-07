#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long arr[n];
    long long  t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        arr[i] = t;
    }
    cout << *min_element(arr, arr + n) << " " << *max_element(arr, arr + n) << " " << accumulate(arr, arr + n, 0LL) << endl;

    return 0;
}
