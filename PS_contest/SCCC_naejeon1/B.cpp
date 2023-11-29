#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, d; cin >> n >> d;
    if (n & 1) {
        // 홀수
        int l = n >> 1;
        for (int st = d - l; st <= d + l; ++st)
            cout << st << ' ';
    } else {
        // 짝수
        int l = n >> 1;
        for (int st = d - l; st < d; ++st)
            cout << st << ' ';
        for (int st = d + 1; st <= d + l; ++st)
            cout << st << ' ';
    }
}