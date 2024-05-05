#include<vector>
using namespace std;

extern int count_pair(int, int, int);
extern int find_character(int, std::vector<int>);

int guess_palindromicity(int N) {
    if (N == 1) return 1;
    else if (N <= 3) {
        vector<int> v;
        v.push_back(N-1);
        return find_character(0, v);
    }
    int nn = N >> 1;
    int res_1;
    vector<int> v; v.reserve(N);
    for (int i = 1; i < nn; ++i) {
        int counter = N - i - 1;
        int res = count_pair(0, i, counter);
        if (i == 1) res_1 = res;
        if (res == 0) return 0;
        else if (res == 1) {
            v.push_back(i);
            v.push_back(counter);
        }
    }
    return !find_character(0, v) && count_pair(1, N-2, N-1) == res_1;
}
