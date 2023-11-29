#include<cstdio>

int n, topick, ttopick;
char arr[17];
bool isPicked[8];

void get_su_yeol(int picked) {
    if (picked == topick) {
        fwrite(arr, 1, ttopick, stdout);
        return;
    }

    for (int i = 0; i != n; ++i) {
        if (isPicked[i]) continue;
        arr[picked << 1] = i + '1';
        isPicked[i] = true;
        get_su_yeol(picked + 1);
        isPicked[i] = false;
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
    get_su_yeol(0);
}