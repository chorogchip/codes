#include<cstdio>
#include<algorithm>

int n, nn, arr1[4001], arr2[4001], arr3[4001], arr4[4001],
brr1[16123123], brr2[16123123], *p1 = brr1, *p2 = brr2;
long long res = 0LL;

void sol() {
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j) {
            *p1++ = arr1[i] + arr2[j];
            *p2++ = -arr3[i] - arr4[j];
        }
    std::sort(brr1, brr1 + nn);
    std::sort(brr2, brr2 + nn);
    p1 = brr1;
    p2 = brr2;
    while (p1 < brr1 + nn && p2 < brr2 + nn) {
        if (*p1 == *p2) {
            long long a = 1LL, b = 1LL;
            while (++p1 < brr1 + nn && *p1 == *p2) a++; p1--;
            while (++p2 < brr2 + nn && *p1 == *p2) b++; p1++;
            res += a * b;
        }
        else if (*p1 < *p2) p1++;
        else p2++;
    }
}

int main() {
    scanf("%d", &n);
    nn = n * n;
    for (int i = 0; i != n; ++i)
        scanf("%d %d %d %d", arr1 + i, arr2 + i, arr3 + i, arr4 + i);
    sol();
    printf("%lld", res);
}