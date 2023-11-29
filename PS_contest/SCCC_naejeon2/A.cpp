#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int h, l, a, b; cin >> h >> l >> a >> b;
    h *= 2;
    if (h > l) swap (h, l);
    if (a > b) swap (a, b);
    if (a <= h && b <= l) goto YES;
    else goto NO;


    YES: cout << "YES"; return 0;
    NO: cout << "NO"; return 0;
}