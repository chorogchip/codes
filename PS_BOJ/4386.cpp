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

int N;
pair<double,double> V[101];
pair<double, ii> G[10101];
char U[101];
double S;

int find(int x) {
    if (U[x] == x) return x;
    return U[x] = find(U[x]);
}

#include<cmath>
double dist(int i, int j) {
    double a = V[i].first - V[j].first,
    b = V[i].second - V[j].second;
    return sqrt(a*a + b*b);
}

int main() {
    cin >> N;
    fore (i, N) cin >> V[i].first >> V[i].second;
    int k = 0;
    fore (i, N) for (int j = i + 1; j < N; ++j)
        G[k++] = {dist(i, j), {i, j}};
    sort(G, G + k);
    for1 (i, N) U[i] = i;
    int kk = 1, a, b;
    fore (i, k) {
        if (kk == N) break;
        if ((a = find(G[i].second.first)) !=
            (b = find(G[i].second.second)))
                U[a] = b, ++kk, S += G[i].first;
    }
    printf("%.2lf", S);
}
