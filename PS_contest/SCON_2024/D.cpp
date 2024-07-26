#include<bits/stdc++.h>
using namespace std;

int asd(int a, int b, int c) {
    if (b == 1 && c == a)  return 0;
    if (c == 1 && b == a) return 0;
    if (b + 1 == c) return 1;
    if (c + 1 == b) return 1;
    if (b == 1) return 1;
    if (b == a) return 1;
    return 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >>t ;
    while(t--) {
        int a, b, c; cin >> a >> b >> c;
        cout << asd(a, b, c) << '\n';
    }
}