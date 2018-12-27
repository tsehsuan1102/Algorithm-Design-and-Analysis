#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

#define PII pair<int,int>
#define weight first
#define value second
const int SIZE = 20;

int dp[SIZE][SIZE];
PII A[SIZE]={ make_pair(0,0),make_pair(1,3),make_pair(3,7),make_pair(4,10),make_pair(5,12),make_pair(8,17),make_pair(10,19),make_pair(11,21) };

int main (void)
{
    for(int i=1;i<=7;i++){
        for(int j=0;j<=15;j++){
            if( j-A[i].weight>=0 )
                dp[i][j] = max( dp[i-1][j], dp[i-1][j-A[i].weight] + A[i].value );
            else dp[i][j] =  dp[i-1][j];
        }
    }
    for(int i=0;i<=15;i++)
        printf("%d%c",dp[7][i],i==15?'\n':' ');
}


