#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b, c; cin >> a >> b >> c;
    char cc[3] = {a[0], b[0], c[0]};
    sort(cc, cc + 3);
    if (cc[0] == 'k' && cc[1] == 'l' && cc[2] == 'p') cout << "GLOBAL";
    else cout << "PONIX";
}