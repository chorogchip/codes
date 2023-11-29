#include <bits/stdc++.h>
using namespace std;

char st[10001];
int n, a, b;
long long minasdf = LONG_LONG_MAX;

void asdf(char *stst, long long aa) {
    long long cost = 0LL;
    int half = n >> 1;
    for (int i = 0; i < half; ++i)
    {
        if (stst[i] != stst[n - i - 1])
        cost += b;
    }
    minasdf = min(minasdf, cost + aa);
}

int main() {
    cin >> n >> a >> b >> st;
    long long cost = 0;
    for (int i = 0; i < n; ++i)
    {
        asdf(st + i, cost);
        st[n + i] = st[i];
        cost += a;
    }
    cout << minasdf;
}