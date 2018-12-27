#include <cstdio>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
#define PII pair<int,int>
#define x first
#define y second
using namespace std;

map<int,int> mp;
const int SIZE = 100000+10;
PII A[SIZE];

//ans
long long ans;
//pre-process array
long long prey[SIZE];
long long prex[SIZE];
long long prexy[SIZE];
//tmp pair
PII tmp[SIZE];
void D_C(int l,int r)
{
    //basic case
    if( l+1 == r ) return ;
    
    //Divide&Conquer
    int mid = (l+r)>>1;
    D_C(l,mid);
    D_C(mid,r);
    //points in this section
    //copy
    for(int i=mid;i<r;i++)
        tmp[i].x = A[i].x,tmp[i].y = A[i].y;
    //sort
    sort(&tmp[mid],&tmp[r],[](PII a,PII b){
        return a.y < b.y;
    });
    // //order by y
    // for(int i=mid;i<r;i++)
    //     mp[tmp[i].x] = i;
    
    //pre-processing
    prex[mid] = tmp[mid].x, prey[mid] = tmp[mid].y, prexy[mid] = tmp[mid].x*tmp[mid].y;
    for(int i=mid+1;i<r;i++){
        //sigma x
        prex[i] = prex[i-1] + tmp[i].x;
        //sigma y
        prey[i] = prey[i-1] + tmp[i].y;
        //sigma xy
        prexy[i] = prexy[i-1] + tmp[i].x*tmp[i].y;
    }
    //count
    for(int i=l;i<mid;i++){
        int x0 = A[i].x,
            y0 = A[i].y;
        printf("x:%d y:%d\n",x0,y0);
        // int bl = mid, br = r-1;
        // while(bl<br){
        //     printf("%d-%d\n",bl,br);
        //     int bm = (bl+br)>>1;
        //     if( y0 < tmp[bm].y )
        //         br = bm;
        //     else bl = bm;
        // }
        // puts("!");
        int idx = mid;
        while( idx<r && tmp[idx+1].y < y0 ) idx++;
        int upper = r-idx,
            lower = idx-mid;

        printf("%d %d %d\n",idx,upper,lower);
        ans += (upper*x0*y0 + prexy[r]-prexy[idx] - y0*(prex[r]-prex[idx]) - x0*(prey[r]-prey[idx]) );
        printf("%lld\n",(upper*x0*y0 + prexy[r]-prexy[idx] - y0*(prex[r]-prex[idx]) - x0*(prey[r]-prey[idx]) ) );
        
        ans += (-1*lower*x0*y0 - prexy[idx]-prexy[mid] + y0*(prex[idx]-prex[mid]) + x0*(prey[idx]-prey[mid]) );
        printf("%lld\n",(-1*lower*x0*y0 - prexy[idx]-prexy[mid] + y0*(prex[idx]-prex[mid]) + x0*(prey[idx]-prey[mid]) ));
        printf("ans:%lld\n",ans);
    }
}
void sol(int N)
{
    D_C(0,N);
    printf("%lld\n",ans);
}
inline void init()
{
    ans = 0ll;
}
int main (void)
{
    init();
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d %d",&A[i].x,&A[i].y);
    sort(A,A+N);
    sol(N);
    return 0;
}








