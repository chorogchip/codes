#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define LL long long
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int n, arr[1000001], arrs[1000001];

MAIN { FAST
    cin >> n;
    arr[1] = 0; arrs[1] = -1;
    for (int i = 2; i <= n; ++i) {
        arr[i] = arr[i - 1] + 1;
        arrs[i] = i - 1;
        if (i % 3 == 0 && arr[i / 3] + 1 < arr[i]) {
            arr[i] = arr[i / 3] + 1;
            arrs[i] = i / 3;
        }
        if ((i & 1) == 0 && arr[i >> 1] + 1 < arr[i]) {
            arr[i] = arr[i >> 1] + 1;
            arrs[i] = i >> 1;
        }
    }
    cout << arr[n] << endl;
    int i = n;
    do cout << i << " ", i = arrs[i];
    while (i != -1);
}