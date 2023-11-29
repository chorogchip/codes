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

int L, C;
char D[20], CC[20];

void asd(int dpt, int chs) {
    if (dpt == L) {
        int m = 0, j = 0;
        for (int i = 0; i != L; ++i) switch (CC[i]) {
            case 'a': case 'i': case 'e': case 'o': case 'u': ++m; break;
            default: ++j; break;
        }
        if (m < 1 || j < 2) return;
        for (int i = 0; i != L; ++i) cout << CC[i];
        cout << endl;
        return;
    }
    for (int i = chs; i < C; ++i) {
        CC[dpt] = D[i];
        asd(dpt + 1, i + 1);
    }

}

int main() { FAST
    cin >> L >> C;
    fore (i, C) cin >> D[i];
    sort(D, D + C);
    asd(0, 0);
}
