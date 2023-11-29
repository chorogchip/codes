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

int N, M, C[32010], A, B;
vi G[32010], R;

void add(int x) {
    for (auto o : G[x]) if (!C[o]) {
        C[o] = 1;
        add(o);
    }
    R.push_back(x);
    C[x] = 1;
}

int main() { FAST
    cin >> N >> M;
    fore (i, M) {
        cin >> A >> B;
        G[A].push_back(B);
    }
    for1 (i, N) if (!C[i]) add(i);
    for (int i = R.size() - 1; i >= 0; --i) cout << R[i] << ' ';
}
