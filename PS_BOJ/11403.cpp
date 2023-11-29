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

int N;
char c;
vector<int> G[101];
char arr[103*103*2];
vector<int>st;

int main() {
    scanf("%d", &N); getchar();
    st.reserve(N);
    for (int i = 0; i != N; ++i)
        for (int j = 0; j != N; ++j) {
            c = getchar();
            if (c == '1') G[i].push_back(j);
            getchar();
        }
    fore (i, N) {
        for (int j = 0; j  != N - 1; ++j)
            arr[(i * N + j) << 1] = '0',
            arr[((i * N + j) << 1) + 1] = ' ';
        arr[((i * N + N - 1) << 1)] = '0';
        arr[((i * N + N - 1) << 1) + 1] = '\n';
    }
    for (int i = 0; i != N; ++i) {
        st.push_back(i);
        while (!st.empty()) {
        auto o = st.back(); st.pop_back();
            for (auto oo : G[o]) if (arr[(i * N + oo) << 1] == '0') {
                arr[(i * N + oo) << 1] = '1';
                st.push_back(oo);
            }
        }
    }
    fwrite(arr, 1, N * N << 1, stdout);
}
