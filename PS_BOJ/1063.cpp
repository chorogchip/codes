#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int KX, KY, SX, SY, N, MX, MY;
char c1, c2;

int main() {
    c1 = getchar(); c2 = getchar();
    KX = c1 - 'A'; KY = c2 - '1';
    getchar();
    c1 = getchar(); c2 = getchar();
    SX = c1 - 'A'; SY = c2 - '1';
    getchar();
    scanf("%d", &N);
    getchar();
    fore (i, N) {
        c1 = getchar(); c2 = getchar();
        if (c2 != '\n') {
            getchar();
            if (c1 == 'L')
                if (c2 == 'B') MX = -1, MY = -1;
                else MX = -1, MY = 1;
            else
                if (c2 == 'B') MX = 1, MY = -1;
                else MX = 1, MY = 1;
        } else switch (c1) {
            case 'L': MX = -1, MY = 0; break;
            case 'R': MX = 1, MY = 0; break;
            case 'B': MX = 0, MY = -1; break;
            case 'T': MX = 0, MY = 1; break;
        }
        int NKX = KX + MX, NKY = KY + MY;
        if (NKX >= 0 && NKX < 8 && NKY >= 0 && NKY < 8) {
            if (NKX == SX && NKY == SY) {
                int NSX = SX + MX, NSY = SY + MY;
                if (NSX >= 0 && NSX < 8 && NSY >= 0 && NSY < 8)
                    KX = NKX, KY = NKY, SX = NSX, SY = NSY;
            } else KX = NKX, KY = NKY;
        }
    }
    cout << (char)(KX + 'A') << (char)(KY + '1') <<
    endl << (char)(SX + 'A') << (char)(SY + '1') << endl;
}
