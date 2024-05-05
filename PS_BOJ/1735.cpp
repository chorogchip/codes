#include<bits/stdc++.h>
using namespace std;

int gcdd(int a, int b) {
    if (b == 0) return a;
    return gcdd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b, c, d; cin >> a >> b >> c >> d;
    int m = a * d + b * c;
    int M = b * d;
    int g = gcdd(m, M);
    cout << m/g << ' ' << M/g;
}