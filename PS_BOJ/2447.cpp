#include<cstdio>

int n;
char arr[4785156];

void solution(int x, int y, int size) {
    if (size == 1) {
        arr[y * (n + 1) + x] = '*';
        return;
    }
    size /= 3;
    solution(x, y, size);
    solution(x + size, y, size);
    solution(x + size + size, y, size);
    solution(x, y + size, size);
    for (int i = y + size; i != y + size + size; ++i) {
        int tmp = i * (n + 1);
        for (int j = x + size; j != x + size + size; ++j) {
            arr[j + tmp] = ' ';
        }
    }
    solution(x + size + size, y + size, size);
    solution(x, y + size + size, size);
    solution(x + size, y + size + size, size);
    solution(x + size + size, y + size + size, size);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        arr[i * (n + 1) + n] = '\n';
    }
    solution(0, 0, n);
    fwrite(arr, 1, n * (n + 1), stdout);
}