#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

pair<int,int> g[201010];
unsigned indeg[201010];
int res;

void rem(int i) {
    res--;
    indeg[i] = -1;
    auto [a, b] = g[i];
    if (--indeg[a] < 2) rem(a);
    if (--indeg[b] < 2) rem(b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> g[i].first >> g[i].second;
        indeg[g[i].first]++;
        indeg[g[i].second]++;
    }
    res = n;
    for (int i = 1; i <= n; ++i)
        if (indeg[i] < 2) rem(i);
    cout << res << '\n';
    for (int i = 1; i <= n; ++i)
        if ((int)indeg[i] > 0) cout << i << ' ';

}