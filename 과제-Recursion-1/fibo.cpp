#include <iostream>
#include <stdio.h>
int fibo(int num);

int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        int numcase;
        scanf("%d",&numcase);
        printf("%d \n", fibo(numcase));
    }
}
int fibo(int num)
{
    if(num<=1)
    {
        return num;
    }
    else{
        return fibo(num-1) + fibo(num-2);
    }
}