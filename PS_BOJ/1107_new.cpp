#include<bits/stdc++.h>
using namespace std;

int d[11];
int INF = 10'0000'0000;

int asd(int n, int t) {
    int cost = 0;
    int tt = t;
    do {
        int digit = t % 10;
        if (d[digit]) return INF;
        cost++;
    } while(t /= 10);
    return cost + abs(n - tt);
}

int main() {
    int n; cin >> n;
    int b; cin >> b;
    for (int i = 0; i < b; ++i) {
        int x; cin >> x; d[x] = 1;
    }
    int cost = abs(n - 100);
    for (int t = 0; t <= n * 2 + 100; ++t) {
        cost = min(cost, asd(n, t));
    }
    cout << cost;
}