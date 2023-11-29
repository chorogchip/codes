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

int N, X, T[2001010];
ii A[501010];

int sum(int i) {
    int s = 0;
    while (i) s += T[i], i -= i&-i;
    return s;
}
void add1(int i) {
    while (i <= N) ++T[i], i += i&-i;
}

int main() { FAST
    ll R = 0, S = 0;
    cin >> N;
    for1 (i, N) cin >> A[i].first, A[i].second = i;
    sort(A + 1, A + N + 1);
    for1 (i, N) {
        cin >> X;
        int dest = lower_bound(A + 1, A + N + 1, make_pair(X, 0))->second;
        R += S - sum(dest);
        add1(dest);
        ++S;
    }
    cout << R << endl;
}
