#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<int,int> fd[501010];
int r[501010];

int main() {
    int n, g, b, d; cin >> n >> g >> b >> d;
    for (int i = 1; i <= n; ++i) cin >> fd[i].first >> fd[i].second;
    sort(fd + 1, fd + 1 + n);
    if (b < fd[1].first) {
        cout << -1;
        return 0;
    }
    fd[0] = {0, 1010101010};
    fd[n + 1] = {d, 0};
    stack<int> st;
    for (int i = n; i >= 0; --i) {
        while (!st.empty() && fd[st.top()].second >= fd[i].second) st.pop();
        r[i] = st.empty() ? n + 1 : st.top();
        st.push(i);
    }
    ll cost = 0;
    for (int i = 0; i <= n;) {
        int next = r[i];
        int gap = fd[next].first - fd[i].first;
        if (gap <= g) {
            if (b < gap) cost += (ll)fd[i].second * (ll)(gap - b), b = gap;
            b -= gap;
            i = next;
        } else {
            gap = fd[i + 1].first - fd[i].first;
            if (gap > g) {
                cout << -1;
                return 0;
            }
            cost += (ll)fd[i].second * (ll)(g - b), b = g;
            b -= gap;
            ++i;
        }
    }
    cout << cost;
}