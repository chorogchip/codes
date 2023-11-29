#include<bits/stdc++.h>
using namespace std;

int s[301010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    string str; cin >> str;
    for (int p = 1; p < n; ++p) {
        s[p] = s[p-1];
        if (str[p-1] == str[p]) s[p]++;
    }
    for (int i = 1; i <= q; ++i) {
        int l, r; cin >> l >> r;
        cout << s[r - 1] - s[l - 1] << '\n';
    }

}