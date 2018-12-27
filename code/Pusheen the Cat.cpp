#include <cstdio>
#include <map>

using namespace std;

map<int,int> mp;
void sol(int x)
{
    int ans = 0, now = 0;
    int fix = 0, pre = -1;
    bool first = true;
    while(x){
        int lsb = x&(-x);
        int pos = mp[lsb];
        ans += pos-now+1;
        now = pos;
        if( first && pos-pre == 1 )
            now++, pre = pos;
        else first = false;
        x-=lsb;
    }
    if( fix>0 ) ans++, ans-=fix;
    printf("%d\n",ans);
}

const int SIZE = 1000000000;
void build()
{
    int now = 1;
    int id = 0;
    while( now<SIZE ){
        mp[now] = id;
        now*=2;
        id++;
    }
}
int main (void)
{
    build();

    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        sol(N);
    }
    return 0;
}





