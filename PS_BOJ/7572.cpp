#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    n %= 60;
    int a = (n % 12 + 8) % 12;
    int b = (n % 10 + 6) % 10;
    cout << (char)('A'+a) << b;
}