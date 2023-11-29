#include<stdio.h>
#include<algorithm>

int arr[1000001];

int main(void) {

    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr + n);
    for (int i = 0; i != n; ++i) {
        printf("%d\n", arr[i]);
    }

    return 0;
}