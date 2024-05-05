#include<iostream>
using namespace std;

constexpr int CNT = 101010;
int r[CNT], a[CNT], s[CNT], t[CNT];

int main() {
    while (true) {
        cin >> r[0] >> r[1];
        s[0] = 1;
        s[1] = 0;
        t[0] = 0;
        t[1] = 1;
        int i = 0;
        for (; i < CNT - 2 && r[i+1]; ++i) {
            a[i] = r[i] / r[i+1];
            r[i+2] = r[i] % r[i+1];
            s[i+2] = s[i] - a[i] * s[i+1];
            t[i+2] = t[i] - a[i] * t[i+1];
        }
        for (int j = 0; j <= i+1; ++j) {
            cout << r[j] << ' ' << a[j] << ' ' << s[j] << ' ' << t[j] << endl;
        }
    }
}