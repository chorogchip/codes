#include<bits/stdc++.h>
using namespace std;

bool dp[1024][1024];

bool asd(int a, int b, int c) {
    if (a == b && b == c) return true;
    if (b<a) swap(a, b);
    if (c<b) swap(b, c);
    if (b<a) swap(a, b);
    if (dp[a][b]) return false;
    dp[a][b] = true;
    bool res = false;
    res |= asd(min(a,b)*2,abs(a-b),c);
    res |= asd(a,min(b,c)*2,abs(c-b));
    res |= asd(min(a,c)*2,b,abs(c-a));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b, c; cin >> a >> b >> c;
    cout << asd(a, b, c);
}