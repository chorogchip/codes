#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        int i;
        for (i = 2; i < n; ++i) {
            if (n % i) break;
        }
        string res;
        res.reserve(n);
        char c = 'a', itv = 'a' + i;
        for (int i = 0; i < n; ++i) {
            res += c;
            c++;
            if (c == itv) c = 'a';
        }
        res += '\n';
        cout << res;
    }
}
