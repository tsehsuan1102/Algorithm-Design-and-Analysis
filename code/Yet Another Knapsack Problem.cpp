//reference: https://blog.csdn.net/LYHVOYAGE/article/details/39889311
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#define PLL pair<long long,long long>
#define weight first
#define value second
using namespace std;

const int SIZE = 42;
typedef long long ll;
int n;
ll W;
ll v[SIZE], w[SIZE];

PLL dp[1<<(SIZE/2)]; 
//pair(weight, value)
const ll INF = 10000000000000;

void solve()
{
    int mid = n>>1;
    //enumerate the first half items(0~mid)
    for(int i=0;i < (1<<mid);i++){
        ll tmpw = 0ll, tmpv = 0ll;
        for(int j=0;j<mid;j++){
            if( i & (1ll<<j) ){
                tmpw += w[j];
                tmpv += v[j];
            }
        }
        dp[i] = make_pair(tmpw, tmpv);
    }

    // sort by weight
    sort(dp, dp+(1<<mid));
    //remove the items whose weight more but with less value.
    int index = 1;
    for(int i=1;i < (1<<mid);i++){
        if(dp[i].value > dp[index-1].value){
            dp[index++] = dp[i];
        }
    }

    ll ans = 0;
    //enumerate the last half items(mid~n)
    int N2 = n-mid;
    for(int i=0;i < (1<<N2);i++){
        ll tmpw = 0, tmpv = 0;
        for(int j=0;j<N2;j++){
            if( i & (1<<j) ){
                tmpw += w[mid + j];
                tmpv += v[mid + j];
            }
        }
        if( tmpw <= W ){
            //binary search -> find the item whose weight is less than or equal to W-tmpw 
            int id = (upper_bound(dp, dp+index, make_pair(W - tmpw, INF))-1-dp );
            ans = max(ans, dp[id].value + tmpv);
        }
    }
    printf("%lld\n", ans);
}

int main(void)
{
    scanf("%d %lld", &n, &W);
    for(int i=0;i<n;i++)
        scanf("%lld %lld", v+i, w+i);
    solve();
    return 0;
}


/*
4 5
1 2
3 4
5 3
4 1
*/


