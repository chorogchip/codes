#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int N;
#include<queue>
queue<int> qu;

MAIN { FAST
    string str;
    int num;
    cin >> N;
    foreach (i, N) {
        cin >> str;
        if (str == "push") {
            cin >> num;
            qu.push(num);
        }
        else if (str == "pop")
            if (qu.empty()) cout << -1 << endl;
            else cout << qu.front() << endl, qu.pop();
        else if (str == "size") cout << qu.size() << endl;
        else if (str == "empty") cout << qu.empty() << endl;
        else if (str == "front")
            if(qu.empty()) cout << -1 << endl;
            else cout << qu.front() << endl;
        else if (str == "back")
            if (qu.empty()) cout << -1 << endl;
            else cout << qu.back() << endl;
    }
}