#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

pii operator+(const pii& a, const pii& b) {
    return {a.first + b.first, a.second + b.second};
}
bool operator==(const pii& a, const pii& b) {
    return a.first == b.first && a.second == b.second;
}
bool operator!=(const pii& a, const pii& b) {
    return a.first != b.first || a.second != b.second;
}

int n, m;
static struct {
    char d[16][16];
    char& at(pii p) { return d[p.first][p.second]; }
} board;

const int INF = 1'000'000;
const pii SUCC = {-1, 0};
const pii FAIL = {-1, -1};

void prt(pair<pii,pii> pp) {
    const auto [rp, bp] = pp;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            if (pii{y, x} == rp) cout << 'R';
            else if (pii{y, x} == bp) cout << 'B';
            else cout << board.d[y][x];
        }
        cout << '\n';
    }
    cout << '\n';
}

static pii push_one(pii p, pii way) {
    while(board.at(p + way) == '.') p = p + way;
    if (board.at(p + way) == 'O') return SUCC;
    return p;
}

static pair<pii, pii> push_two(pair<pii,pii> pp, pii way) {
    const auto [rp, bp] = pp;

    board.at(rp) = 'R';
    const auto bp_1 = push_one(bp, way);
    board.at(rp) = '.';

    if (bp_1 == SUCC) return {FAIL, {}};

    board.at(bp_1) = 'B';
    const auto rp_1 = push_one(rp, way);
    board.at(bp_1) = '.';

    if (rp_1 == SUCC) {
        const auto bp_2 = push_one(bp_1, way);
        if (bp_2 == SUCC) return {FAIL, {}};
        return {SUCC, {}};
    } else {
        board.at(rp_1) = 'R';
        const auto bp_2 = push_one(bp_1, way);
        board.at(rp_1) = '.';

        if (bp_2 == SUCC) return {FAIL, {}};
        return {rp_1, bp_2};
    }
}
static int ans1(int rem, pair<pii,pii> pp);
static int ans2(int rem, pair<pii,pii> pp);

static int ans1(int rem, pair<pii,pii> pp) {
    if (rem > 10) return INF;
    int res = INF;
    auto o = push_two(pp, {-1, 0});
    if (o.first == SUCC) return rem;
    if (o.first != FAIL) res = min(res, ans2(rem+1, o));
    o = push_two(pp, {1, 0});
    if (o.first == SUCC) return rem;
    if (o.first != FAIL) res = min(res, ans2(rem+1, o));
    return res;
}
static int ans2(int rem, pair<pii,pii> pp) {
    if (rem > 10) return INF;
    int res = INF;
    auto o = push_two(pp, {0, -1});
    if (o.first == SUCC) return rem;
    if (o.first != FAIL) res = min(res, ans1(rem+1, o));
    o = push_two(pp, {0, 1});
    if (o.first == SUCC) return rem;
    if (o.first != FAIL) res = min(res, ans1(rem+1, o));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    pii rp, bp;
    for (int y = 1; y <= n; ++y) for (int x = 1; x <= m; ++x) {
        cin >> board.d[y][x];
        if (board.d[y][x] == 'R') rp = {y, x}, board.d[y][x] = '.';
        else if (board.d[y][x] == 'B') bp = {y, x}, board.d[y][x] = '.';
    }
    int res = min(ans1(1, {rp, bp}), ans2(1, {rp, bp}));
    cout << (res == INF ? -1 : res);
}