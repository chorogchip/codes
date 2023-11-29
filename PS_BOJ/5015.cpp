#include<bits/stdc++.h>
using namespace std;

string pat;
int patlen;
string str;
int len;
unsigned char dp[128][128];

unsigned char match(int st, int tar) {
    if (dp[st][tar]) return dp[st][tar];
    if (st == len && tar == patlen) return dp[st][tar] = 1;
    if (tar == patlen) return dp[st][tar] = 2;
    if (st == len)
        if (pat[tar] == '*') return dp[st][tar] = match(st, tar + 1);
        else return dp[st][tar] = 2;
    //cout << st << str[st] << ' ' << tar << pat[tar] << '\n';
    if (pat[tar] != '*') {
        if (str[st] != pat[tar]) return dp[st][tar] = 2;
        return dp[st][tar] = match(st + 1, tar + 1);
    } else {
        for (int k = st; k <= len; ++k)
            if (match(k, tar + 1) & 1) return dp[st][tar] = 1;
        return dp[st][tar] = 2;
    }

}

int main() {
    cin >> pat;
    patlen = pat.size();
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        len = str.size();
        if (match(0, 0) & 1) cout << str << '\n';
        memset(dp, 0, sizeof(dp));
    }
}