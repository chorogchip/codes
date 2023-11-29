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

int N, R1, R2, C[101010], X;
char D[101010], CO, CO2;
vector<pair<int,int>> st;

int main() {
    scanf("%d", &N); getchar();
    fore (i, N) {
        fore (j, N) D[i * N + j] = getchar();
        getchar();
    }
    fore (i, N) fore (j, N) if (!C[X = i * N + j]) {
        CO = D[X];
        C[X] = 1;
        st.push_back(make_pair(i, j));
        ++R1;
        while (!st.empty()) {
            auto o = st.back(); st.pop_back();
            if (o.first-1>=0&&!C[X=(o.first-1)*N+o.second]&&D[X]==CO)
                C[X]=1,st.push_back(make_pair(o.first-1,o.second));
            if (o.first+1< N&&!C[X=(o.first+1)*N+o.second]&&D[X]==CO)
                C[X]=1,st.push_back(make_pair(o.first+1,o.second));
            if (o.second-1>=0&&!C[X=o.first*N+o.second-1 ]&&D[X]==CO)
                C[X]=1,st.push_back(make_pair(o.first,o.second-1));
            if (o.second+1< N&&!C[X=o.first*N+o.second+1 ]&&D[X]==CO)
                C[X]=1,st.push_back(make_pair(o.first,o.second+1));
        }
    }
    fore (i, N) fore (j, N) if (C[X = i * N + j]) {
        CO = D[X];
        CO2 = CO ^ 'R' ^ 'G';
        C[X] = 0;
        st.push_back(make_pair(i, j));
        ++R2;
        while (!st.empty()) {
            auto o = st.back(); st.pop_back();
            if (o.first-1>=0&&C[X=(o.first-1)*N+o.second]&&(D[X]==CO||D[X]==CO2))
                C[X]=0,st.push_back(make_pair(o.first-1,o.second));
            if (o.first+1< N&&C[X=(o.first+1)*N+o.second]&&(D[X]==CO||D[X]==CO2))
                C[X]=0,st.push_back(make_pair(o.first+1,o.second));
            if (o.second-1>=0&&C[X=o.first*N+o.second-1 ]&&(D[X]==CO||D[X]==CO2))
                C[X]=0,st.push_back(make_pair(o.first,o.second-1));
            if (o.second+1< N&&C[X=o.first*N+o.second+1 ]&&(D[X]==CO||D[X]==CO2))
                C[X]=0,st.push_back(make_pair(o.first,o.second+1));
        }
    }
    cout << R1 << " " << R2 << endl;
}
