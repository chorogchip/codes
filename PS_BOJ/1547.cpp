#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int p = 1;
    while(n--) {
        int a, b; cin >> a >> b;
        if (p == a) p = b;
        else if (p == b) p = a;
    }
    cout << p;
}