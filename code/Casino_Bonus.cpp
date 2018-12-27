#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>

#define PII pair<int,int>
#define PDI pair<double,int>
#define pr first
#define co second
#define pb push_back
using namespace std;

const int SIZE = 1024+10;
const double eps = 1e-6;

int prize[SIZE][SIZE];
int cost[SIZE][SIZE];
PII edges[SIZE][SIZE];

bool vis[SIZE];
priority_queue<PDI, vector<PDI>, greater<PDI>> pq;

double d[SIZE][SIZE];

double prim(double f, int N)
{
    // printf("prim:%d\n", N);
    for(int i=0;i<SIZE;i++) vis[i] = false;
    vis[0] = true;
    //build new edges


    for(int i=0;i<=N;i++){
        for(int j=i;j<=N;j++){
            d[i][j] = d[j][i] = edges[i][j].pr - f * edges[i][j].co;
            if(i==j) d[i][j] = 0;
        }
    }
    while(pq.size()) pq.pop();
    for(int i=1;i<=N;i++)
        pq.push( make_pair((double)(d[0][i]), i) );

    vis[0] = true;
    int cnt = 0;
    double re = 0;

    while(cnt<N){
        if( pq.size() ){
            PII now = pq.top();
            pq.pop();
            if( vis[now.second] == false ){
                re += now.first;
                vis[now.second] = true;
                cnt++;
                for(int i=0;i<=N;i++)
                    if( i!=now.second )
                        pq.push( make_pair(d[now.second][i], i));
            }
            else continue;
        }
    }
    return re;
}



int main(void)
{
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
            PII tmp;
            tmp.pr = prize[i][j];
            tmp.co = cost[i][j];
            edges[i-1][j] = edges[j][i-1] = tmp;
        }
    }

    double l=0, r=100000000;

    int timer = 100000;
    while( timer-- ){
        double mid = (l+r)/2;
        printf("mid=%lf\n", mid);
        double t = prim(mid, N);
        printf("t=%lf\n", t);
        
        if( fabs(t) <= eps )
            break;
        if( t < 0 )
            r = mid;
        else l = mid;
    }
    printf("%lf\n", l);

    return 0;
}




