#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int dpa = 0, dpb = 0, dpn = 1;
    for (int i = 1; i <= n; ++i) {
        int s = dpa + dpb;
        dpa += dpn;
        dpb += dpn;
        dpn += s;
        dpa %= 9901;
        dpb %= 9901;
        dpn %= 9901;
    }
    cout << (dpa + dpb + dpn) % 9901;

}