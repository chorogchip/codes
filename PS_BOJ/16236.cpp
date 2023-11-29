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

int N, D[21][21], C[21][21];
#include<queue>
priority_queue<pair<int,int>> qu;
vector<pair<int,int>>v;

int main() {
    cin >> N;
    int px, py;
    fore (i, N) fore (j, N) {
        cin >> D[i][j];
        if (D[i][j] == 9) px = i, py = j;
    }
    int sz = 2;
    int cc = 0;
    int k = 0, d = 0;
    while (true) {
        int ppx = -1000, ppy = -1000;
        while(!qu.empty()) qu.pop(); memset(C, 0, sizeof(C)); v.clear();
        qu.push(make_pair(-px, -py));
        C[px][py] = 1;
        d = 0;
        while (!qu.empty()) {
            int s = qu.size();
            for (int i = 0; i != s; ++i) {
                auto o = qu.top(); qu.pop();
                int& x = D[-o.first][-o.second];
                if (x > 0 && x <= 6 && x < sz) {
                    ppx = -o.first, ppy = -o.second;
                    goto E;
                }
                if (-o.first-1>=0&&D[-o.first-1][-o.second]<=sz&&!C[-o.first-1][-o.second])
                    C[-o.first-1][-o.second]=1,v.push_back(make_pair(o.first+1,o.second));
                if (-o.first+1<N&&D[-o.first+1][-o.second]<=sz&&!C[-o.first+1][-o.second])
                    C[-o.first+1][-o.second]=1,v.push_back(make_pair(o.first-1,o.second));
                if (-o.second-1>=0&&D[-o.first][-o.second-1]<=sz&&!C[-o.first][-o.second-1])
                    C[-o.first][-o.second-1]=1,v.push_back(make_pair(o.first,o.second+1));
                if (-o.second+1<N&&D[-o.first][-o.second+1]<=sz&&!C[-o.first][-o.second+1])
                    C[-o.first][-o.second+1]=1,v.push_back(make_pair(o.first,o.second-1));
            }
            for (auto o : v) qu.push(o); v.clear();
            ++d;
        }
        E:
        if (ppx == -1000) break;
        if (++cc == sz) cc = 0, ++sz;
        k += d;
        D[px][py] = 0;
        px = ppx, py = ppy;
        D[px][py] = 9;
    }
    cout << k << endl;
}
