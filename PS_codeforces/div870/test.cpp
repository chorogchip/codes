#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    while(1) {
        int a, b; cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
}