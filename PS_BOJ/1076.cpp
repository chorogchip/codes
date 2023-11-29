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

string arr[] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
string S;
long long N;

int main() { FAST
    cin >> S;
    for (int i = 0; i != 10; ++i) if (arr[i] == S) {
        N += i;
        break;
    } N *= 10;
    cin >> S;
    for (int i = 0; i != 10; ++i) if (arr[i] == S) {
        N += i;
        break;
    }
    cin >> S;
    for (long long i = 0, j = 1; i != 10; ++i, j *= 10) if (arr[i] == S) {
        N *= j;
        break;
    }
    cout << N << endl;
}
