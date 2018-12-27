//reference:高政(B06902040)是學霸，他救了我的code
#include <cstdio>
#include <algorithm>

const int SIZE = 100000+10;
typedef long long ll;
using std::max;

ll A[2*SIZE],ans[2*SIZE];
void init(ll* x,int n)
{
    for(int i=0;i<n;i++) x[i] = 0;
}
//a*a, b*b, [(a+b)*(a+b)]-a*a-b*b
void karatsuba(ll* A,ll* now,int size)
{
    //base case
    if( size < 128 ){
        for(int i=0;i<=size;i++)
            for(int j=0;j<=size;j++)
                now[i+j] += (A[i]*A[j]);
        return ;
    }
    int m = size>>1;

    ll* a2 = new ll[2*(m+1)];
    ll* b2 = new ll[2*(m+1)];
    ll* ab2 = new ll[2*(m+1)];
    ll* B = new ll[m+1];
    //init
    init(a2,2*(m+1)),init(b2,2*(m+1)),init(ab2,2*(m+1)),init(B,m+1);
    
//build B:(a+b)
    for(int i=0;i<m+1;i++)
        B[i] += A[i];
    for(int i=0;i<size-m;i++)
        B[i] += A[m+i+1];

    karatsuba(A,a2,m);
    karatsuba(A+m+1,b2,size-m-1);
    karatsuba(B,ab2,m);

    //ab2-a2-b2
    for(int i=0;i<2*(m+1);i++){
        ab2[i] -= a2[i];
        ab2[i] -= b2[i];
    }

//Combine
    //a2
    for(int i=0;i<2*(m+1);i++)
        now[i] += a2[i];

    //10^(n/2) ab2
    for(int i=0;i<2*(m+1);i++)
        now[i+m+1] += ab2[i];

    //10^n b2
    for(int i=0;i<2*(m+1);i++)
        now[i+2*(m+1)] += b2[i];

    delete [] a2;
    delete [] b2;
    delete [] ab2;
    delete [] B;

    return ;
}
void build(int N)
{
    //karatsuba
    karatsuba(A,ans,N);

    for(int i=0;2*i<=2*N;i++)
        ans[2*i] -= (A[i]);
    for(int i=0;i<=2*N;i++)
        ans[i] /= 2;
}
ll reans(int k)
{
    if (k>200000) return 0;
    return ans[k];
}
int main(void)
{
    int n;
    int MX = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        A[x]++;
        MX = max(MX,x);
    }
    build(MX);
    int m;
    scanf("%d",&m);
    while(m--){
        int k;
        scanf("%d",&k);
        printf("%lld%c",reans(k),m==0?'\n':' ');
    }
    return 0;
}




