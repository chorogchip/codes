#include<cstdio>
#include<algorithm>

#define getd(x) scanf("%d", (x))
#define prtd(x) printf("%d\n", (x))
#define prtds(x, y) for (int asdf = 0; asdf != (x); ++asdf) printf("%d ", (y)[asdf]); putchar('\n');
#define foreach(x, y) for (int x = 0; x != (y); ++x)

struct disSt {
    int target;
    int money;
};

int n, cost[10], disC[10], order[10], res = 2145674567;;
disSt *dis[10];

void sol() {
    do {
        int sum = 0, costL[10];
        foreach(i, n) costL[i] = cost[i];
        foreach(i, n) {
            int target = order[i];
            sum += costL[target];
            foreach(j, disC[target]) {
                int targettarget = dis[target][j].target - 1;
                costL[targettarget] -= dis[target][j].money;
                costL[targettarget] = std::max(1, costL[targettarget]);
            }
        }
        res = std::min(res, sum);
    } while (std::next_permutation(order, order + n));
}

int main() {
    getd(&n);
    foreach(i, n) getd(cost + i);
    foreach(i, n) {
        getd(disC + i);
        dis[i] = new disSt[disC[i]];
        foreach(j, disC[i]) {
            getd(&dis[i][j].target);
            getd(&dis[i][j].money);
        }
        order[i] = i;
    }
    sol();
    prtd(res);
}
