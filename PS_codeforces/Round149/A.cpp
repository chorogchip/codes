#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
//#define x first
#define y second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int x, k; cin >> x >> k;
        if (x % k != 0) {
            cout << 1 << '\n' << x << '\n';
        } else {
            cout << 2 << '\n' << x-1 << ' ' << 1 << '\n';
        }
    }
}
