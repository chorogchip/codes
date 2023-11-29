#include<bits/stdc++.h>
using namespace std;

int dp_x[101010], dp_c[101010], cost[401010];
int const INF = 10'0000'0000;

void init_seg(int nn) {
    for (int i = 0; i <= nn; ++i)
        cost[i] = INF;
}

void update_cost(int i, int p, int s, int e, int c) {
    if (p < s || e < p) return;
    if (s == e) {
        cost[i] = min(cost[i], c);
        return;
    }
    int mid = s + e >> 1;
    if (p <= mid) update_cost(i<<1, p, s, mid, c);
    else update_cost((i<<1)+1, p, mid + 1, e, c);
    cost[i] = min(cost[i<<1], cost[(i<<1)+1]);
}

int query(int i, int l, int r, int s, int e) {
    if (r < s || e < l) return INF;
    if (l <= s && e <= r) return cost[i];
    int mid = s + e >> 1;
    return min(
        query(i<<1, l, r, s, mid),
        query((i<<1)+1, l, r, mid+1, e));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<tuple<int,int,int>> input(k);
    for (int i = 0; i < k; ++i) {
        int x, r, c; cin >> x >> r >> c;
        input[i] = {x, r, c};
        dp_x[x] = 1;
        dp_c[x] = c;
    }
    for (int i = 1; i <= n; ++i) {
        dp_x[i] += dp_x[i-1];
    }
    vector<tuple<int,int,int>> input2;
    input2.reserve(k);
    for (auto o : input) {
        auto [x, r, c] = o;
        int up = dp_x[min(n, x + r)];
        int down = dp_x[max(0, x - r - 1)];
        input2.push_back({up, down, c});
    }
    sort(input2.begin(), input2.end());
    int kk = 1 << 32 - __builtin_clz(k);
    init_seg(kk * 2 + 2);
    update_cost(1, 1, 1, kk, 0);
    for (auto o : input2) {
        auto [up, down, c] = o;
        int minc = query(1, down+1, k+1, 1, kk);
        if (minc > INF) minc = INF;
        update_cost(1, up+1, 1, kk, minc + c);
    }
    cout << query(1, k+1, k+1, 1, kk);
}