#include <iostream>
#include <stdio.h>
using namespace std;
void fibo(long long num);
void multi(long long m1[][2], long long m2[][2]);
long long base[2][2] = {{1,1},{1,0}};
long long res[2][2] = {0};
long long zero[2][2] = {{1,0},{0,1}};

int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        res[0][0] = 1;
        res[0][1] = 1;
        res[1][0] = 1;        
        res[1][1] = 0;
        long long numcase;
        scanf("%lld",&numcase);
        if (numcase==0)
            cout<<0<<endl;
        else{
            fibo(numcase);
            cout << res[1][0] << endl;}
    }
}

void fibo(long long num)
{
    if(num==1)
    {
        multi(res,zero);
    }
    else
    {
        fibo(num/2);
        multi(res,res);
        if(num%2==1) multi(res,base);       
    }
}
void multi(long long m1[][2], long long m2[][2]){
    long long tmp[2][2];
    long long temp;

    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            temp = 0;
            for(int k=0;k<2;++k){
                temp += (m1[i][k] * m2[k][j]);
            }
            tmp[i][j] = (long long)temp % 1000;
        }
    }
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            res[i][j] = tmp[i][j];
        }
    }
    return ;
}