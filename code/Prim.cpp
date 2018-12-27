#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

#define PII pair<int,int>
#define pb push_back
using namespace std;


const int SIZE = 1024+10;
typedef struct{
    int end;
    int prize;
    int cost;
}Edge;

vector<Edge> vec[SIZE];

int prize[SIZE][SIZE];
int cost[SIZE][SIZE];
bool vis[SIZE];

struct compare{
    bool operator() (const Edge& p1,const Edge& p2 ){
         if( p1.cost == p2.cost ){
            return p1.prize < p2.prize;
         }else return p1.cost > p2.cost;
    }
};
int gcd(int a, int b){
    while( (a%=b) && (b%=a) );
    return a+b;
}


priority_queue<Edge, vector<Edge>, compare> pq;
void init()
{
    while(pq.size()) pq.pop();
    for(int i=0;i<SIZE;i++)
        vec[i].clear(), vis[i]=false;
}








double prim(double mid)
{
    double P = 0, Q = 0;

    for(int i=0;i<SIZE;i++) vis[i] = false;
    vis[0] = true;
    

    if( pq.size() ){
            Edge now = pq.top();
            pq.pop();
            if( vis[now.end] == false ){ d
                ansPrize += now.prize;
                ansCost += now.cost;
                vis[now.end] = true;
                cnt++;
                for(auto next: vec[now.end]){
                    pq.push(next);
                }
            }else{
                continue;
            }
        }else{
            puts("error");
        }
}

    foru(i,2,n) {
        dis[i] = cost[1][i]-dist[1][i]*p;
        pre[i] = 1;
    }
 
    double Cost = 0, Len = 0;
    for0(i,n-1){
        double Mincost = INF;
        int k = -1;
        for1(j,n){
            if(!vis[j] && dis[j]<Mincost){
                Mincost = dis[k=j];
            }
        }
        if(k==-1) break;
        vis[k] = 1;
        Cost += cost[pre[k]][k];
        Len += dist[pre[k]][k];
        for1(j,n){
            double tmp = cost[k][j] - dist[k][j]*p;
            if(!vis[j]&&dis[j]>tmp){
                dis[j] = tmp;
                pre[j] = k;
            }
        }
    }
    return Cost / Len;



int main(void)
{
    init();

    int N;
    scanf("%d",&N);
// input
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            int x;
            scanf("%d", &x);
            prize[i][j] = x;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            int x;
            scanf("%d", &x);
            cost[i][j] = x;
        }
    }
// build_edges
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            Edge tmp;
            tmp.cost = cost[i][j];
            tmp.prize = prize[i][j];

            tmp.end = j;
            vec[i-1].pb(tmp);
            tmp.end = i-1;
            vec[j].pb(tmp);
        }
    }


    double l=0, r=100000000;


    int timer = 100000;
    while( timer-- ){
        double mid = (l+r)/2;
        double tmp = prim(mid);

    }











    for(auto now: vec[0]){
        pq.push(now);
    }
    vis[0] = true;

    int ansPrize = 0;
    int ansCost = 0;
    int cnt = 0;
    while( cnt < N ){
        if( pq.size() ){
            Edge now = pq.top();
            pq.pop();
            if( vis[now.end] == false ){
                ansPrize += now.prize;
                ansCost += now.cost;
                vis[now.end] = true;
                cnt++;
                for(auto next: vec[now.end]){
                    pq.push(next);
                }
            }else{
                continue;
            }
        }else{
            puts("error");
        }
    }
    int g = gcd(ansPrize, ansCost);
    printf("%d %d\n", ansPrize/g, ansCost/g);

    return 0;
}




















