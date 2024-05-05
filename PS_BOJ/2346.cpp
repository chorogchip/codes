#include<bits/stdc++.h>
using namespace std;

int d[1024];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> d[i];
    int cur = 0, curn = n;
    for (int i = 1; i < n; ++i) {
        cout << cur+1 << ' ';
        int num = d[cur]; d[cur] = 0; --curn;
        if (num > 0) {
            num %= curn;
            if (num == 0) num = -1;
        } else {
            num = -(-num % curn);
            if (num == 0) num = 1;
        }
        if (num > 0) while (num) { ++cur; if (cur == n) cur = 0; if (d[cur]) --num; }
        else while (num) {--cur; if (cur == -1) cur = n-1; if (d[cur]) ++num; }
    }
    cout << cur+1 << ' ';
}