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

ll N, Q, A, B, C, D, E, T[1010], DD[1010];

ll sum(int i) {
    ll s = 0;
    while (i) s += T[i], i -= i&-i;
    return s;
}
void add(int i, ll val) {
    while(i<=N) T[i] += val, i += i&-i;
}

int main() { FAST
    cin >> N >> Q;
    for1 (i, N) cin >> DD[i], add(i, DD[i]);
    fore (i, Q) {
        cin >> A;
        if (A == 1) {
            cin >> B >> C;
            cout << sum(C) - sum(B - 1) << endl;
            D = DD[B]; E = DD[C];
            add(B, E - D);
            add(C, D - E);
            DD[B] = E;
            DD[C] = D;
        } else {
            cin >> B >> C >> D >> E;
            cout << sum(C) - sum(B - 1) - sum(E) + sum(D - 1) << endl;
        }
    }
}
