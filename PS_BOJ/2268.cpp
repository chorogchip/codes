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

int N, NN, M;
ll D[4010101], A, B, C, DD[1010101];

ll sum(int i) {
    ll s = 0;
    while (i) s += D[i], i -= i&-i;
    return s;
}
void add(int i, ll x) {
    while (i <= N) D[i] += x, i += i&-i;
}
int main() { FAST
    cin >> N >> M;
    NN = 1<<32-__builtin_clz(N);
    fore (i, M) {
        cin >> A >> B >> C;
        if (A) add(B, C - DD[B]), DD[B] = C;
        else {
            if (B > C) swap(B, C);
            cout << sum(C) - sum(B - 1) << endl;
        }
    }

}
