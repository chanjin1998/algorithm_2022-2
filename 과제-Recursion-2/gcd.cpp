#include <iostream>
using namespace std;

int gcd(int a,int b);

int main()
{
    int num;
    scanf("%d",&num);
    for (int i=0;i<num;i++)
    {
        int bigNum,smallNum;
        scanf("%d %d",&bigNum,&smallNum);
        printf("%d",gcd(bigNum,smallNum));
        cout << endl;
    }
}
int gcd(int a, int b)
{
    if (b==0) return a;
    else return gcd(b, a % b);
}