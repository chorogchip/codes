#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int T, N, R;
string S1, S2;
vector<pair<string,int>> SS1;

int main() { FAST
    cin >> T;
    while (T--) {
        cin >> N;
        R = 1;
        SS1.clear();
        fore (i, N) {
            cin >> S1 >> S2;
            int ss1 = SS1.size();
            for (int i = 0; i != ss1; ++i) if (SS1[i].first == S2) {
                ++(SS1[i].second);
                goto E;
            }
            SS1.push_back(make_pair(S2, 1));
            E:;
        }
        int ss1 = SS1.size();
        for (int i = 0; i != ss1; ++i) R *= SS1[i].second + 1;
        cout << R - 1 << endl;
    }
}
