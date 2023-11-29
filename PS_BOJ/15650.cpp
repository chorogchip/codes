#include<cstdio>

int n, topick, ttopick;
char arr[17];

void get_su_yeol(int picked, int prev) {
    if (picked == topick) {
        fwrite(arr, 1, ttopick, stdout);
        return;
    }

    for (int i = prev + 1; i < n; ++i) {
        arr[picked << 1] = i + '1';
        get_su_yeol(picked + 1, i);
    }
}

int main(void) {
    scanf("%d %d", &n, &topick);
    ttopick = topick << 1;
    for (int i = 1; i < 17; i += 2) {
        arr[i] = ' ';
    }
    arr[ttopick] = '\n';
    ttopick++;
    get_su_yeol(0, -1);
}