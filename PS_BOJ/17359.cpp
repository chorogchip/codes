#include<cstdio>
#include<algorithm>

int n;
struct num {
    char stt, fin;
};
int ans = 2134563456, cnt = 0;
num arr[10];

void sol() {
    std::sort((short*)arr, (short*)(arr + n));
    do {
        int ccnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i].fin != arr[i + 1].stt)
                ccnt++;
        }
        ans = std::min(ans, ccnt);
    } while (std::next_permutation((short*)arr, (short*)(arr + n)));
}

int main() {
    scanf("%d", &n);
    getchar();
    char c;
    for (int i = 0; i != n; ++i) {
        char prev;
        bool isFirst = true;
        while((c = getchar()) != '\n') {
            if (isFirst) {
                arr[i].stt = c;
                arr[i].fin = c;
                isFirst = false;
            } else {
                arr[i].fin = c;
                if (prev != c)
                    cnt++;
            }
            prev = c;
        }
        
    }
    sol();
    printf("%d", ans + cnt);
}