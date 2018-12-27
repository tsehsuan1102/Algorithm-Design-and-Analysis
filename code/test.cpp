#include <cstdio>
#include <algorithm>

const int SIZE = 1000000+10;
typedef long long ll;
using std::max;

ll A[2*SIZE],ans[2*SIZE];
void init(ll* x,int n)
{
    for(int i=0;i<n;i++)
        x[i] = 0;
}
//a*a, b*b, [(a+b)*(a+b)]-a*a-b*b
void karatsuba(ll* A,ll* now,int size)
{
    puts("------------------A-------------------");
    for(int i=0;i<=size;i++){
        printf("%d%c",A[i],i==size?'\n':' ');
    }
    puts("--------------------------------------");
    

    printf("#%d\n",size);
    //base case
    if( size < 3 ){
        for(int i=0;i<=size;i++)
            for(int j=0;j<=size;j++)
                now[i+j] += (A[i]*A[j]);
        puts("return");
        return ;
    }

    // Divide
    int sizer = size>>1;
    int sizel = size-sizer-1;
    // int sep_size = size/2+1;

    ll* a2 = new ll[2*(size+1)];
    ll* b2 = new ll[2*(size+1)];
    ll* ab2 = new ll[2*(size+1)];
    ll* B = new ll[2*(size+1)];
    //init
    init(a2,2*size),init(b2,2*size),init(ab2,2*size),init(B,2*size);
    
    //build B:(a+b)
    for(int i=0;i<=sizel;i++)
        B[i] = (A[i] + A[sizel+i+1]);
    if( sizel<sizer )
        B[sizer] = A[sizer];

    for(int i=0;i<=sizer;i++)
        printf("[%d]%c",B[i],i==sizer?'\n':' ');

    puts("1");
    karatsuba(A,a2,sizel);
    puts("2");
    karatsuba(A+sizel+1,b2,sizer);
    puts("3");
    karatsuba(B,ab2,sizer);

    //ab2-a2-b2
    for(int i=0;i<=2*sizer;i++){
        ab2[i] -= a2[i];
        ab2[i] -= b2[i];
    }

    //10^n a2
    for(int i=size;i+2*sep_size<=2*size;i++)
        now[i+2*sep_size] += a2[i];

    //10^(n/2) ab2
    for(int i=0;i+sep_size<=2*size;i++)
        now[i+sep_size] += ab2[i];

    //b2
    for(int i=0;i<=size;i++)
        now[i] += b2[i];

    delete [] a2;
    delete [] b2;
    delete [] ab2;
    delete [] B;

    return ;
}
void build(int N)
{
    //karatseba
    karatsuba(A,ans,N);

    for(int i=0;2*i<=2*N;i++)
        ans[2*i] -= (A[i]);
    for(int i=0;i<=2*N;i++)
        ans[i] /= 2;
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
        if( k>2*SIZE ) puts("0");
        else printf("%d%c",ans[k],m==0?'\n':' ');
    }

    return 0;
}







