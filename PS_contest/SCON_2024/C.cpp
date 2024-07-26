#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string too(ll i) {
    string res = "";
    do res += (char)('0'+i%10LL); while (i/=10LL);
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string as, bs;
    for (int i = 1; i <= n; ++i) {
        ll a; cin >> a;
        as += too(a);
    }
    for (int i = 1; i <= n; ++i) {
        ll a; cin >> a;
        bs += too(a);
    }
    if (as.size() != bs.size()) {
        if (as.size() > bs.size()) goto A;
        else goto B;
    } else {
        int sz = as.size();
        for (int i = 0; i < sz; ++i) {
            if (as[i] != bs[i]) {
                if (as[i] > bs[i]) goto A;
                else goto B;
            }
        }
    }

    A: cout << bs; exit(0);
    B: cout << as; exit(0);
}