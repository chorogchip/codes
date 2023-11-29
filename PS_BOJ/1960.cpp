#include<bits/stdc++.h>
using namespace std;

bool ans[512][512];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int j = 0; x && j < n; ++j)
            if (b[j]) --b[j], --x, ans[i][j] = 1;
        if (x) goto NO;
    }
    for (int i = 0; i < n; ++i) if (b[i]) goto NO;

    cout << 1 << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << (int)ans[i][j];
        cout << '\n';
    }

    return 0;
    NO: cout << -1;
}
