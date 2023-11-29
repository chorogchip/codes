#include<stdio.h>
#include<algorithm>

constexpr int NN = 1000000;

int arr[NN + 1];
int n, m, x;

// search that data exists in arr by binary search
bool isNumIn(int num) {
    int lo = 0, hi = n - 1, md;
    while (lo < hi) {
        md = (lo + hi) / 2;
        if (num > arr[md]) {
            lo = md + 1;
        } else {
            hi = md;
        }
    }
    return arr[lo] == num;
}

int main() {

    scanf("%d" , &n);
    for (int i = 0; i != n; ++i) {
        scanf("%d", arr + i);
    }
    std::sort(arr, arr + n);
    scanf("%d", &m);
    for (int i = 0; i != m; ++i) {
        scanf("%d", &x);
        putchar('0' + isNumIn(x));
        putchar('\n');
    }
    return 0;
}