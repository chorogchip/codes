#include<bits/stdc++.h>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);

int N;
string arr[20001];

MAIN { FAST
    cin >> N;
    foreach (i, N) cin >> arr[i];
    sort(arr, arr + N, [](string s1, string s2) -> bool {
        return s1.length() != s2.length() ? s1.length() < s2.length() : s1 < s2;
    });
    cout << arr[0] << endl;
    for (int i = 1; i < N; ++i) if (arr[i] != arr[i - 1]) cout << arr[i] << endl;
}