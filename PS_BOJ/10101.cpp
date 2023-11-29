#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);

    if (a + b + c != 180) {
        cout << "Error";
        return 0;
    } else if (a == b && b == c) {
        cout << "Equilateral";
        return 0;
    } else if (a == b || b == c || c == a) {
        cout << "Isosceles";
        return 0;
    } else {
        cout << "Scalene";
        return 0;
    }
}