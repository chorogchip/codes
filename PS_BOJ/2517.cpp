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

int N, T[501010];
ii D[501010];

void add1(int i) {
    while (i <= N) ++T[i], i += i&-i;
}
int sum(int i) {
    int res = 0;
    while (i) res += T[i], i -= i&-i;
    return res;
}

int main() { FAST
    cin >> N;
    fore (i, N) cin >> D[i].first, D[i].second = i;
    sort(D, D + N);
    int pre = D[0].first;
    D[0].first = 1;
    for (int i = 1; i != N; ++i) {
        if (D[i].first == pre)
            D[i].first = D[i-1].first;
        else pre = D[i].first, D[i].first = D[i-1].first + 1;
    }
    sort(D, D + N, [](ii a, ii b)->bool{
        return a.second < b.second;
    });
    fore (i, N) {
        cout << i - sum(D[i].first-1) + 1 << endl;
        add1(D[i].first);
    }
}
