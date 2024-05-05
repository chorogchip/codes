#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a = 100, b = 100;
    for (int i = 0; i < n; ++i) {
        int aa, bb; cin >> aa >> bb;
        if (aa > bb) b -= aa;
        else if (aa < bb) a -= bb;
    }
    cout << a << '\n' << b;
}