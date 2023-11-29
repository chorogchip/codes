#include<bits/stdc++.h>
using namespace std;

int cnt[101010];

void asdf() {
    for (int i = 2; i <= 10'0000; ++i) {
        cnt[i] += cnt[1];
        for (long long j = 2; j * j <= i; j++)
            if (i % j == 0) {
                cnt[i] += cnt[j];
                if (j * j != i) cnt[i] += cnt[i/j];
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x]++;
    }
    asdf();
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        cout << cnt[x] << ' ';
    }
}