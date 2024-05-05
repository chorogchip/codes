#include<bits/stdc++.h>
using namespace std;

int d[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    int cur = 0, cnt = 0;
    for (int i = n; i > 0; --i) if (d[i] > cur) ++cnt, cur = d[i];
    cout << cnt;
}