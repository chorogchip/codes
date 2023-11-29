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

int A[10], B[10], AS, BS, LW = 'D';

int main() { FAST
    fore (i, 10) cin >> A[i];
    fore (i, 10) cin >> B[i];
    fore (i, 10) {
        if (A[i] > B[i]) AS += 3, LW = 'A';
        else if (A[i] < B[i]) BS += 3, LW = 'B';
        else ++AS, ++BS;
    }
    cout << AS << " " << BS << endl;
    if (AS > BS) cout << "A\n";
    else if (AS < BS) cout << "B\n";
    else cout << (char)LW << endl;
}
