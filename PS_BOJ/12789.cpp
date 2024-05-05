#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v;
    int turn = 1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x == turn) turn++;
        else v.push_back(x);
        while (!v.empty() && v.back() == turn) turn++, v.pop_back();
    }
    cout << (v.empty() ? "Nice" : "Sad");
}