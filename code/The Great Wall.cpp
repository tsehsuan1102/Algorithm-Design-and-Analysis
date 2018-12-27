#include <cstdio>
#include <stack>
#include <algorithm>
#include <utility>

#define PII pair<int,int>
#define l first
#define r second
#define sq(x) (x)*(x)
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    stack<PII> stk;
    while(stk.size()) stk.pop();
    long long ans = 0;
    while(n--){
        int left, right;
        scanf("%d %d",&left,&right);
        int now_l = left;
        while( stk.size() && left <= stk.top().r ) {
            ans -= sq(((long long)(stk.top().r) - stk.top().l));
            now_l = min(now_l, stk.top().l);
            stk.pop();
        }
        ans += sq(((long long)(right)-now_l));
        stk.push( make_pair(now_l, right) );
        printf("%lld\n", ans);
    }
    
    return 0;   
}

