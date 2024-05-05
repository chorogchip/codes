#include<bits/stdc++.h>
using namespace std;

struct Sh {
    int speed, dir, size;
} sh[128][128], shp[128][128];


int main() {
    int y, x, m; cin >> y >> x >> m;
    for (int i = 0; i < m; ++i) {
        int r, c, s, d, z; cin >> r >> c >> s >> d >> z;
        --d;
        switch(d) {
            case 0: case 1: s %= max(1, y * 2 - 2); break;
            case 2: case 3: s %= max(1, x * 2 - 2); break;
        }
        sh[r][c] = {s, d, z};
    }
    int sum = 0;
    for (int xc = 1; xc <= x; ++xc) {

        
        for (int yy = 1; yy <= y; ++yy) {
            for (int xx = 1; xx <= x; ++xx) {
                auto& o = sh[yy][xx];
                cout << o.speed << ' ' << o.dir << ' ' << o.size << '/';
            }
            cout << '\n';
        }
        cout << '\n';

        memset(shp, 0, sizeof(shp));
        for (int yy = 1; yy <= y; ++yy) for (int xx = 1; xx <= x; ++xx) if (sh[yy][xx].size) {
            auto& o = sh[yy][xx];
            int new_x = xx;
            int new_y = yy;
            switch(o.dir) {
                case 0: new_y -= o.speed; break;
                case 1: new_y += o.speed; break;
                case 2: new_x += o.speed; break;
                case 3: new_x -= o.speed; break;
            }
            if (new_x < -x + 2) new_x += x * 2 - 2;
            else if (new_x < 1) new_x = 2 - new_x, o.dir ^= 1;
            else if (new_x >= x * 2) new_x -= x * 2 - 2;
            else if (new_x > x) new_x = x - (new_x - x), o.dir ^= 1;
            
            if (new_y < -y + 2) new_y += y * 2 - 2;
            else if (new_y < 1) new_y = 2 - new_y, o.dir ^= 1;
            else if (new_y >= y * 2) new_y -= y * 2 - 2;
            else if (new_y > y) new_y = y - (new_y - y), o.dir ^= 1;
            
            auto& new_o = shp[new_y][new_x];
            if (!new_o.size || new_o.size < o.size) new_o = o;
        }
        memcpy(sh, shp, sizeof(sh));


        for (int yy = 1; yy <= y; ++yy) {
            for (int xx = 1; xx <= x; ++xx) {
                auto& o = sh[yy][xx];
                cout << o.speed << ' ' << o.dir << ' ' << o.size << '/';
            }
            cout << '\n';
        }
        cout << '\n';
        cout << '\n';

        for (int yy = 1; yy <= y; ++yy) if (sh[yy][xc].size) {
            sum += sh[yy][xc].size;
            sh[yy][xc] = Sh{};
            break;
        }
    }
    cout << sum;
}