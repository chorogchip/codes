#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    priority_queue<int> qm;
    priority_queue<int, vector<int>, greater<int>> qM;
    qm.push(-10101); qM.push(10101);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        int m = qm.top(); qm.pop();
        int M = qM.top(); qM.pop();
        if (m > x) swap(m, x);
        if (x > M) swap(x, M);
        if (m > x) swap(m, x);
        qm.push(m); qM.push(M);
        if (i & 1) {
            cout << x << '\n';
            qM.push(x);
        } else {
            cout << x << '\n';
            qm.push(x);
        }
    }

}