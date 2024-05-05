#include<bits/stdc++.h>
using namespace std;

int arr[128][128];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i <= n + 1; ++i) arr[i][0] = arr[i][n+1] = arr[0][i] = arr[n+1][i] = 1;
    while(k--) {
        int yy, xx; cin >> yy >> xx;
        arr[yy][xx] = 2;
    }
    int l; cin >> l;
    int tim = 0;
    arr[1][1] = 1;
    queue<pair<int,int>> snake;
    snake.push({1, 1});
    int py = 1, px = 1;
    int facing = 1;
    int cur = 0;
    while(l--) {
        
        int step; char dir; 
        int ppy = 0, ppx = 0;
        if (l == -2) step = 1'000'000;
        else cin >> step >> dir;
        if (facing == 0) ppy = -1;
        else if (facing == 1) ppx = 1;
        else if (facing == 2) ppy = 1;
        else ppx = -1;
        while(cur < step) {
            cur++;
            ++tim;
            if (arr[py+ppy][px+ppx] & 1) goto END;
            else {
                bool is_apple = arr[py+ppy][px+ppx] == 2;
                arr[py+ppy][px+ppx] = 1;
                snake.push({py+ppy,px+ppx});
                py+=ppy, px+=ppx;
                if (!is_apple) {
                    auto [ny, nx] = snake.front(); snake.pop();
                    arr[ny][nx] = 0;
                }
            }
        }
        if (dir == 'L') facing = (facing + 3) % 4;
        else facing = (facing + 1) % 4;
        if (l == 0) l = -1;
    }

    END: cout << tim;
}