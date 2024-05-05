#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int a[6] = {0, };
    while(n--) {
        int s, g; cin >> s >> g;
        a[s | (g-1&6)]++;
    }
    int cnt = 0;
    cnt += (a[5] + k - 1) / k;
    cnt += (a[4] + k - 1) / k;
    cnt += (a[3] + k - 1) / k;
    cnt += (a[2] + k - 1) / k;
    cnt += (a[1] + a[0] + k - 1) / k;
    cout << cnt;
}