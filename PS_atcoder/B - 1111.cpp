#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        int y; cin >> y;
        for (int x = 1; x <= y; ++x) {
            vector<int> v;
            int ii = i; while(ii) v.push_back(ii%10), ii/=10;
            int xx = x; while(xx) v.push_back(xx%10), xx/=10;
            for (int j = 1; j < v.size(); ++j) if (v[0] != v[j]) goto E;
            ++s;
            E:;
        }
    }
    cout << s;
}