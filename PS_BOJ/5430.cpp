#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int T, N, D[101010], X;
char CMD[101010], NN[401010], C;
#include<deque>
deque<int> dq;

main() { FAST
    cin >> T;
    fore (i, T) {
        bool isF = true, isE = false;
        dq.clear();
        cin >> CMD >> N >> NN;
        char *p = NN + 1;
        bool toB = true;
        do switch (C = *p++) {
            case ',': dq.push_back(X); X = 0; break;
            case ']': if (dq.size() != N) dq.push_back(X); X = 0; toB = false; break;
            default: X *= 10; X += C - '0';
        } while (toB);
        p = CMD;
        do if (*p == 'D')
            if (isF) if (dq.empty()) { isE = true; break; }
                else dq.pop_front();
            else if (dq.empty()) { isE = true; break; }
                else dq.pop_back();
        else isF = !isF;
        while (*++p);
        if (isE) {
            cout << "error\n";
            isE = false;
        } else {
            cout << "[";
            int S = dq.size();
            if (isF) {
                if (S) cout << dq[0];
                for (int i = 1; i < S; ++i) cout << "," << dq[i];
            } else {
                if (S) cout << dq.back();
                for (int i = S - 2; i >= 0; --i) cout << "," << dq[i];
            }
            cout << "]\n";
        }
    }
}

