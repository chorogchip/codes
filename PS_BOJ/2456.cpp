#include<bits/stdc++.h>
using namespace std;

int a[4][4];
bool cmp(int x, int y) {
    if (a[x][0] != a[y][0]) return a[x][0] > a[y][0];
    else if (a[x][3] != a[y][3]) return a[x][3] > a[y][3];
    else if (a[x][2] != a[y][2]) return a[x][2] > a[y][2];
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;  cin >> n;
    while(n--) {
        int x, y, z; cin >> x >> y >> z;
        a[1][x]++; a[2][y]++; a[3][z]++;
    }
    for (int i =1; i <= 3; ++i)
        a[i][0] = a[i][1] + a[i][2]*2 + a[i][3]*3;
    int cmp_1 = cmp(1, 2) + cmp(1, 3);
    int cmp_2 = cmp(2, 1) + cmp(2, 3);
    int cmp_3 = cmp(3, 1) + cmp(3, 2);
    if (cmp_1 == 2) cout << 1 << ' ' << a[1][0];
    else if (cmp_2 == 2) cout << 2 << ' ' << a[2][0];
    else if (cmp_3 == 2) cout << 3 << ' ' << a[3][0];
    else if (cmp_1 == cmp_2) cout << 0 << ' ' << a[1][0];
    else if (cmp_2 == cmp_3) cout << 0 << ' ' << a[2][0];
    else if (cmp_3 == cmp_1) cout << 0 << ' ' << a[1][0];
}