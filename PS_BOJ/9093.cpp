#include<iostream>
#include<string>

char word[21];
char sentence[1001];

// 단어 거꾸로 출력
inline void printReversedWord(char* word, int length) {
    for (int i = length - 1; i >= 0; --i) {
        putchar(word[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i != n; i++) {

        char* cc = sentence;
        while((*(cc++) = getchar()) != '\n');
        *(--cc) = '\0';

        char c;
        int j = 0;  // 한 문장의 몇 번째 글자인지
        int k = 0;  // 한 단어의 몇 번째 글자인지
        while (1) {
            c = sentence[j++];
            if (c == '\0') {
                printReversedWord(word, k);
                putchar('\n');
                break;
            } else if (c == ' ') {
                printReversedWord(word, k);
                putchar(' ');
                k = 0;
            } else {
                word[k++] = c;
            }
        }
    }
    return 0;
}
