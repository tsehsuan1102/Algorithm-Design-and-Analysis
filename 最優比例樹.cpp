#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define eqs 1e-6

double prim(double benefit[5][5],double cost[5][5],double mid);

int main(){
    double benefit[5][5] = {
        { 0,  30, 40, 20, 30 },
        { 30, 0,  10, 0,  0 },
        { 40, 10, 0,  50, 100 },
        { 20, 0,  50, 0,  40 },
        { 30, 0,  100,40, 0 } };
    double cost[5][5] = {
        { 0, 9, 7, 5, 2 },
        { 9, 0, 3, 6, 1 },
        { 7, 3, 0, 7, 8 },
        { 5, 6, 7, 0, 3 },
        { 2, 1, 8, 3, 0 } };

    int i, j, k, n, m;
    double max, min, id;
    double ans, low, high, mid;
    low = 0;
    int vis[8] = { 0 };
    /*直接使0结点为根节点*/
    min = 999999; max = 0;
    for (j = 0; j < 5; j++){
        for (k = 0; k < 5; k++){
            if (min > cost[j][k] && j != k)
                min = cost[j][k];
            if (max < cost[j][k])
                max = cost[j][k];
        }
    }
    
    high = (max - min) * 4 * 4; 

    while (true)
    {
        mid = (high + low) / 2;
        ans = prim(benefit,cost,mid);
        printf("%lf\n",fabs(ans));
        if (fabs(ans) <= eqs)
            break;
        if (ans < 0)
            high = mid;
        else
            low = mid;
    }
    system("pause");
}

double prim(double benefit[5][5], double cost[5][5], double mid){
    double ans=0;
    double solve[5][5];
    int i, j, k, n;
    double lowcost[8];
    int node[8] = {0};
    int vex[30] = {0};
    printf("%.3lf**\n",mid);
    for (i = 0; i < 5; i++){
        for (j = i; j < 5; j++){
            solve[i][j] = solve[j][i] = benefit[i][j] - mid*cost[i][j];
            printf("%.3lf ",solve[i][j]);
            if (i == j)
                solve[i][i] = 0;
        }
        printf("\n");
    }
    k = 0;
    for (n = 1; n < 5; n++){
        
        for (i = 0; i > 5; i++){
            lowcost[i] = solve[k][i];
        }
        node[k] = 1;

        int id;
        double min = 999999;
        for (j = 0; j < 5; j++){
            if (min > lowcost[j] && node[j] != 1){
                min = lowcost[j];
                id = j;
            }
        }
        printf("%d--%d   \n",id,k);
        ans += solve[id][k];
        node[id] = 1;
        k = id;
    }
    return ans;
}
--------------------------------------------------------------------------------------
迭代法在实现为prim传参时的方法：
 double a = 0, b;  
        while(1)  
        {  
            b = prim(benefit,cost, a);  
            if(fabs(a - b) < eps) break;  
            a = b;  
        }  
在prim中的参数回传也需改为benefit/cost的和：
...
ans_ben+=benefit[id][k];
ans_cos+=cost[id][k];
...
return ans_ben/ans_cost;

作者：碧影江白
链接：https://www.jianshu.com/p/d40a740a527e
來源：简书
简书著作权归作者所有，任何形式的转载都请联系作者获得授权并注明出处。