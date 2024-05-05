#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
constexpr bool DBG = false;

int d[16][16];


void chk(int i){if(DBG){cout << "chk " << i << '\n';}}
void prt(int i){if(DBG){
    cout << "prt " << i << '\n';
    for (int y = 1; y <= 10; ++y) {
        for (int x = 1; x <= 10; ++x) cout << d[y][x];
        cout << '\n';
    }
    cout << '\n';
}}
void ass(bool b){if(!b){cout<<0;exit(0);}}
void f(){ass(false);}
void end(pii a, pii b, pii c){
    cout << a.first << ' ' << a.second << '\n'
         << b.first << ' ' << b.second << '\n'
         << c.first << ' ' << c.second << '\n'; exit(0);}

int inp_sum() {
    int sum = 0;
    int px, py;
    for (int y = 1; y <= 10; ++y)
    for (int x = 1; x <= 10; ++x) {
        char c; cin >> c;
        int num = c - '0';
        d[y][x] = num;
        sum += num;
        if (num == 1) py = y, px = x;
    }
    ass(sum > 0);
    if (sum == 1) end({py,px},{py,px},{py,px});
    return sum;
}
pair<pii,pii> calc_minmax() {
    int my = 11, mx = 11, My = 0, Mx = 0;
    for (int y = 1; y <= 10; ++y)
    for (int x = 1; x <= 10; ++x) if (d[y][x]) {
        my = min(my, y);
        My = max(My, y);
        mx = min(mx, x);
        Mx = max(Mx, x);
    }
    return {{my, mx}, {My, Mx}};
}
pair<int,int> get_n(pii mm, pii MM) {
    const auto [my, mx] = mm;
    const auto [My, Mx] = MM;
    const int gapy = My - my + 1;
    const int gapx = Mx - mx + 1;
    const int n = min(gapx, gapy);
    const int nn = max(gapx, gapy);
    return {n, nn};
}
int get_dir(int n, int nn, pii mm, pii MM) {
    const auto [my, mx] = mm;
    const auto [My, Mx] = MM;
    const int plt = d[my][mx];
    const int prt = d[my][Mx];
    const int pld = d[My][mx];
    const int prd = d[My][Mx];
    if (n == nn) {
        ass(plt + prt + pld + prd == 3);
        if (plt == 0) return 0;
        if (prt == 0) return 1;
        if (prd == 0) return 2;
        if (pld == 0) return 3;
        else f(); return 0;
    }
    ass(plt + prt + pld + prd == 2);
    if (plt + prt == 0) return 0;
    else if (prt + prd == 0) return 1;
    else if (pld + prd == 0) return 2;
    else if (plt + pld == 0) return 3;
    else f(); return 0;
}
void gen(int (&dd)[16][16], int dir, int n, int nn, pii mm, pii MM) {
    memset(dd, 0, sizeof(dd));
    const auto [my, mx] = mm;
    const auto [My, Mx] = MM;
    if (n == nn) {
        if (dir == 0) {
            for (int i = 0; i < n; ++i)
            for (int x = Mx-i; x <= Mx; ++x) dd[my+i][x] = 1;
        } else if (dir == 1) {
            for (int i = 0; i < n; ++i)
            for (int x = mx; x <= mx+i; ++x) dd[my+i][x] = 1;
        } else if (dir == 2) {
            for (int i = 0; i < n; ++i)
            for (int x = mx; x <= mx+i; ++x) dd[My-i][x] = 1;
        } else if (dir == 3) {
            for (int i = 0; i < n; ++i)
            for (int x = Mx-i; x <= Mx; ++x) dd[My-i][x] = 1;
        } else f();
        return;
    }
    const int midy = (my + My)/2, midx = (mx + Mx)/2;
    if (dir == 0) {
        for (int i = 0; i < n; ++i)
        for (int x = midx - i; x <= midx + i; ++x) dd[my+i][x] = 1;
    } else if (dir == 1) {
        for (int i = 0; i < n; ++i)
        for (int y = midy - i; y <= midy + i; ++y) dd[y][Mx-i] = 1;
    } else if (dir == 2) {
        for (int i = 0; i < n; ++i)
        for (int x = midx - i; x <= midx + i; ++x) dd[My-i][x] = 1;
    } else if (dir == 3) {
        for (int i = 0; i < n; ++i)
        for (int y = midy - i; y <= midy + i; ++y) dd[y][mx+i] = 1;
    } else f();
}
void calc(int dir, int n, int nn, pii mm, pii MM) {
    int dd[16][16];
    gen(dd, dir, n, nn, mm, MM);
    for (int y = 1; y <= 10; ++y)
    for (int x = 1; x <= 10; ++x)
        ass(d[y][x] == dd[y][x]);
    const auto [my, mx] = mm;
    const auto [My, Mx] = MM;
    if (n == nn) {
        if (dir == 0) end({my, Mx}, {My, mx}, {My, Mx});
        else if (dir == 1) end({my, mx}, {My, mx}, {My, Mx});
        else if (dir == 2) end({my, mx}, {my, Mx}, {My, Mx});
        else if (dir == 3) end({my, mx}, {my, Mx}, {My, mx});
    }
    const int midy = (my + My)/2, midx = (mx + Mx)/2;
    if (dir == 0) end({my, midx}, {My, mx}, {My, Mx});
    else if (dir == 1) end({my, mx}, {midy, Mx}, {My, mx});
    else if (dir == 2) end({my, mx}, {my, Mx}, {My, midx});
    else if (dir == 3) end({my, Mx}, {midy, mx}, {My, Mx});
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    const int sum = inp_sum();
    prt(1);
    chk(1);
    const auto [mm, MM] = calc_minmax();
    chk(2);
    const auto [n, nn] = get_n(mm, MM);
    chk(3);
    const auto dir = get_dir(n, nn, mm, MM);
    chk(4);
    calc(dir, n, nn, mm, MM);
}