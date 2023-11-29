#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int cur = 0, togi = 0;
    vector<int> a(n);
    queue<int> b;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (auto o : a) {
        while (true) {
            if (!b.empty() && cur == b.front()) b.pop();
            else if (!togi || cur < o - m) ++togi;
            else if (cur < o) {
                --togi, b.push(o);
                ++cur;
                break;
            } else goto F;
            ++cur;
        }
    }
    cout << "success"; return 0;
    F: cout << "fail"; return 0;

}