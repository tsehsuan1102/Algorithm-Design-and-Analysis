#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

#define PII pair<int, int>
#define rank first
#define c second
#define pb push_back

const int SIZE = 200000+10;
using namespace std;

int str[SIZE];
int ans[SIZE];
bool vis[SIZE];
vector<PII> vec;

inline void init()
{
    vec.clear();
    for(int i=0;i<SIZE;i++)
        ans[i]=0, vis[i] = false;
}
int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--){
        init();

        int n, k;
        scanf("%d %d", &n, &k);
        for(int i=0;i<n;i++)
            scanf("%d", str+i);
        for(int i=0;i<n;i++){
            int rk;
            scanf("%d", &rk);
            vec.pb( PII(rk, str[i]) );
        }

        sort(vec.begin(), vec.end());
        // puts("!");
        int nowrank = 0;
        for(int i=0;i<n;i++){
            if( !vis[vec[i].c] ){
                vis[vec[i].c] = true;
                ans[nowrank++] = vec[i].c;
            }
        }
        printf("%d", ans[0]);
        for(int i=1;i<nowrank;i++)
            printf(" %d", ans[i]);
        for(int i=1;i<=k;i++){
            if( vis[i]==false )
                printf(" %d",i);
        }
        puts("");
    }

    return 0;
}









