#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
#define START_POINT 1
#define pb push_back
#define PLI pair<long long, int>
#define cost first
#define end second
typedef long long ll;

const int SIZE = 100000+1;
ll dis[SIZE];
vector<PLI> vec[SIZE];

const ll INF = 100000000000000;
priority_queue<PLI, vector<PLI>, greater<PLI>> pq;
bool visited[SIZE];
inline void init()
{
    for(int i=0;i<SIZE;i++){
        dis[i] = INF;
        vec[i].clear();
        visited[i] = false;
    }
    while( pq.size() ) pq.pop();
}

// if d[u]+w(u,v) < d[v]
int main(void)
{
    init();
    
    int n, m;
    scanf("%d %d", &n, &m);
    while( m-- ){
        int a, b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        vec[a].pb( make_pair(c, b) );
        vec[b].pb( make_pair(c, a) );
    }

    dis[START_POINT] = 0;
    pq.push( make_pair(0ll, START_POINT) );
    for(int i=2;i<=n;i++)
        pq.push( make_pair(INF, i) );
    while( pq.size() ){
        auto i = pq.top();
        visited[i.second] = true;
        pq.pop();

        // printf("%lld %d\n", i.first, i.second);
        for(auto now: vec[i.second]){
            if( !visited[now.end] && dis[i.second]+now.cost < dis[now.end] ){
                dis[now.end] = dis[i.second]+now.cost;
                pq.push( make_pair(dis[now.end], now.end) );
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)
        ans = max(ans, dis[i]);
        // printf("(%d, %d)\n",i, dis[i]);
    if(ans == INF) puts("-1");
    else printf("%lld\n", ans);
    return 0;
}


