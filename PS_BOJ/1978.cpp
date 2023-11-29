#include<iostream>
#include<algorithm>

using namespace std;

#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define LL long long
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);

int arr[1001] = { 1, 1 }, n, num, sum = 0;

void sieve(int cnt) {
    int temp;
    for (int i = 2; (temp = i * i) <= cnt; ++i)
        if (!arr[i]) for (int j = temp; j <= cnt; j += i) arr[j] = 1;
}

MAIN { FAST
    cin >> n;
    sieve(1000);
    foreach(i, n) {
        cin >> num;
        if (!arr[num]) sum++;
    }
    cout << sum;
}