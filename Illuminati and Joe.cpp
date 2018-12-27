//reference b06902040
#include <cstdio>
#include <cstring>
#include <cstdlib>
// #include <time.h> 

typedef long long ll;
const int MAX_LEN = 1000+10;
const ll MOD = 1000000000+7;

ll dp[MAX_LEN][10][11][3][3][3][3];
//d1->len, d2->0~9, d3->even-odd, d4=c3, d5=c6, d6=c9, d7=sum%3;
//dp[i][j] = the number that heading by j with lenth i
int p(int x,int d) { while(x<0) x+=d; return x%d; }

void build()
{
    //d1->len, d2->0~9, d3->even-odd, d4=c3, d5=c6, d6=c9, d7=sum%3;
    //dp[i][j] = the number heading by j with lenth i

    for(int n=0;n<=9;n++){
        int c3,c6,c9;
        c3=c6=c9=0;
        if( n==3 ) c3++;
        if( n==6 ) c6++;
        if( n==9 ) c9++ ;
        dp[0][n][p(n,11)][c3][c6][c9][p(n,3)] = 1;
    }

    for(int l=0;l<MAX_LEN-2;l++){//len
        for(int n=0;n<=9;n++){//num
            for(int oe=0;oe<11;oe++){//odd-even
                for(int three=0;three<3;three++){//c3
                    for(int six=0;six<3;six++){//c6
                        for(int nine=0;nine<3;nine++){//c9
                            for(int s=0;s<3;s++){//sum%3
                                // now digit = k = 0~9
                                dp[l][n][oe][three][six][nine][s] %= MOD;
                                for(int k=0;k<=9;k++){
                                    int new_s = p(s+k,3);
                                    int new_oe;
                                    if( l%2==1 ) new_oe = p(oe+k,11);
                                    else new_oe = p(oe-k,11);

                                    if( k==3 ){
                                        dp[l+1][k][new_oe][p(three+1,3)][six][nine][new_s] += dp[l][n][oe][three][six][nine][s],
                                        dp[l+1][k][new_oe][p(three+1,3)][six][nine][new_s] %= MOD;
                                    }else if( k==6 ){
                                        dp[l+1][k][new_oe][three][p(six+1,3)][nine][new_s] += dp[l][n][oe][three][six][nine][s],
                                        dp[l+1][k][new_oe][three][p(six+1,3)][nine][new_s] %= MOD;
                                    }else if( k==9 ){
                                        dp[l+1][k][new_oe][three][six][p(nine+1,3)][new_s] += dp[l][n][oe][three][six][nine][s],
                                        dp[l+1][k][new_oe][three][six][p(nine+1,3)][new_s] %= MOD;
                                    }else{
                                        dp[l+1][k][new_oe][three][six][nine][new_s] += dp[l][n][oe][three][six][nine][s],
                                        dp[l+1][k][new_oe][three][six][nine][new_s] %= MOD;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

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
        check3 %= 3;
    }
    if( (cnt3%3 + cnt6%3 + cnt9%3 + check11%11 + check3%3)==0 ) return 1;
    return 0;
}
ll count(char *s)
{
    ll ans = 0ll;
    int len = strlen(s);
    int c3,c6,c9;
    c3=c6=c9=0;
    int oe=0, sum=0, now_id=0;
    while( now_id<len ){ //len
        int now_digit = s[now_id]-'0';
        for(int n=0;n<now_digit;n++){
            ans += dp[len-now_id-1][n][oe][c3][c6][c9][sum];
            ans %= MOD;
        }
        //update
        //3,6,9
        if( now_digit==3 ) c3=p(c3-1,3);
        else if( now_digit==6 ) c6=p(c6-1,3);
        else if( now_digit==9 ) c9=p(c9-1,3);
        //even-odd
        if( (len-now_id-1)%2 == 0 ) oe = p(oe-now_digit,11);
        else oe = p(oe+now_digit,11);
        //sum of digit
        sum = p(sum-now_digit,3);

        now_id++;
    }
    return ans;
}

int main(void)
{
    build();

    char l[MAX_LEN], r[MAX_LEN];
    scanf("%s %s",l,r);
    ll rel = count(l);
    ll rer = count(r);
    
/*
#################################################
*/
    srand(l[0]*r[1]+r[0]);
    int k = rand();
    if( (k%2==1) && check(l) ) rel++;
/*
#################################################
*/

    if(check(r)) rer++; 
    printf("%lld\n",(rer-rel+MOD)%MOD);
    return 0;
}




