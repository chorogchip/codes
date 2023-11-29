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

int N, D[101010], L[101010], R[101010];
ll S[101010];
vii vec;

int main() { FAST
    cin >> N;
    for1 (i, N) {
        cin >> D[i];
        S[i] = S[i-1] + D[i];
        L[i] = i;
        while (!vec.empty() && vec.back().first >= D[i])
            L[i] = L[vec.back().second], vec.pop_back();
        vec.push_back(make_pair(D[i], i));
    }
    vec.clear();
    for (int i = N; i; --i) {
        R[i] = i;
        while (!vec.empty() && vec.back().first >= D[i])
            R[i] = R[vec.back().second], vec.pop_back();
        vec.push_back(make_pair(D[i], i));
    }
    vec.clear();
    ll RR = 0LL;
    for1 (i, N) RR = max(RR, D[i] * (S[R[i]] - S[L[i]-1]));
    cout << RR;
}
