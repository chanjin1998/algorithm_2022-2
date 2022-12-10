#include <iostream>
using namespace std;
#define MAX_SIZE 100
int cnt;
void merge(int a[],int low, int mid,int high);
void mergeSort(int v[],int low,int high);

void merge(int a[],int low, int mid,int high)
{
    int i,j,k;
    int tmp[MAX_SIZE];
    for(i=low;i<=high;i++)
        tmp[i] = a[i];
    i = k = low;
    j = mid + 1;
    while(i<=mid && j<=high)
    {
        if(tmp[i]<=tmp[j]) a[k++] = tmp[i++];
        else a[k++] = tmp[j++];
        cnt++;
    }
    while(i<=mid) a[k++] = tmp[i++];
    while(j<=high) a[k++] = tmp[j++]; 
}

void mergeSort(int v[],int low,int high)
{
    int mid;
    if(low==high) return;
    mid = (low + high)/2;
    mergeSort(v,low,mid);
    mergeSort(v,mid+1,high);
    merge(v,low,mid,high);
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
        cnt = 0;
        mergeSort(a,0,numcase-1);
        for(int k=0;k<numcase;k++)
        {
            cout << a[k] << " ";
        }
        printf("%d\n",cnt);
    }
}