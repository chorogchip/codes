#include<cstdio>
#include<algorithm>

int n, s, cnt = 0, arr[20];

inline void sol() {
    for (int i = 1; i != (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j != n; ++j)
            if (i & (1 << j)) sum += arr[j];
        if (sum == s) cnt++;
    }
}

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 0; i != n; ++i) {
        scanf("%d", arr + i);
    }
    sol();
    printf("%d", cnt);
}