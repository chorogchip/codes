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
        for (int i = 1; i <= n; ++i) {
            int xx; cin >> xx;
            cout << n + 1 - xx << ' ';
        }
        cout << '\n';
    }
}
