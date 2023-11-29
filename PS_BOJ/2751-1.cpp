#include<cstdio>
#include<algorithm>

int n;
constexpr int NN = 1000000;
char crr[NN << 4], *p = crr, *p2 = crr;
int irr[NN + 1], *ip = irr, remain;

void readInt() {
    int ret = 0;
    char c;
    bool minus = false;
    while (true) {
        switch (c = *p2++) {
            case '-':
                minus = true;
                continue;
            case '\n':
                if (minus) *ip++ = -ret;
                else       *ip++ =  ret;
                minus = false;
                ret = 0;
                remain--;
                continue;
            case '\0':
                while(*--p2 != '\n');
                p2++;
                return;
            default:
                ret *= 10;
                ret += c - '0';
                continue;
        }
    }
}

inline void read() {
    scanf("%d", &n);
    getchar();
    remain = n;
    while (remain) {
        fread(p, 1, (remain << 1) - 1, stdin);
        p += (remain << 1) - 1;
        *(p + 1) = '\0';
        readInt();
    }
}

void writeInt(int num) {
    if (num < 0) {
        *p++ = '-';
        num = -num;
    }
    int nnn = 1000000;
    while (nnn > num && nnn >= 10) nnn /= 10;
    do {
        *p++ = (num / nnn) % 10 + '0';
    } while (nnn /= 10);
    *p++ = '\n';
}

inline void write() {
    p = crr;
    for (int i = 0; i != n; ++i) writeInt(irr[i]);
    fwrite(crr, 1, p - crr, stdout);
}

int main(void) {
    read();
    std::sort(irr, irr + n);
    write();
    return 0;
}