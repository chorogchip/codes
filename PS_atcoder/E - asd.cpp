#include <bits/stdc++.h>
using namespace std;

char D[512][512];
char V[512][512];
#define x first
#define y second

int H, W;

using pii = pair<int,int>;
vector<pii> vec;
using ll = long long;
ll T;

int calc(pii a, pii b) {
    memset(V, 0, sizeof(V));
    V[a.x][a.y] = 1;
    queue<pii> qu;
    qu.push(a);
    int len = 0;
    while (!qu.empty()) {
        int sz = qu.size();
        for (int i = 0; i < sz; ++i) {
            auto o = qu.front(); qu.pop();
            if (o == b) return len;
            #define A(p,q) if (D[(p)][(q)]!='#'&&D[(p)][(q)]!='G'&&!V[(p)][(q)]) V[(p)][(q)]=1,qu.push({(p),(q)});
            A(o.x+1,o.y)
            A(o.x-1,o.y)
            A(o.x,o.y+1)
            A(o.x,o.y-1)
        }
        ++len;
    }
    return -1;
}

int G[32][32];

int vis[32];
int res(int st, int fn, ll dist) {
    int ret = -1;
    if (dist > T) return -1;
    if (st == fn) return 0;
    for (int i = 1; i < vec.size(); ++i)if (!vis[i]) {
        vis[i] = 1;
        int rrr = res(i, fn, dist + G[i][fn]);
        if (rrr != -1) ret = max(ret, rrr + 1);
        vis[i] = 0;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 cin >> H >> W >> T;
    pii s, g;
    vec.push_back({0,0});
    for (int i = 1; i <= H; ++i)
    for (int j = 1; j <= W; ++j) {
        cin >> D[i][j];
        switch(D[i][j]) {
            case 'S': s = {i,j}; break;
            case 'G': g = {i,j}; break;
            case 'o': vec.push_back({i, j}); break;
        }
    }
    vec[0] = s;
    vec.push_back(g);
    for (int i = 0; i <= H + 1; ++i) D[i][0] = '.';
    for (int i = 0; i <= H + 1; ++i) D[i][W+1] = '.';
    for (int i = 0; i <= W + 1; ++i) D[0][i] = '.';
    for (int i = 0; i <= W + 1; ++i) D[H+1][i] = '.';
    for (int i = 0; i < vec.size(); ++i)
    for (int j = 0; j < vec.size(); ++j) if (i != j)
    G[i][j] = calc(vec[i],vec[j]);
    else G[i][j] = 0;

    vis[0] = 1;
    int rrrr = res(0,vec.size()-1,0);
    if (rrrr != -1) --rrrr;
    cout << rrrr;

}