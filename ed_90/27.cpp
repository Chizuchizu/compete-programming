#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

set<string> name;

int main() {
    int N;
    cin >> N;

    rep(i, N){
        string s;
        cin >> s;
        auto before_size = name.size();
        name.insert(s);
        if (name.size() == before_size) {
            continue;
        } else {
            cout << i + 1 << endl;
        }
    }

    return 0;
}
