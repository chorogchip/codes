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

int N, Q, D[201010], L, A, B;

int main() { FAST
    cin >> N >> Q;
    fore (i, N) cin >> D[i];
    fore (i, Q) {
        cin >> A;
        if (A == 1) {
            cin >> A >> B;
            D[(L + A - 1) % N] += B;
        } else if (A == 3) cin >> B, L += B, L %= N;
        else cin >> B, L += N - B, L %= N;
    }
    fore (i, N) cout << D[(L + i) % N] << ' ';
}
