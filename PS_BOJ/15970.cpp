#include<bits/stdc++.h>
using namespace std;

int p[5010];
int c[5010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i] >> c[i];
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int dist = 10'0000;
        for (int j = 0; j < n; ++j) if (i != j)
            if (c[i] == c[j]) dist = min(dist, abs(p[i]-p[j]));
        res += dist;
    }
    cout << res;
}