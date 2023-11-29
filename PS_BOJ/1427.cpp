#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

vector<char> v;

main() { FAST

    char c;
    while ((c = getchar()) != '\n') v.push_back(c);
    sort(v.begin(), v.end());
    while (!v.empty()) putchar(v.back()), v.pop_back();


}