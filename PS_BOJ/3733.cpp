#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(true) {
        int a, b;
        if (!(cin >> a)) break;
        cin >> b;
        cout << b / (a+1) << '\n';
    }
}