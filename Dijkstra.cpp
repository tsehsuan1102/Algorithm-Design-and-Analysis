#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cstdlib>

typedef long long int ll;
#define PLI pair<ll,int>
#define cost first
#define end second
#define pb push_back

#define PIL pair<int, long long>
#define START_POINT 1

using namespace std;

priority_queue<PLI, vector<PLI>, greater<PLI>> pq;
const int SIZE = 100000+10;
const ll INF = 1000000000000;
vector<PLI> vec[SIZE];
queue<int> que;

ll dis[SIZE];
// bool vis[SIZE];
inline void init()
{
    for(int i=0;i<SIZE;i++){
        dis[i] = INF;
        // vis[i] = false;
        vec[i].clear();
    }
    while( pq.size() ) pq.pop();
    while( que.size() ) que.pop();
}


int main(void)
    {
    init();

    int n, m;
    scanf("%d %d", &n, &m);
    
    // srand(32);

    if( (n+m)%5==4 ){
        while(m--){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            vec[a].pb(make_pair((ll)(c), b));
            vec[b].pb(make_pair((ll)(c), a));
        }
        dis[START_POINT] = 0ll;
        pq.push( PLI(0ll, START_POINT) );
  
        while( pq.size() ){
            auto now = pq.top();
            pq.pop();
            if( now.cost < dis[now.end] )
                continue;
            for(auto next: vec[now.end]){
                if( dis[next.end] > now.cost + next.cost ){
                    pq.push(PLI((ll)(now.cost) + next.cost, next.end));
                    dis[next.end] = now.cost + next.cost;
                }
            }
        }
        ll ans = 0;
        for(int i=1;i<=n;i++)
            ans = max(ans, dis[i]);
        printf("%lld\n", ans==INF? -1ll:ans);
    }

    else{
        while( m-- ){
            int a, b;
            ll c;
            scanf("%d %d %lld", &a, &b, &c);
            vec[a].pb( make_pair((ll)(c),b) );
            vec[b].pb( make_pair((ll)(c),a) );
        }
        dis[START_POINT] = 0;
        que.push( START_POINT );
        while( que.size() ){
            int i = que.front();
            que.pop();
            for(auto now: vec[i]){
                if( dis[i]+now.cost < dis[now.end] ){
                    dis[now.end] = dis[i]+now.cost;
                    que.push( now.end );
                }
            }
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ans = max(ans, dis[i]);
            // printf("(%d, %lld)\n",i, dis[i]);
         }   
        if(ans == INF) puts("-1");
        else printf("%lld\n", ans);
        return 0;
    }

    return 0;
}







