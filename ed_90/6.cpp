#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int nex[100009][26];


int main() {
    int N, K;

    string S;
    cin >> N >> K;
    cin >> S;

    // nex[i][j] はi文字目の右にある文字jの中で最も左側にあるもののindex


    // Step #2. 前計算
    rep(i, 26) {
        nex[N][i] = N;
    }
    for (int i = (int)S.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if ((int)(S[i] - 'a') == j) {
                nex[i][j] = i;
            }
            else {
                nex[i][j] = nex[i + 1][j];
            }
        }
    }

    // Step #3. 一文字ずつ貪欲に決める
    string answer = "";
    int CurrentPos = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 26; j++) {
            int NexPos = nex[CurrentPos][j];  // 現在の位置の文字から右にある文字jのindex
            int MaxPossibleLength = (int)(S.size() - NexPos + i);
            int a = 9;
            if (MaxPossibleLength >= K) {
                answer += (char)('a' + j);
                CurrentPos = NexPos + 1;
                // i番目の答えが見つかったら次に進む
                break;
            }
        }
    }

    cout << answer << endl;

    return 0;
}
