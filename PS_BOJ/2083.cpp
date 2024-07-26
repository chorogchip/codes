#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(true) {
        string s; int a, b; cin >> s >> a >> b;
        if (s == "#") break;
        cout << s << ' ' << (a > 17 || b >= 80 ? "Senior\n" : "Junior\n");
    }
}