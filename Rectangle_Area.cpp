#include <cstdio>
#include <utility>
#include <algorithm>
#define PII pair<int,int>
#define x first
#define y second
using namespace std;

const int SIZE = 100000+10;
PII A[SIZE];
PII tmp[SIZE];
typedef long long ll;
ll ans;
void D_C(int L,int R)//[,]
{
    if( L==R ) return;

    int mid = (L+R)>>1;
    //Divide (mid in left)
    D_C(L,mid);
    D_C(mid+1,R);

    ll lxy=0ll,rxy=0ll;
    ll lsumy=0, rsumy=0;
    ll lsumx=0, rsumx=0;
    //pre-processing:(sum)
    for(int i=L;i<=R;i++){
        if(i<=mid){
            lsumx += A[i].x;
            lsumy += A[i].y;
            lxy += A[i].x*A[i].y;
        }else{
            rsumx += A[i].x;
            rsumy += A[i].y;
            rxy += A[i].x*A[i].y;
        }
    }
    int l=L,r=mid+1;
    int idx = l;
    while( l<=mid || r<=R ){
        if( l<=mid && (r>R || A[l].y<A[r].y) ){
            ll nowx = A[l].x,nowy = A[l].y;
            ll sz = R-r+1;
            //take left
            ans += ( rxy - nowx*rsumy - nowy*rsumx + sz*nowx*nowy);
            lsumx -= nowx;
            lsumy -= nowy;
            lxy -= nowx*nowy; 
            tmp[idx].x = A[l].x,tmp[idx++].y = A[l].y;
            l++;
        }else{
            ll nowx = A[r].x,nowy = A[r].y;
            ll sz = mid-l+1;
            //take right
            ans += ( -1*lxy + nowx*lsumy + nowy*lsumx - sz*nowx*nowy);
            rsumx -= nowx;
            rsumy -= nowy;
            rxy -= nowx*nowy; 
            tmp[idx].x = A[r].x,tmp[idx++].y = A[r].y;
            r++;
        }
    }
    for(int i=L;i<=R;i++)
        A[i].x=tmp[i].x, A[i].y=tmp[i].y;
    return ;
}

void sol(int N)
{
    ans = 0ll;
    sort(A,A+N);
    D_C(0,N-1);
    printf("%lld\n",ans);
}
int main(void)
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%lld %lld",&A[i].x,&A[i].y);
    sol(N);
    
    return 0;
}
