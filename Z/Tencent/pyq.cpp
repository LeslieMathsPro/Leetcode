#include <iostream>
#include <vector>
using namespace std;

#define PERSON_NUM 100001

struct UF {
    vector<int> pa = vector<int> (PERSON_NUM);
    vector<int> cnt = vector<int> (PERSON_NUM, 1);

    UF() {
        for(int i = 1; i < PERSON_NUM; ++i) {
            pa[i] = 1;
        }
    }

    int find(int x){
        if(pa[x] != x) return pa[x] = find(pa[x]);
    }

    int join(int x, int y){
        int px = find(x), py = find(y);
        if (px != py) { //去重
            pa[px] = py;
            cnt[py] += cnt[px];
        }
        return py;
    }
};


int main(){
    int T, n, x, y, ans;
    scanf("%d", &T);
    while(T--){
        struct UF uf_;
        ans = 1;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i){
            scanf("%d%d", &x, &y);
            int py = uf_.join(x, y);
            ans = max(ans, uf_.cnt[py]);
        }
        printf("%d\n", ans);
    }
}