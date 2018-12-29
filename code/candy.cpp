#include <cstdio>
#include <algorithm>

const int SIZE = 21;

bool friends[SIZE][SIZE];


int A, B, C;
int ans = -1;
int colors[SIZE];
//1->A, 2->B, 4->C

void printcolor(int n)
{
    for(int i=1;i<=n;i++)
        printf("%d ", colors[i]);
    puts("");
}

void Candy(int now, int max)
{
    if( A+(max-now+1) < ans ){
        return ;
    }
    if(now == max+1) {
        ans = std::max(ans, A);
        //printf("%d:", ans);
        //printcolor(max);
        return ;
    }

    bool flag;

    //A
    colors[now] = 1;
    flag = true;
    for(int i=1;i<=max;i++){
        if( friends[now][i] ){
            //now, i is friend
            if( colors[i] == colors[now] ){
                flag = false;
                colors[now] = 0;
            }
        }
    }
    if( flag ){
        A++;
        Candy(now+1, max);
        A--;
    }


    //B
    colors[now] = 2;
    flag = true;
    for(int i=1;i<=max;i++){
        if( friends[now][i] ){
            //now, i is friend
            if( colors[i] == colors[now] ){
                flag = false;
                colors[now] = 0;
            }
        }
    }
    if( flag ){
        B++;
        Candy(now+1, max);
        B--;
    }
    
    //C
    colors[now] = 4;
    flag = true;
    for(int i=1;i<=max;i++){
        if( friends[now][i] ){
            //now, i is friend
            if( colors[i] == colors[now] ){
                flag = false;
                colors[now] = 0;
            }
        }
    }
    if( flag ){
        C++;
        Candy(now+1, max);
        C--;
    }

    colors[now] = 0;
    return ;

}

void sol(int n)
{
    Candy(1, n);
}


inline void init() {
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            friends[i][j] = false;
    for(int i=0;i<SIZE;i++)
        colors[0] = 0;
    A = B = C = 0;
}
int main(void)
{
    init();

    int n, m;
    scanf("%d %d", &n, &m);
    while(m--){
        int x, y;
        scanf("%d %d", &x, &y);
        friends[x][y] = friends[y][x] = true;
    }

    sol(n);
    printf("%d\n", ans);
    return 0;
}


/*
7 7
1 2
1 3
1 4
4 6
3 4
3 5
5 7
*/




