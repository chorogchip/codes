#include<cstdio>

int n, nn;
char arr[1 << 22], *p = arr;

void hanoi(char from, char to, char other, int num) {
    if (num == 1) {
        *p++ = from;
        *p++ = ' ';
        *p++ = to;
        *p++ = '\n';
        return;
    }
    hanoi(from, other, to, num - 1);
    *p++ = from;
    *p++ = ' ';
    *p++ = to;
    *p++ = '\n';
    hanoi(other, to, from, num - 1);
}

int main() {
    scanf("%d", &n);
    nn = (1 << n) - 1;
    printf("%d\n", nn);
    hanoi('1', '3', '2', n);
    fwrite(arr, 1, nn << 2, stdout);
}