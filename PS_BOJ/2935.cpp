#include<bits/stdc++.h>
using namespace std;

int main() {
    char c; int a = 0, b = 0;
    getchar();
    while((c = getchar(), c == '0')) ++a;
    char op = getchar(); getchar();
    getchar();
    while((c = getchar(), c == '0')) ++b;
    if (op == '*') {
        putchar('1');
        for (int i = 0; i < a + b; ++i) putchar('0');
    } else {
        if (a == b) {
            putchar('2');
            for (int i = 0; i < a; ++i) putchar('0');
        } else {
            if (a > b) swap(a, b);
            putchar('1');
            for (int i = 0; i < b - a - 1; ++i) putchar('0');
            putchar('1');
            for (int i = 0; i < a; ++i) putchar('0');
        }
    }
}