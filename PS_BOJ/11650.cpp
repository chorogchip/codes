#include<stdio.h>
#include<algorithm>


struct pos {
    int x, y;
};

struct pos arr[1000001];

bool poscmp(struct pos& a, struct pos& b) {
    if (a.x != b.x) {
        return a.x < b.x;
    } else {
        return a.y < b.y;
    }
}
int main(void) {

    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    std::sort(arr, arr + n, poscmp);
    for (int i = 0; i != n; ++i) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }

    return 0;
}