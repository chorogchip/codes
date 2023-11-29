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

int N, S, D[101010], R = INF;

int main() { FAST
    cin >> N >> S;
    for1 (i, N) cin >> D[i];
    int sum = D[1], lo = 1, hi = 1;
    while (hi <= N) {
        if (sum >= S) {
            R = min(R, hi - lo + 1);
            sum -= D[lo++];
        } else {
            sum += D[++hi];
        }
    }
    if (R == INF) {
        cout << 0;
        return 0;
    }
    cout << R;
}
