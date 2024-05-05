#include<bits/stdc++.h>
using namespace std;

int aa[501010], tmp[501010];
int n, cnt, k;

void merg(int a[], int l, int md, int r) {
    int i = l, j = md+1, t = 1;
    while (i <= md && j <= r) {
        if (a[i] <= a[j]) tmp[t++] = a[i++];
        else tmp[t++] = a[j++];
    }
    while (i <= md) tmp[t++] = a[i++];
    while (j <= r) tmp[t++] = a[j++];
    i = l; t = 1;
    while (i <= r) {
        a[i++] = tmp[t++];
        if (++cnt == k) { cout << a[i-1]; exit(0); }
    }
}

void mgst(int a[], int l, int r) {
    if (l >= r) return;
    int md = l + r >> 1;
    mgst(a, l, md);
    mgst(a, md+1, r);
    merg(a, l, md, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> aa[i];
    mgst(aa, 1, n);
    cout << -1;
}