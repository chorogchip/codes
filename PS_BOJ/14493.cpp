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

int N, R, A, B;

int main() { FAST
    cin >> N;
    fore (i, N) {
        cin >> A >> B;
        int rem = R % (A + B);
        if (rem >= B) ++R;
        else R += B - rem + 1;
    }
    cout << R << endl;
}
