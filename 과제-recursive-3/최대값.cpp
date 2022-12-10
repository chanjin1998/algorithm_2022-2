#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 100
#define MAX(a,b) ((a)>(b)?(a):(b))

int recurMax(int a[],int left,int right);

int recurMax(int a[],int left,int right)
{
    int half;
    if(left == right) return a[left];
    else
    {
        half = (left+right)/2;
        return MAX(recurMax(a,left,half),recurMax(a,half+1,right));
    }
}
int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        int numcase;
        cin >> numcase;
        int a[numcase];
        for(int j=0;j<numcase;j++)
        {
            scanf("%d",&a[j]);
        }
        printf("%d\n",recurMax(a,0,numcase-1));
    }
}