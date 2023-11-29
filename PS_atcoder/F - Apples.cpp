#include<bits/stdc++.h>
using namespace std;

int segmax[1601010];
int segnum[1601010];

void prttree(int i, int s, int e) {
    cout << "p " << i << ' ' << s << ' ' << e << ' ' << segmax[i] << ' ' << segnum[i] << '\n';
    if (segmax[i] == 0) return;
    if (s == e) return;
    int ms = s + e >> 1;
    prttree(i<<1, s, ms);
    prttree((i<<1)+1, ms+1, e);
}

void addd(int i, int s, int e, int l, int r, int x) {
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        segnum[i] += x;
        segmax[i] += x;
        return;
    }
    int md = s + e >> 1;
    segnum[i<<1] += segnum[i];
    segmax[i<<1] += segnum[i];
    segnum[(i<<1)+1] += segnum[i];
    segmax[(i<<1)+1] += segnum[i];
    segnum[i] = 0;

    addd(i<<1, s, md, l, r, x);
    addd((i<<1)+1, md+1, e, l, r, x);
    segmax[i] = max(segmax[i<<1], segmax[(i<<1)+1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, d, w; cin >> n >> d >> w; --d, --w;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    queue<pair<int,int>> qu;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        qu.push(v[i]);
        int nn = 1 << 32 - __builtin_clz(2'00000 + w - 1);
        addd(1, 1, nn, v[i].second, v[i].second + w, 1);
        while (v[i].first - qu.front().first > d) {
            addd(1, 1, nn, qu.front().second, qu.front().second + w, -1);
            qu.pop();
        }
        res = max(res, segmax[1]);
    }
    cout << res;
}