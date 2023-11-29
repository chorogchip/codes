#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    string cf = "codeforces";
    while (tc--) {
        string st; cin >> st;
        int res = 0;
        for (int i = 0; i < 10; ++i)
            if (cf[i] != st[i]) ++res;
        cout << res << '\n';
    }
}
