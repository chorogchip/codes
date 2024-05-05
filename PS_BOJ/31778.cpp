#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    string str; cin >> str;
    int a = 0, b = n-1;
    while(k--) {
        while (a < n && str[a] == 'P') ++a;
        if (a == n) break;
        while(b >= 0 && str[b] == 'C') --b;
        if (b == -1) break;
        if (a >= b) break;
        swap(str[a++], str[b--]);
    }
    ll pc = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'P') ++pc;
        else res += pc * (pc-1) >> 1;
    }
    cout << res;
}