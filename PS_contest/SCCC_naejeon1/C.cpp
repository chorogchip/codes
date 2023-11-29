#include<bits/stdc++.h>
using namespace std;



pair<int,int> v[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y; cin >> x >> y;
        v[i] = {max(abs(x), abs(y)), i};
    }
    sort(v+1, v+n+1);
    vector<int> answer;
    for (int i = 1; i <= n; ++i) {
        if (v[i].first < i) goto NO;
        answer.push_back(v[i].second);
    }
    for (auto o : answer) cout << o << ' ';
    return 0;
    NO: cout << "-1";
}