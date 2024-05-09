#include<bits/stdc++.h>
using namespace std;

struct {
private:
    int t[10101];
public:
    int sum(int i) { int s = 0; while (i) s += t[i], i -= i&-i; return s; }
    void add(int i, int x) { while (i) t[i] += x, i += i&-i; }
} fenwick;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}