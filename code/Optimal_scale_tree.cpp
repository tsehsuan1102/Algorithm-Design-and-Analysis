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
    printf("prim:%d\n", N);

    for(int i=0;i<SIZE;i++) vis[i] = false;
    vis[0] = true;

    build new edges

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
    // int N;
    // scanf("%d",&N);
    double t = prim(100, 10);

    return 0;
}




