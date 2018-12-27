#include <cstdio>

i
nt A[10]={5,2,2,4,1,2,9,0,1,3};
int B[20]={0};

int main (void)
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            B[i+j] += A[i]*A[j];
    for(int i=0;i<20;i++)
        printf("%d:%d\n",i,B[i]);
    return 0; 
}








