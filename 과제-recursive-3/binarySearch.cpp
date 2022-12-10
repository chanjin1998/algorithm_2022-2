#include <iostream>
using namespace std;
int binarySearch(int a[],int left,int right,int value);
int binarySearch(int a[],int left,int right,int value)
{
    int mid;
    if(left>right) return -1;
    else
    {
        mid = (left+right)/2;
        if(a[mid] == value) return mid;
        else if(a[mid]>value) return binarySearch(a,left,mid-1,value);
        else return binarySearch(a,mid+1,right,value);
    }
}
int main()
{
    int num;
    cin >> num;
    for(int i=0;i<num;i++)
    {
        int numcase,value;
        cin >> numcase >> value;
        int a[numcase];
        for(int j=0;j<numcase;j++)
        {
            scanf("%d",&a[j]);
        }
        printf("%d\n",binarySearch(a,0,numcase,value));
    }
}