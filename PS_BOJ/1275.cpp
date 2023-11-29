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
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;

ll N, Q, X, Y, A, B, D[101010], T[101010];

ll sum(ll i) {
    ll s = 0;
    while (i) s += T[i], i -= i&-i;
    return s;
}

void add(ll i, ll x) {
    while (i <= N) T[i] += x, i += i&-i;
}

int main() { FAST
    cin >> N >> Q;
    for1(i, N) cin >> D[i], add(i, D[i]);
    fore(i, Q) {
        cin >> X >> Y >> A >> B;
        if (X > Y) swap(X, Y);
        cout << sum(Y) - sum(X - 1) << endl;
        add(A, B - D[A]), D[A] = B;
    }
}
