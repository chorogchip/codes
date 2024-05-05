#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<pair<int,int>> arr;
    for (int i = 1; i <= 8; ++i) {
        int x; cin >> x;
        arr.push_back({x, i});
    }
    sort(arr.begin(), arr.end());
    int s= 0;
    for (int i = 3; i < 8; ++i) s += arr[i].first;
    cout << s << '\n';
    vector<int> res;
    for (int i = 3; i < 8; ++i)
        res.push_back(arr[i].second);
    sort(res.begin(), res.end());
    for (auto o : res) cout << o << ' ';
}