#include <iostream>
using namespace std;
#define MAX 100
#define MIN(a,b) (a>b)?b:a

int binCoeff(int n, int k)
{
    int i, j;
    int b[MAX][MAX];
    for(i=0; i<=n; i++)
        for(j=0; j<=MIN(i,k); j++)
        {
            if(j==0 || j==i) b[i][j] = 1;
            else b[i][j] = b[i-1][j-1]+b[i-1][j];
        }
    return b[n][k];
}
int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        int n,k;
        cin >> n >> k;
        printf("%d\n",binCoeff(n,k));
    }
}