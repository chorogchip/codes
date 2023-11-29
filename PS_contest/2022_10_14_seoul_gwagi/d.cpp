#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
int C[26][26];
int R[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        char a, b; cin >> a >> b;
        ++C[a-'A'][b-'A'];
    }
    for (int i1 = 0; i1 < 26; ++i1)
    for (int i2 = 0; i2 < 26; ++i2)
    if (C[i1][i2])
    for (int i3 = 0; i3 < 26; ++i3)
    for (int i4 = 0; i4 < 26; ++i4)
    if (C[i3][i4])
    if (i1 == i3 && i2 == i4) {
        if (C[i1][i2] > 1) {
            R[max(i1, i2)] = 1;
        }
    } else {
        R[max(i1, i4)] = 1;
        R[max(i2, i3)] = 1;
    }
    int sum = 0;
    for (char i : R) if (i) ++sum;
    cout << sum << '\n';
    for (int i = 0; i < 26; ++i) if (R[i])
    cout << (char)(i+'A') << ' ';

}