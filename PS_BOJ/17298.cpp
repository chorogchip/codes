#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'


#include<stack>

int N, A[1001001];

MAIN { FAST
    stack<int> st;
    cin >> N;
    foreach (i, N) cin >> A[i];
    for (int i = N - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= A[i]) st.pop();
        A[i + 1] = st.empty() ? -1 : st.top();
        st.push(A[i]);
    }
    for (int i = 1; i <= N; ++i) cout << A[i] << ' ';
}