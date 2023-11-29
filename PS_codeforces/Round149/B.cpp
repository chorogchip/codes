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
        int n; string str; cin >> n >> str;
        int maxc = 1;
        int xx = 1;
        for (int i = 1; i < n; ++i) {
            if (str[i] == str[i-1]) {
                ++xx;
                maxc = max(maxc, xx);
            } else {
                xx = 1;
            }
        }
        cout << maxc + 1 << '\n';
    }
}
