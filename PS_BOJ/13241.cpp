#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcdd(ll a, ll b) {
    if (b == 0) return a;
    return gcdd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll a, b; cin >> a >> b;
    cout << a / gcdd(a, b) * b;
}