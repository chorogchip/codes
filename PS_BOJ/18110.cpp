#include<bits/stdc++.h>
using namespace std;

int d[5'00000];

int main() {
    int n; cin >> n;
    if (n == 0) { cout << 0; exit(0); }
    for (int i = 0; i < n; ++i) cin >> d[i];
    sort(d, d + n);
    int asd = (3 * n + 10) / 20;
    int sum = 0;
    for (int i = asd; i < n - asd; ++i) sum += d[i];
    int cnt = n - asd * 2;
    int res = (sum + cnt/2) / (cnt);
    cout << res;
}