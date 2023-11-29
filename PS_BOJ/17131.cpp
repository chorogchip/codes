#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
constexpr int INF = 1000*1000*1000;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

int N, D[501010], S;
ii P[201010];
vii vec;
ll SS;
constexpr ll Mod = INF + 7;

void insert(int i) {
    while (i <= 500000) ++D[i], i += i&-i;
}
int getS(int i) {
    int s = 0;
    while (i) s += D[i], i -= i&-i;
    return s;
}

int main() { FAST
    cin >> N;
    fore (i, N) cin >> P[i].second >> P[i].first, P[i].second += 250000;
    sort(P, P + N, [](const ii& a, const ii& b)->bool{
        return a.first > b.first;
    });
    vec.push_back(P[0]);
    for (int i = 1; i != N; ++i) {
        if (P[i].first != P[i-1].first) {
            for (auto o : vec) insert(o.second), ++S;
            vec.clear();
        }
        ll a = getS(P[i].second - 1);
        ll b = S - getS(P[i].second);
        SS += a * b % Mod;
        SS %= Mod;
        vec.push_back(P[i]);
    }
    cout << SS;
}
