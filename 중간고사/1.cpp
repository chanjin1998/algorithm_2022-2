#include <iostream>

using namespace std;

int palindrome(int a[],int start,int end)
{
    if(end<=start) return 1;
    else if(a[start]!=a[end]) return 0;
    else return palindrome(a,start+1,end-1);
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
        printf("%d\n",palindrome(a,0,n-1));

    }
}