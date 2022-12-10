#include <iostream>

using namespace std;
#define MAX(a,b) (a>b) ? a:b
#define MIN(a,b) (a>b) ? b:a
int max(int a, int b)
{
    if (a>b) return a;
    else return b;
}
int recurMax(int a[],int left,int right)
{
    int half;
    if(left==right)
        return a[left];
    else
    {
        half = (left+right)/2;
        return (left==0 && right=sizeof(a)/sizeof(a[0]))) ? MIN(recurMax(a,left,half),recurMax(a,half+1,right)):MAX(recurMax(a,left,half),recurMax(a,half+1,right));
    }
}
int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        int numCase;
        scanf("%d",&numCase);
        int a[numCase];
        for(int j=0;j<numCase;j++)
        {
            cin >> a[j];
        }
        int n = sizeof(a)/sizeof(a[0]);
        printf("%d\n",recurMax(a,0,n-1));
    }
}

    