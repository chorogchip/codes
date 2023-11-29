#include<iostream>
using namespace std;

int count2(long long n) {
    int res = 0;
    for (long long i = 2; i <= n; i <<= 1)
        res += n / i;
    return res;
}
int count5(long long n) {
    int res = 0;
    for (long long i = 5; i <= n; i *= 5)
        res += n / i;
    return res;
}

int main() {
    int n, m, r2, r5;
    cin >> n >> m;
    r2 = count2(n) - count2(m) - count2(n-m);
    r5 = count5(n) - count5(m) - count5(n-m);
    cout << min(r2, r5) << endl;
    return 0;
}
