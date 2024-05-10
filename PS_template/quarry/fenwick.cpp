#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

struct {
private:
    ll t[10101];
public:
    ll sum(int i) { ll s = 0; while (i) s += t[i], i -= i&-i; return s; }
    void add(int i, int x) { while (i <= n) t[i] += x, i += i&-i; }
} fenwick;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}