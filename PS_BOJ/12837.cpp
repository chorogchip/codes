#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;

int N, Q, C, A, B, X;
ll T[1010101];

void add(int i, ll x) {
    while (i <= N) T[i] += x, i += i&-i;
}
ll sum(int i) {
    ll s = 0;
    while (i) s += T[i], i -= i&-i;
    return s;
}

int main() { FAST
    cin >> N >> Q;
    fore (i, Q) {
        cin >> C >> A >> B;
        if (C == 1) add(A, B);
        else cout << sum(B) - sum(A - 1) << endl;
    }
}
