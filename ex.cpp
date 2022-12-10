#include <iostream>
using namespace std;

#define MAX_SIZE 100

void merge(int a[],int low,int mid,int high)
{
    int i,j,k;
    int tmp[MAX_SIZE];
    for(int i=low;i<=high;i++)
        tmp[i] = a[i];
    i = k = low;
    j = mid + 1;
    while(i<=mid&&j<=high)
    {
        if(tmp[i]<=tmp[j])
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
    }
    while(i<=mid)
        a[k++] = tmp[i++];
    while(j<=high)
        a[k++] = tmp[j++];
}
void mergeSort(int a[], int low, int high)
{
    int mid;
    if(low == high)
        return;
    mid = (low+high)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid,high);
}