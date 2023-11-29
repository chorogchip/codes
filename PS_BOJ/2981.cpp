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

int N, D[101], S;
vector<int> DS;
vector<pair<int, int>>soinsu;
vector<int>res;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
inline int getGCD() {
    int ret = DS[0];
    for (int i = 1; i != S; ++i)
        ret = gcd(ret, DS[i]);
    return ret;
}

void addASD(int num, int level) {
    if (level == S) {
        if (num != 1)
            res.push_back(num);
        return;
    }
    auto o = soinsu[level];
    for (int i = 0, nn = 1; i <= o.second; ++i, nn *= o.first)
        addASD(num * nn, level+1);
}

int main() {
    int N;
    cin >> N;
    fore (i, N) cin >> D[i];
    sort(D, D + N);
    for (int i = 1; i != N; ++i) {
        int gap = D[i] - D[i-1];
        if (gap && ((DS.empty()) || (gap != DS.back()))) DS.push_back(gap);
    }
    int G;
    S = DS.size();
    if (S == 0) G = D[0];
    else G = getGCD();
    for (int i = 2; G > 1;) {
        if (G % i == 0) {
            if (soinsu.empty() || soinsu.back().first != i) soinsu.push_back(make_pair(i, 1));
            else ++(soinsu.back().second);
            G /= i;
        } else ++i;
    }
    S = soinsu.size();
    addASD(1, 0);
    sort(res.begin(), res.end());
    for (auto o : res)
        cout << o << " ";
}
