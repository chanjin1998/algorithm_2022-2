#include <iostream>
#include <cmath>
using namespace std;
long long p(double x, int n);
long long p(double x, int n)
{
    long long y;
    if(n==0) return 1.0;
    else if(n%2==1)
    {
        y = pow(p(x,(n-1)/2)%1000,2);
        return x*y;
    }
    else{
        y = pow(p(x,n/2),2);
        return y;
    }
}
int main()
{
    int numCase;
    scanf("%d",&numCase);
    for(int i=0;i<numCase;i++)
    {
        double a,b;
        scanf("%lf %lf",&a,&b);
        printf("%lld",p(a,b)%1000);
        cout << endl;
    }
}