#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << n/25 << ' '; n%=25;
        cout << n/10 << ' '; n%=10;
        cout << n/ 5 << ' '; n%= 5;
        cout << n/ 1 << ' '; n%= 1;
        cout << '\n';
    }
}