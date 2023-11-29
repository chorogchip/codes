#include<cstdio>

char arr[400001], *p = arr;
int n, num, tnum = 0;
bool brr[100001] = {0, };

// 따로 입력 함수 사용
int getInt() {
    char c;
    int num = 0;
    while((c = getchar()) != '\n') {
        num *= 10;
        num += (c - '0');
    }
    return num;
}

int main(void) {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i != n; ++i) {
        num = getInt();
        if (num > tnum) {
            // 이미 뺀 수 패스
            while (brr[++tnum]);
            --tnum;
            // 안뺀수는 스택에 넣기
            for (int j = 0; j != num - tnum; ++j) {
                *(p++) = '+';
                *(p++) = '\n';
            }
            // 해당 수 방금전 넣었다가 아래에서 뺌
            *(p++) = '-';
            *(p++) = '\n';
            brr[num] = 1;
            tnum = num;
            // 이미 뺀 수 패스
            while (brr[--tnum]);
        } else {
            if (num == tnum) {
                *(p++) = '-';
                *(p++) = '\n';
                brr[num] = 1;
                // 이미 뺀 수 패스
                while (brr[--tnum]);
            } else {
                fwrite("NO\n", 1, 3, stdout);
                return 0;
            }
        }
    }

    fwrite(arr, 1, n << 2, stdout);
}