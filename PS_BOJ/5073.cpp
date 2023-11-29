#include<bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a + b <= c) cout << "Invalid\n";
        else if (a == b && b == c) cout << "Equilateral\n";
        else if (a == b || b == c || c == a) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }
}