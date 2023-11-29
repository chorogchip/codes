#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

int T[201010], isParEx[201010], state[201010];
vector<int> TT[201010];
vector<pii> input;
int res;

void gen(int i) {
    for (auto o : TT[i]) if (!isParEx[o]) {
        isParEx[o] = 1;
        T[o] = i;
        gen(o);
    }
}

int calc(int i) {
    if (i == 1) return 1;

    int par = T[i];

    if (state[par] == -1) {
        // appeared, lazy
        return state[i] = calc(par) + isParEx[i];
    } else {
        // calc ed
        return state[i] = state[par] + isParEx[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        memset(T, 0, sizeof(T));
        memset(isParEx, 0, sizeof(T));
        memset(state, 0, sizeof(T));
        input.clear();
        res = 1;
        int n; cin >> n;
        for (int i = 0; i <= n; ++i) TT[i].clear();
        for (int i = 1; i < n; ++i) {
            int a, b; cin >> a >> b;
            input.push_back({a, b});
            TT[a].push_back(b);
            TT[b].push_back(a);
        }
        T[1] = 0;
        state[1] = 1;
        isParEx[1] = 1;
        gen(1);
        memset(isParEx, 0, sizeof(T));
        for (auto o : input) {
            int a = o.x;
            int b = o.y;
            if (T[a] == b) swap(a, b);
            // a is parent
            if (state[a] == 0) {
                // not appeared
                isParEx[b] = 1;
                state[b] = -1;
            } else if (state[a] == -1) {
                // appeared, lazy
                isParEx[b] = 0;
                state[b] = -1;
            } else {
                // calc ed
                isParEx[b] = 0;
                state[b] = state[a];
            }
        }
        for (int i = 2; i <= n; ++i) if (state[i] == -1)
            res = max(res, calc(i));
        cout << res << '\n';
    }
}
