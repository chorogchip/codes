#include<stdio.h>
#include<algorithm>

int n, arr[100001], ansA, ansB, ansRes = 2012012012;

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i != n; ++i) {
        scanf("%d", arr + i);
    }
    if (n == 2) {

    }
    std::sort(arr, arr + n);
    for (int i = 0; i < n - 1; ++i) {
        int lo = i + 1, hi = n - 1, md;
        while (lo < hi) {
            md = (lo + hi) >> 1;
            if (arr[i] + arr[md] < 0) {
                lo = md + 1;
            } else {
                hi = md;
            }
        }
        int val = std::abs(arr[i] + arr[lo]);
        if (ansRes > val) {
            ansRes = val;
            ansA = i;
            ansB = lo;
        }
        if (lo != i + 1) {
            val = std::abs(arr[i] + arr[lo - 1]);
            if (ansRes > val) {
                ansRes = val;
                ansA = i;
                ansB = lo - 1;
            }
        }
    }
    printf("%d %d\n", arr[ansA], arr[ansB]);
    return 0;
}