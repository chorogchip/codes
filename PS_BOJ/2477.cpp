#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, X, Y, A, B;;
pair<int,int> poss[6];

main() { FAST

    cin >> N;
    fore(i,6) {
        cin >> A >> B;
        poss[i] = make_pair(X, Y);
        switch(A) {
            case 1: X += B; break;
            case 2: X -= B; break;
            case 3: Y += B; break;
            case 4: Y -= B; break;
        }
    }
    int maxx = -9999999, minx = 9999999, maxy = -9999999, miny = 9999999;
    fore (i, 6) {
        maxx = max(maxx, poss[i].first);
        minx = min(minx, poss[i].first);
        maxy = max(maxy, poss[i].second);
        miny = min(miny, poss[i].second);
    }
    fore (i, 6) if (poss[i].first != maxx && poss[i].first != minx &&
                    poss[i].second != maxy && poss[i].second != miny) {
        A = i + 1; if (A >= 6) A -= 6;
        B = i - 1; if (B < 0) B += 6;
        break;
    }
    cout << N * (
        (maxx - minx) * (maxy - miny) -
        abs((poss[A].first - poss[B].first) * (poss[A].second - poss[B].second))
    );

}