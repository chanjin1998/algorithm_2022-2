#include <iostream>

using namespace std;
#define MAX 100
#define MIN 0
int binCoeff(int n, int k)
{
    int i, j;
    int B[MAX][MAX];
    for(i=0; i<=n; i++)
        for(j=0; j<=MIN(i,k); j++){
        if(j==0 || j==i) B[i][j] = 1;
        else  B[i][j] = B[i-1][j-1]+B[i-1][j];
        }
    return B[n][k];
}