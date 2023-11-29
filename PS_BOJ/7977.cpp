#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N;
char C[10101];
pair<int,char> M[4];

int main() { FAST
    cin >> N >> C;
    M[0].second = 'A', M[1].second = 'C', M[2].second = 'T', M[3].second = 'G';
    for (int i = 0; i != N; ++i)
        ++M[C[i] >> 1 & 3].first;
    sort(M, M + 4);
    char c = M[0].second;
    cout << M[0].first << endl;
    for (int i = 0; i != N; ++i) cout << c;
    cout << endl;
}
