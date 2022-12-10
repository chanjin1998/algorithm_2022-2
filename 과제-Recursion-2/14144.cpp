#include <iostream>
using namespace std;
long long mat[2][2] = {1, 1, 1, 0};
long long res[2][2] = {1, 0, 0, 1};
void fibo(int num);

void multi(long long m1[][2], long long m2[][2]){
    long long tmp[2][2];
    long long temp;
 
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            temp = 0;
            for(int k=0;k<2;++k){
                temp += (m1[i][k] * m2[k][j]);
            }
            tmp[i][j] = temp % 1000;
        }
    }
 
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            m1[i][j] = tmp[i][j];
        }
    }
 
    return;
}
void fibo(int num)
{
    while(num>0)
    {
        if(num%2 == 1) multi(res,mat);

        num /= 2;
        multi(mat,mat);
    }
}
int main() {
    
    long long n;
    cin>>n;
    fibo(n);
 
    cout<<res[1][0];
}