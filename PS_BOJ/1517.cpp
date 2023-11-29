#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define LL long long
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'


struct Node {
    Node(int numb) : number(numb) {}
    int number;
    int count = 0;
    Node* smaller = nullptr;
    Node* bigger = nullptr;
    
    void print(int ind) {
        printSp(ind); putchar('{'); putchar('\n'); printSp(ind + 2);
        printf("%d %d\n", number, count);
        if (smaller) smaller->print(ind + 2); else printSp(ind + 2), putchar('x'), putchar('\n');
        if (bigger) bigger->print(ind + 2); else printSp(ind + 2), putchar('x'), putchar('\n');
        printSp(ind);
        printf("}\n");
    }
    static void printSp(int ind) { foreach (i, ind + 2) putchar(' '); }
    
};

class Tree {
    private:
    Node* node;

    public:
    Tree() { node = new Node(1073741824); }
    void print() { node->print(0); }

    int insert_and_count(int num) {
        int aaa = 1073741824;
        int res = 0;
        Node* nd = node;
        while (nd->number != num) {
            aaa >>= 1;
            if (nd->number < num) {
                if (nd->bigger == nullptr)
                    nd->bigger = new Node(nd->number + aaa);
                nd->count++;
                nd = nd->bigger;
            } else {
                if (nd->smaller == nullptr)
                    nd->smaller = new Node(nd->number - aaa);
                res += nd->count - nd->smaller->count;
                nd->count++;
                nd = nd->smaller;
            }
        }
        if (nd->bigger) res += nd->bigger->count;
        nd->count++;
        return res;
    }
};

int n, x;
long long rres = 0LL;

MAIN { FAST
    cin >> n;
    Tree tree = Tree();
    while (--n >= 0) cin >> x, rres += tree.insert_and_count(x + 1073741824);
    cout << rres;
}