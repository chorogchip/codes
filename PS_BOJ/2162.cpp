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

struct L {
    int x1, y1, x2, y2;
    int group;
    bool isCollide(const L& l) {

    }
}
int N, S, G[3030], C[3030];
L Ls[3030];
vector<int> group[3030];
vector<int> st;

int main() { FAST
    cin >> N;
    fore (i, N) {
        cin >> Ls[i].x1 >> Ls[i].y1 >> Ls[i].x2 >> Ls[i].y2;
        bool isC = false;
        fore (j, i) if (Ls[i].isCollide(Ls[j]))
            if (isC) group[Ls[i].group].push_back(Ls[j].group),
                     group[Ls[j].group].push_back(Ls[i].group);
            else isC = true, Ls[i].group = Ls[j].group, ++G[Ls[j].group];
        if (!isC) Ls[i].group = ++S, G[S] = 1;
    }
    for (int i = 1; i <= S; ++i) if (!C[i]) {
        C[i] = 1;
        st.push_back(i);
        while (!st.empty()) {
            int o = st.back(); st.pop_back();
            
        }
    }
    cout << S << endl;
}
