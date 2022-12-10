#include <stdio.h>

int factorial(int n);
int check(int n);
int al;
int aa;

int main()
{
    int numCases;
    scanf("%d>>", &numCases);
    for (int i=0;i<numCases;++i)
    {
        int num;
        scanf("%d>>", &num);
        aa = factorial(num);
        while(true){
            if (aa%10==0) aa/=10;
            else break;}
        printf("%d \n", aa%1000);

    }
}
int factorial(int n)
{
    if (n<=1)
    {
        return 1;
    }
    else return check(n)* check(factorial(n-1));
} 
int check(int value)
{
    if (value % 10==0) return check(value/=10);
    else return value%10000;

}