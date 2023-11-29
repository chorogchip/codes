#include<bits/stdc++.h>
using namespace std;

//int sum[201010 * 4];
vector<pair<int,string>> t[201010 * 4];
vector<pair<int,string>> pv;
string str;
int nn;
/*
int gets(int i, int l, int s, int e) {
    if (s == e) return sum[i];
    int md = s + e >> 1;
    if (l < md) return sum[i] + gets(i<<1, l, s, md);
    else return sum[i] + gets((i<<1)+1, l, md+1, e);
}*/

void ins(int i, int l, int r, int s, int e, int mm) {
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        t[i].push_back({mm, str});
        return;
    }
    int md = s + e >> 1;
    ins(i<<1, l, r, s, md, mm);
    ins((i<<1)+1, l, r, md+1, e, mm);
}

void prt(int i, int l, int s, int e/*, int x, int yy*/) {
    /*cout << "prt\n";
    auto it = lower_bound(t[i].begin(), t[i].end(), make_pair(x, string("")));
    for (; it < t[i].end(); ++it) {
        if (it->first > yy) break;
        pv.push_back(*it);
    }*/
    for (auto o : t[i]) pv.push_back(o);
    if (s == e) return;
    int md = s + e >> 1;
    
    if (l <= md) prt(i<<1, l, s, md/*, x, yy*/);
    else prt((i<<1)+1, l, md+1, e/*, x, yy*/);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    nn = 1 << 32 - __builtin_clz(n-1);
    for(int mm = 0; mm < m; ++mm) {
        int q, a, b, c; cin >> q >> a >> b;
        if (q == 1) {
            cin >> str;
            ins(1, a, b, 0, nn-1, mm);
        } else {
            cin >> c;
            prt(1, a, 0, nn-1/*, b-1, c*/);
            sort(pv.begin(), pv.end());
            int skip = 0;
            int sz = b - c + 1;
            --b;
            for (auto o : pv) {
                if (skip >= b) {
                    if (skip > c);
                    else if (skip + o.second.size() < c) {
                        cout << o.second;
                        skip += o.second.size();
                    } else {
                        int dif = o.second.size() + skip - c;
                        for (int i = 0; i < dif; ++i) cout << o.second[i];
                        skip += o.second.size();
                    }
                } else if (o.second.size() <= b - skip) {
                    skip += o.second.size();
                } else {
                    int intv = o.second.size() - (b - skip);
                    for (int i = intv; i < o.second.size(); ++i) cout << o.second[i];
                    skip += o.second.size();
                }
            }
            cout << '\n';
            pv.clear();
        }
    }
}