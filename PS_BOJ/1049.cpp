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

int N, B;
pair<int,int> C[51];

int main() { FAST
    cin >> N >> B;
    fore (i, B) cin >> C[i].first >> C[i].second;
    for (int i = 1; i != B; ++i) {
        C[0].first = min(C[0].first, C[i].first);
        C[0].second = min(C[0].second, C[i].second);
    }
    if (C[0].first >= C[0].second * 6) {
        cout << C[0].second * N << endl;
        return 0;
    }
    cout << C[0].first * (N / 6) + min(C[0].first, C[0].second * (N % 6)) << endl;
}
