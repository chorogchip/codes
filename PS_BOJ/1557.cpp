#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[4010101];

void sieve(ll n) {
    arr[1] = 1;
    for (ll i = 4; i * i <= n; i += 2) arr[i] = 1;
    for (ll i = 3; i * i <= n; i += 2) if (!arr[i]) {
        for (ll j = i + i; j * j <= n; j += i) {
            if (arr[j] == 0) arr[j] = 1;
            else if (arr[j] > 0) {
                arr[j] += 1;
                for (ll l = j + j; l * l <= n; l += j) arr[l] = -1;
            }
        }
    }

    ll i;
    for (i = 1; i * i <= n; ++i) if (arr[i] == 0 || arr[i] > 1) cout << i << ' ' << arr[i] << '\n';
    for (; i <= n; ++i) if (arr[i] > 1) cout << i << ' ' << arr[i] << '\n';
}

/*
1개 : 4, 9, 16, 25, ... 배수 더함
2개 : 36, ... 배수 뺌
3개 : 36 * 16 ... 배수 더함
4개 : ... 뺌
10만개.
약수의개수 : 매우 적음
2찾음 -> 2의지수 락, 2의배수 마크
3찾음 -> 3의지수 락, 3의배수 마크, 6찾음 (2 * 3)
4 pass
5찾음 -> 5의지수 락, 5의배수 마크, 10,15찾음 (2 * 5, 3 * 5), 30찾음(2 * 3 * 5) : 6에서 발전

마킹한 수 : 유효한 수.
2, 3, 6 이 유효, 2, 3은 소수.
새로 소수 찾을 시 : 기존 유요한 수에 해당 수를 곱한 수를 유효한 수로.
즉 유효한 수의 배수는 유효한 후보.
후보 : 1
유효 : 2
죽음 : -1
소수 : 0

소수(0)를 찾으면 소수 마킹하고 그 배수를 후보로 마킹.
2 : 0 / 4, 6, 8 ... : 1
3 : 0 / 6 : 이미 1이 있으므로 2로 함 / 6의 배수를 죽임
    배수 중 이미 1이나 2가 있는거는 2로, 그 배수를 -1로

단 약수의 개수가 궁금할 수 있음.
1의 경우 : 2개 즉 2가 2개를 뜻함
이미 2인 경우 : 하나 추가.
즉 n이 n개를 뜻함

1 2 3 5 6 7 10 11 13 14 15 17 19 21 22 23
*/

ll getcc(ll n) {
    ll res = 0;
    for (ll i = 1; i * i <= n; ++i) {
        if (arr[i] == 0) res += n / (i * i);
        else if (arr[i] > 1) res += ((arr[i] & 1) * 2 - 1) * (n / (i * i));
    }
    return n - res;
}

ll ans(ll k) {
    sieve(k * 4);
    ll lo = 1, hi = k * 4;
    while(lo < hi) {
        ll md = lo + hi >> 1;
        ll c = getcc(md);
        if (c < k) lo = md + 1;
        else hi = md;
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll k; cin >> k;
    cout << ans(k);
}