#include <bits/stdc++.h>
using namespace std;

int n, x, a[51], b[51];
bool asdf[2][10001];

int main(void) {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    asdf[1][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) if (asdf[i&1][j])
            for (int k = 0; k <= b[i] && j + a[i] * k <= x; ++k)
                asdf[(i+1)&1][j+a[i]*k] = true;
    }
    if (asdf[(n+1)&1][x]) cout << "Yes";
    else cout << "No";
}