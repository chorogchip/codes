#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int s, n; cin >> s >> n;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        s -= a * b;
    }
    if (s == 0) cout << "Yes"; else cout << "No";
}