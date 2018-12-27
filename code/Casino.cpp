#include <cstdio>
#include <vector>
#include <utility>


const int SIZE = 1024+10;

typedef struct{
    int start, end;
    int prize;
    int cost;
}Edge;
vector<edge> edges;

struct disjointset{
    int dis[SIZE];
    void init(){
        for(int i=0;i<SIZE;i++)
            dis[i] = i ;
    }
    int find(int x){
        return x == dis[x]? x : dis[x] = find(dis[x]);
    }
    void uni(int x, int y){
        dis[ find(x) ] = find(y);
    }
}set;



int main(void)
{
    set.init();

    int N;
    scanf("%d", &N);

    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            scanf("%d", );
            printf("1 ");
        }
    }

    return 0;
}





























