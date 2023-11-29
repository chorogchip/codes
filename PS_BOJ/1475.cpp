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

int N, D[10], M;

int main() { FAST
    cin >> N;
    do ++D[N%10]; while (N /= 10);
    D[6] = D[9] = D[6] + D[9] + 1 >> 1;
    fore (i, 10) M = max(M, D[i]);
    cout << M;
}
