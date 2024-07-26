#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int w[201010];
vector<int> g[201010];
ll acc[201010];

struct SS {
    ll a, b;
    void operator+=(const SS& s) {
        a += s.a; b += s.b;
    }
    void operator-=(const SS& s) {
        a -= s.a; b -= s.b;
    }
    void step(int wei) {
        a += b;
        b += wei;
    }
};

SS self[201010];
vector<SS> mres[201010];

SS calc_up(int i, int prev) {
    SS sum{};
    for (auto o : g[i]) if (o != prev) {
        SS os = calc_up(o, i);
        mres[i].push_back(os);
        sum += os;
    }
    self[i] = sum;
    sum.step(w[i]);
    return sum;
}
ll ret = 0;
void calc_down(int i, int prev, SS up) {
    SS res = up;
    res += self[i];
    res.step(w[i]);
    ret = max(ret, res.a);
    res = up;
    res += self[i];
    int j = 0;
    for (auto o : g[i]) if (o != prev) {
        SS os = res;
        os -= mres[i][j++];
        os.step(w[i]);
        calc_down(o, i, os);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=  1; i <= n; ++i) {
        cin >> w[i];
    }
    calc_up(1, 0);
    calc_down(1, 0, {0, 0});
    cout << ret;
}