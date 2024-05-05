#include<bits/stdc++.h>
using namespace std;

struct ss {
    string name;
    int a, b, c;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ss> v(n);
    for(auto &o : v) cin >> o.name >> o.a >> o.b >> o.c;
    sort(v.begin(), v.end(), [](const ss& a, const ss& b) ->bool {
        if (a.a != b.a) return b.a < a.a;
        if (a.b != b.b) return a.b < b.b;
        if (a.c != b.c) return b.c < a.c;
        return a.name < b.name;
    });
    for (auto& o : v) cout << o.name << '\n';
}