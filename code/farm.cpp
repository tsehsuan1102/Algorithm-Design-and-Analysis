#include <cstdio>
#include <utility>

#define PII pair<int,int>
#define x first
#define y second
using namespace std;

const int SIZE = 1000000+10;
PII A[SIZE];

int _abs(int x) { if(x<0) return -x; return x; }

int count(int x, int y) { return x>2*y?  x : ((x+y)/3*2) + ((x+y)%3);  }
int main (void)
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d %d", &A[i].x, &A[i].y);
    for(int i=0;i<N;i++){
        int loneliness = 0;
        for(int j=0;j<N;j++){
            int dx = _abs(A[i].x - A[j].x);
            int dy = _abs(A[i].y - A[j].y);
            loneliness += count(dx, dy);
        }
        printf("%d\n", loneliness);
    }

    return 0;
}
