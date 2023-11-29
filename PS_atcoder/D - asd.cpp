#include <bits/stdc++.h>
using namespace std;
using ll =  long long;

int s[64], t[64];

ll cal(bool is_equal, int i) {
    if (i == -1) return 0;
    if (s[i] == 0) {
        if (t[i] == 0) {
            return cal(is_equal, i-1);
        } else {
            return cal(0, i-1);
        }
    } else if (s[i] == 1) {
        if (t[i] == 0) {
            if (!is_equal) return cal(0, i-1) | 1LL << i;
            else return -1;
        } else {
            return cal(is_equal, i-1) | 1LL << i;
        }
    } else {
        if (t[i] == 0) {
            if (is_equal) return cal(is_equal, i-1);
            else return cal(0, i-1) | 1LL << i;
        } else {
            if (is_equal) {
                ll res = cal(1, i-1);
                if (res != -1) return res | 1LL << i;
                else return cal(0, i-1);
            }
            else return cal(0, i-1) | 1LL << i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str; ll n; cin >> str >> n;
    for (int i = str.size() - 1, j = 0; i >= 0; --i, ++j) {
        if (str[i] == '0') s[j] = 0;
        else if (str[i] == '1') s[j] = 1;
        else s[j] = 2;
    }
    for (int j = 0; n; ++j) {
        t[j] = n & 1;
        n >>= 1;
    }
    cout << cal(1, 63);
}