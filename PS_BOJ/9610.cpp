#include<bits/stdc++.h>
using namespace std;

int r[5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        if (x == 0 || y == 0) r[4]++;
        else if (x > 0 && y > 0) r[0]++;
        else if (x < 0 && y > 0) r[1]++;
        else if (x < 0 && y < 0) r[2]++;
        else r[3]++;
    }
    cout << "Q1: " << r[0] << "\nQ2: " << r[1] << "\nQ3: " << r[2] << "\nQ4: " << r[3] << "\nAXIS: " << r[4];
}