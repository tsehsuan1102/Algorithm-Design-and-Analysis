#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

#define PII pair<int,int>
#define x first
#define y second

const int SIZE = 1000000+10;
PII A[SIZE];

int chizu[5][5] = { {0,1,2,3}, {1,2,2,3}, {2,2,3,4}, {3,3,4,4} };
typedef long long ll;
void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
ll _abs(int x) { return x<0?  -x : x; }
ll count(int x,int y)
{
    if(x>2*y) return x;
    ll re = 0ll;
    int s = (2*x-y)/3; 
    int t = (2*y-x)/3; 
    x -= (2*s+t);
    y -= (s+2*t);
    return 2*(s+t) + chizu[x][y];
}

int main(void)
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d %d",&A[i].x, &A[i].y);

    for(int i=0;i<N;i++){
        ll ans = 0ll;
        for(int j=0;j<N;j++){
            ll dx = _abs( A[i].x-A[j].x );
            ll dy = _abs( A[i].y-A[j].y );
            if( dy>dx ) swap(dx,dy); // let x > y
            ll tmp = count(dx,dy);
            ans +=tmp;
        }
        printf("%lld\n",ans);
    }

}


