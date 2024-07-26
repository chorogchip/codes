#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int t = 0; t < 3; ++t) {
        int n; cin >> n;
        unsigned long long s = 0;
        int cnt = 0;
        while(n--) {
            long long x; cin >> x;
            unsigned long long xx = x;
            if (x == 0) continue;
            if (x < 0) --cnt;
            if (s + xx < s) ++cnt;
            s += xx;
        }
        if (cnt == 0 && s == 0) cout << "0\n";
        else cout << (cnt>=0 ? "+\n" : "-\n");
    }
}