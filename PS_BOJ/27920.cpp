#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    cout << "YES\n";
    for (int i = n & 1 ? n : n - 1; i >= 1; i -= 2)
        cout << i << ' ';
    for (int i = 2; i <= n; i += 2)
        cout << i << ' ';
    cout << '\n';
    for (int i = n + 1 >> 1, j = i + 1;;) {
        if (i <= 0) break;
        cout << i-- << ' ';
        if (j > n) break;
        cout << j++ << ' ';
    }
}