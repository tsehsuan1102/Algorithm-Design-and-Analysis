#include<stdio.h>
#define size 100000+10

int dis[size];
int hx[size];
int hy[size];

int map[3][3] = { { 0, 1, 2}, 
                  { 1, 2, 2}, 
                  { 2, 2, 3} };

int abs(int x)  {return (x >= 0)? x : -x;}
void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; return;}

int find_dis(int a, int b){
    int x = abs( hx[a] - hx[b]), y = abs( hy[a] - hy[b]);
    if( x < y) swap(&x, &y);
    if( x > 2*y){
        return x;
    }
    int X = 2 * x - y;
    int xr = X % 3;
    X /= 3;
    int Y = 2 * y - x;
    int yr = Y % 3;
    Y /= 3;
    int dis = 2 * X + 2 * Y + map[xr][yr];
    return dis;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d", &hx[i], &hy[i]);
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++){
            int d = find_dis(i, j);
//          printf("%d\n", d);
            dis[i] += d;
            dis[j] += d;
        }
    for(int i = 0; i < n; i++)
    printf("%d\n", dis[i]); 
        
    
}