#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int cnt = 0;
    while(n--) {
        int a, b, c; cin >> a >> b >> c;
        if (a == -1) continue;
        if (b == -1) {
            if (c != -1) continue;
        } else {
            if (a > b) continue;
            if (c != -1 && b > c) continue;
        }
        ++cnt;
    }
    cout << cnt;
}