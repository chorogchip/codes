#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b; cin >> a >> b;
    int k = 0, sz = a.size(), c = 0;
    for (auto o : b) {
        if (o == a[k]) {
            ++k;
            if (k == sz) k = 0, ++c;
        }
    }
    cout << c;
}