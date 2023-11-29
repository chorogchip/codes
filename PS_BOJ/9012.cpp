#include<cstdio>

int main(void) {

    int n, i = 0;
    char *c, arr[53];

    scanf("%d", &n);
    getchar();

    while (n--) {
        c = arr;
        fgets(arr, 52, stdin);
        while(*c != '\n') {
            if (*(c++) == '(') {
                i++;
            } else {
                if (i-- == 0) {
                    fwrite("NO\n", 1, 3, stdout);
                    goto ASD;
                }
            }
        }
        if (i != 0) {
            fwrite("NO\n", 1, 3, stdout);
        } else {
            fwrite("YES\n", 1, 4, stdout);
        }
        ASD:
        i = 0;
    }

}