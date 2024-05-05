#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while(n--) {
        int a = 0, b = 0;
        for (int i = 0; i < 9; ++i) {
            int aa, bb; cin >> aa >> bb;
            a += aa; b += bb;
        }
        if (a == b) cout << "Draw\n";
        else if (a > b) cout << "Yonsei\n";
        else cout << "Korea\n";
    }
}