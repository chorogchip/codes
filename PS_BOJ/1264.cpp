#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;

string C;

int main() {
    while (true) {
        char c;
        int S = 0;
        getline(cin, C);
        if (C[0] == '#') break;

        for (int i = 0; c = C[i]; ++i) {
            c |= ' ';
            if (c == 'i' || c == 'a' ||
            c == 'e' || c == 'o' || c == 'u') ++S; 
        }
        cout << S << endl;
    }    
}
