#include<cstdio>
#include<algorithm>

int n, arr[8], ss = 0;

void sol() {
    std::sort(arr, arr + n);
    do {
        int aaa = 0;
        for (int i = 0; i != n - 1; ++i) {
            aaa += std::abs(arr[i] - arr[i + 1]);
        }
        ss = std::max(aaa, ss);
    } while (std::next_permutation(arr, arr + n));
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        scanf("%d", arr + i);
    }
    sol();
    printf("%d", ss);
}