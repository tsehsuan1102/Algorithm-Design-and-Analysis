#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
char s1[10] = " ABCADB";
char s2[10] = " CABDAB";

const int SIZE = 10;
int dp[SIZE][SIZE];

int main(void)
{
    int len = strlen(s1);
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            int tmp = s1[i]==s2[j]? 0:2;
            if( i==0 || j==0 ) {
                dp[i][j] = i+j;
            }
            else dp[i][j] = min( min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+tmp);
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++)
            printf("%d ",dp[i][j]);
        printf("\n");
    }
    return 0;
}