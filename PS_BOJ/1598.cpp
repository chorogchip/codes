#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b; cin >> a >> b; a--; b--;
    cout << abs(a/4 - b/4) + abs(a%4 - b%4);
}