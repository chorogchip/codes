#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P {
    int x, y;
};

int main() {
    int C; cin >> C;
    do {
        P p[4];
        for (int i = 0; i < 4; ++i)
            cin >> p[i].x >> p[i].y;
        sort(p, p + 4, [](const P& a, const P& b)->bool{
            return a.x < b.x || a.x == b.x && a.y < b.y;
        });
        int dx0 = p[1].x - p[0].x;
        int dx1 = p[2].x - p[0].x;
        int dx2 = p[3].x - p[2].x;
        int dx3 = p[3].x - p[1].x;
        int dy0 = p[1].y - p[0].y;
        int dy1 = p[2].y - p[0].y;
        int dy2 = p[3].y - p[2].y;
        int dy3 = p[3].y - p[1].y;
        if (dx0 == dx2 && dx1 == dx3 && dy0 == dy2 && dy1 == dy3 &&
            dx0 == dy1 && dx1 == dy0) goto Y;
        else goto N;
    
        Y: cout << "1\n"; continue;
        N: cout << "0\n"; continue;
    } while (--C);
}