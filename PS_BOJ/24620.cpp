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

#include<list>
int T, N, D[101010], S;
vector<pair<int,int>> primes;
list<pair<int,int>> yl;

void getYaksu(int dpt, int val) {
    if (dpt == S) {
        yl.push_back(make_pair(val, val));
        return;
    }
    for (int i = 0; i <= primes[dpt].second; ++i, val *= primes[dpt].first)
        getYaksu(dpt + 1, val);
}

int main() { FAST
    cin >> T;
    while (T--) {
        cin >> N >> D[1]; primes.clear();
        for (int i = 2; i <= N; ++i) cin >> D[i], D[i] += D[i-1];
        S = D[N];
        if (S == 0) {
            cout << "0\n";
            continue;
        }
        if ((S & 1) == 0) {
            primes.push_back(make_pair(2, 0));
            do ++(primes[0].second);
            while (((S >>= 1) & 1) == 0);
        }
        for (int i = 3; i * i <= S;) if (S % i == 0) {
            S /= i;
            if (primes.empty() || primes.back().first != i)
                primes.push_back(make_pair(i, 1));
            else ++(primes.back().second);
        } else i += 2;
        if (primes.empty() || primes.back().first != S)
            primes.push_back(make_pair(S, 1));
        else ++(primes.back().second);

        S = primes.size(); yl.clear();
        getYaksu(0, 1);
        yl.sort();
        for (int i = 1; i <= N; ++i) for (auto it = yl.begin(); it != yl.end();) {
            if (D[i] == it->second) it->second += it->first, ++it;
            else if (D[i] > it->second) it = yl.erase(it);
            else ++it;
        }
        cout << N - (yl.front().second / yl.front().first - 1) << endl;
    }
}
