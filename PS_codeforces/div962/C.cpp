#include<bits/stdc++.h>
using namespace std;

int A[201010][26], B[201010][26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;
        string a, b; cin >> a >> b;
        a = "#" + a; b = "#" + b;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                A[i][j] = A[i-1][j];
                B[i][j] = B[i-1][j];
            }
            A[i][a[i]-'a']++;
            B[i][b[i]-'a']++;
        }
        while(q--) {
            int l, r; cin >> l >> r;
            int gap = 0;
            for (int j = 0; j < 26; ++j) {
                gap += abs((A[r][j] - A[l-1][j]) - (B[r][j] - B[l-1][j]));
            }
            gap >>= 1;
            cout << gap << '\n';
        }
    }
}