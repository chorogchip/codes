#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

int n;
bool b[401010];

void sieve() {
    b[0] = b[1] = 1;
    for (ll i = 4; i < sizeof(b); i += 2) b[i] = 1;
    for (ll i = 3; i < sizeof(b); i += 2) if (!b[i]) {
        for (ll j = i * i; j < sizeof(b); j += i) b[j] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve();
    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> vp, vnp;
        for (int i = 1; i <= n; ++i)
            if (!b[i]) vp.push_back(i);
            else vnp.push_back(-i);
        sort(vp.begin(), vp.end());
        sort(vnp.begin(), vnp.end());
        vector<int> st, ed;
        int sz = vp.size();
        for (int i = 0; i < sz; ++i) {
            st.push_back(vp[i]);
            ++i;
            if (i >= sz) break;
            ed.push_back(vp[i]);
        }
        int sz2 = vnp.size();
        for (int i = 0; i < sz2; ++i) {
            ed.push_back(-vnp[i]);
            ++i;
            if (i >= sz2) break;
            st.push_back(-vnp[i]);
        }
        for (auto o : st) cout << o << ' ';
        for (int i = ed.size() - 1; i >= 0; --i) cout << ed[i] << ' ';
        cout << '\n';

    }
}
