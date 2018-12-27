#include <cstdio>
#include <cstring>

const int SIZE = 1000+10;
const int MOD = 1000000000+7;
int mp[SIZE][SIZE];
long long dp[SIZE][SIZE];

int check(char *s)
{
    int len = strlen(s);
    int cnt3=0, cnt6=0, cnt9 = 0;
    int check3 = 0,check11 = 0;
    int flag = 1;
    for(int i=0;i<len;i++){
        if( s[i] == '3' ) cnt3++;
        if( s[i] == '6' ) cnt6++;
        if( s[i] == '9' ) cnt9++;
        check11 += (flag*(s[i]-'0'));
        flag = -flag;
        check3 += (s[i]-'0');
    }
    if( cnt3%3==0 && cnt6%3==0 && cnt9%3==0 && check11%11==0 && check3%3==0 ) return 1;
    return 0;
}
void print(int n,int m)
{
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d ",dp[i][j]);
        puts("");
    }
}

inline void init()
{
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            dp[i][j] = 0;
}
int main(void)
{
    init();

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char x[20];
            scanf("%s",x);
            mp[i][j] = check(x);
        }
    if(mp[1][1]==0) dp[1][1] = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(mp[i][j]==0)
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= MOD;
        }
    // print(n,m);
    printf("%lld\n",dp[n][m]);
    return 0;
}
