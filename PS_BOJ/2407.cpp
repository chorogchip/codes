#include<iostream>
#include<cstdlib>
#include<vector>
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int N, K, R, C[4010101];
vector<pair<int,int>> soinsu;
class LLL {
    public:
    LLL(): v(1, 1) {}
    vector<int> v;
    LLL& operator*=(int n) {
        int s = v.size();
        v.push_back(0);
        v.push_back(0);
        int cry = 0;
        for (int i = 0; i != s; ++i) {
            v[i] *= n;
            v[i] += cry;
            cry = v[i] / 10;
            v[i] %= 10;
        }
        v[s] = cry;
        v[s+1] = v[s] / 10;
        v[s] %= 10;
        if (v.back() == 0) v.pop_back();
        if (v.back() == 0) v.pop_back();
        return *this;
    }
};

int find(int num) {
    int lo = 0, md, hi = soinsu.size() - 1;
    while (lo < hi) {
        md = lo + hi >> 1;
        if (soinsu[md].first < num) lo = md + 1;
        else hi = md;
    }
    return lo;
}

int main() {
    LLL S;
    cin >> N >> K;
    R = N - K;
    for (int j = 2; j <= N; j *= 2) C[j] = 2;
    for (int j = 6; j <= N; j += 2) if (!C[j]) C[j] = -1;
    soinsu.push_back(make_pair(2, N / 2 - R / 2));
    for (int i = 3; i <= N; ++i) if (!C[i]) {
        for (long long j = i; j <= N; j *= i) C[j] = i;
        for (int k = i << 1, j = i + k; j <= N; j += k) if(!C[j]) C[j] = -1;
        soinsu.push_back(make_pair(i, N / i - R / i));
    } else if (C[i] != -1) soinsu[find(C[i])].second += N / i - R / i;
    for (int i = 2; i <= K; ++i) if (C[i] != -1)
        soinsu[find(C[i])].second -= K / i;
    K = soinsu.size();
    while (K--) while (soinsu[K].second--)
        S *= soinsu[K].first;
    int s = S.v.size();
    for (int i = s-1; i >= 0; --i) cout << (char)(S.v[i]+'0');
    cout << endl;
}
