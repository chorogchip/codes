#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using piii = pair<pii, pii>;
#define x first
#define y second

int asd(int al, int ar, int bl, int br) {
    if (ar < bl || br < al) return 0;
    if (ar == bl || br == al) return 1;
    return 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    piii a, b;
    cin >> a.x.x >> a.x.y >> a.y.x >> a.y.y;
    cin >> b.x.x >> b.x.y >> b.y.x >> b.y.y;
    int xx = asd(a.x.x, a.y.x, b.x.x, b.y.x);
    int yy = asd(a.x.y, a.y.y, b.x.y, b.y.y);
    if (xx * yy == 0) cout << "NULL";
    else if ((xx & yy) == 1) cout << "POINT";
    else if ((xx | yy) == 3) cout << "LINE";
    else cout << "FACE";
}