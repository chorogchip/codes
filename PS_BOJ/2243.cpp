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

int N, T[4010101], A, B, C;
constexpr int NN = 1<<32-__builtin_clz(1000000);

void add(int i, int val, int cnt, int s, int e) {
    T[i] += cnt;
    if (s == e) return;
    int md = s + e >> 1;
    if (val <= md) add(i<<1, val, cnt, s, md);
    else add((i<<1)+1, val, cnt, md+1, e);
}

int get(int i, int val, int s, int e) {
    --T[i];
    if (s == e) return s;
    int md = s + e >> 1;
    if (val <= T[i<<1]) return get(i<<1, val, s, md);
    else return get((i<<1)+1, val - T[i<<1], md+1, e);
}

int main() { FAST
    cin >> N;
    fore (i, N) {
        cin >> A;
        if (A == 1) {
            cin >> B;
            cout << get(1, B, 1, NN) << endl;
        } else {
            cin >> B >> C;
            add(1, B, C, 1, NN);
        }
    }
}
