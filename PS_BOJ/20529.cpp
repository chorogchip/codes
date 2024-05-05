#include<bits/stdc++.h>
using namespace std;

int dist(int a, int b) {
    int xx = a ^ b;
    return __builtin_popcount((unsigned)xx);
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int k[16];
        memset(k, 0, sizeof(k));
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            int x = 0;
            if (s[0] == 'I') x |= 1;
            if (s[1] == 'N') x |= 2;
            if (s[2] == 'T') x |= 4;
            if (s[3] == 'P') x |= 8;
            k[x] += 1;
        }
        int res = 12341234;
        for (int i = 0; i < 16; ++i) if (k[i]) {
            k[i]--;
            for (int j = 0; j < 16; ++j) if (k[j]) {
                k[j]--;
                for (int l = 0; l < 16; ++l) if (k[l]) {
                    res = min(res, dist(i, j) + dist(j, l) + dist(l, i));
                }
                k[j]++;
            }
            k[i]++;
        }
        cout << res << '\n';
    }
}