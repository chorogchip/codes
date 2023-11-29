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

int T, X1, X2, Y1, Y2, N, C[51], R;
vector<int> G[51];
struct circle {
    int x, y, r;
} circles[51];
#include<queue>
queue<int> qu;

inline bool isin(int data, int out) {
    if (circles[out].r <= circles[data].r) return false;
    int dx = circles[data].x - circles[out].x;
    int dy = circles[data].y - circles[out].y;
    return dx * dx + dy * dy < circles[out].r * circles[out].r;
}

void push(int cind, int ind) {
    for (auto o : G[ind])
    if (!C[o] && isin(cind, o)) {
        C[o] = 1;
        push(cind, o);
        return;
    }
    G[ind].push_back(cind);
    G[cind].push_back(ind);
}

main() { FAST
    cin >> T;
    while (T--) {
        cin >> X1 >> Y1 >> X2 >> Y2 >> N;
        while (!qu.empty()) qu.pop();
        for (int i = 0; i <= N; ++i) G[i].clear();
        circles[0] = circle { 0, 0, 10000 };
        for (int i = 1; i <= N; ++i)
            cin >> circles[i].x >> circles[i].y >> circles[i].r;
        sort(circles + 1, circles + 1 + N, [](circle a, circle b)->bool{
            return a.r > b.r;
        });
        for (int i = 1; i <= N; ++i) {
            memset(C, 0, sizeof(C));
            C[0] = 1;
            push(i, 0);
        }
        int st, en, o;
        for (int i = N; i >= 0; --i) {
            int dx = circles[i].x - X1;
            int dy = circles[i].y - Y1;
            if (dx * dx + dy * dy < circles[i].r * circles[i].r) {
                st = i;
                break;
            }
        }
        for (int i = N; i >= 0; --i) {
            int dx = circles[i].x - X2;
            int dy = circles[i].y - Y2;
            if (dx * dx + dy * dy < circles[i].r * circles[i].r) {
                en = i;
                break;
            }
        }
        memset(C, 0, sizeof(C));
        qu.push(st);
        C[st] = 1;
        R = 0;
        while (true) {
            int s = qu.size();
            for (int k = 0; k != s; ++k) {
                o = qu.front(); qu.pop();
                if (o == en) goto E;
                for (auto oo : G[o]) if (!C[oo]) {
                    C[oo] = 1;
                    qu.push(oo);
                }
            }
            ++R;
        }
        E:
        cout << R << endl;
    }
}

