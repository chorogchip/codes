#include <bits/stdc++.h>
using namespace std;

int b[101010];
using pii = pair<int,int>;
using vii = vector<pii>;
vii r, l;
priority_queue<pii> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        r.clear(); l.clear();
        int n; cin >> n;
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
            pq.push({b[i], i});
        }
        for (int i = 1; i <= n; ++i) {
            int val = b[i] - i;
            while (!r.empty() && r.back().second < val) r.pop_back();
            r.push_back({i, val});
        }
        for (int i = n; i; --i) {
            int val = b[i] - (n - i + 1);
            while (!l.empty() && l.back().second < val) l.pop_back();
            l.push_back({i, val});
        }
        while (!pq.empty()) {
            auto o = pq.top(); pq.pop();
            int ii = o.second;
            if (ii == 1 || ii == n) continue;
            int val = o.first;
            int ri = upper_bound(r.begin(), r.end(), pii{ii,0}, [](pii a, pii b)->bool{return a.first < b.first;})->first;
            int li = upper_bound(l.begin(), l.end(), pii{ii,0}, [](pii a, pii b)->bool{return a.first > b.first;})->first;
            val += b[ri] + b[li] - (ri - li);
            result = max(result, val);
        }
        cout << result << '\n';
    }
}
