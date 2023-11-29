#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

#include<stack>
int N, A[100100], L[100100], R[100100], RES;

MAIN { FAST
    stack<pair<int, int>> st;
    cin >> N;
    foreach (i, N) cin >> A[i];
    for (int i = 0; i != N; ++i) {
        while(!st.empty() && st.top().second >= A[i]) st.pop();
        if (st.empty()) L[i] = -1;
        else L[i] = st.top().first;
        st.push(make_pair(i, A[i]));
    }
    while(!st.empty()) st.pop();
    for (int i = N - 1; i >= 0; --i) {
        while(!st.empty() && st.top().second >= A[i]) st.pop();
        if (st.empty()) R[i] = N;
        else R[i] = st.top().first;
        st.push(make_pair(i, A[i]));
    }
    for (int i = 0; i != N; ++i)
        RES = max(RES, A[i] * (R[i] - L[i] - 1));
    cout << RES;
}