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

typedef unsigned long long ull;
constexpr ull M = 1000000007ULL;
class MM {
public:
    ull a, b, c, d;
    MM(ull a_, ull b_, ull c_, ull d_): a(a_), b(b_), c(c_), d(d_) {}
    MM operator* (const MM& mm) {
        return MM((a*mm.a+b*mm.c)%M,
                  (a*mm.b+b*mm.d)%M,
                  (c*mm.a+d*mm.c)%M,
                  (c*mm.b+d*mm.d)%M);
    }
};

int main() { FAST
    ull N;
    cin >> N;
    MM a(1, 1, 1, 0), b(1, 0, 0, 1);
    do {
        if (N & 1) b = b * a;
        a = a * a;
    } while (N >>= 1);
    cout << b.b << endl;
}
