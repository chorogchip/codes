#define TEMM
#ifdef TEMM
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
struct Pos {int x,y;};
typedef long long ll;
typedef vector<int> vi;
typedef vector<Pos> vp;
constexpr int INF = 1000*1000*1000;
using namespace std;
#endif


int N, M;
#include<set>
set<int> st;
vector<pair<char,int>> bb;
char C, CC[100]; int X;

int main() { FAST
    cin >> N >> M; N <<= 1;
    for (int i = 1; i <= N; ++i) st.insert(i);
    bb.reserve(M);
    fore (i, M) {
        cin >> C >> CC >> X;
        bb.emplace_back(C, X);
        st.erase(X);
    }
    for (int i = 1; i != bb.size(); ++i) if (bb[i-1].first == bb[i].first) {
        auto xx = st.lower_bound(it->second);
        if (xx != st.end()) {
            bb[i].first ^= 'A' ^ 'B';
            bb[i].second = *xx;
            st.erase(xx);
        } else goto NO;
    }
    
    YES: cout << "YES\n";

    return;
    NO: cout << "NO\n";

}
