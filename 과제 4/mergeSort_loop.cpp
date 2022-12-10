#include <iostream>
#define MAX_SIZE 100

using namespace std;
void merge(int a[],int low, int mid, int high);
int min(int a, int b);
void mergeSort(int a[], int n);
int cnt = 0;
void merge(int a[],int low, int mid, int high)
{
    int i,j,k;
    int tmp[MAX_SIZE];
    for(i=low;i<=high;i++)
    {
        tmp[i] = a[i];
    }
    i = k =low;
    j = mid+1;
    while(i<=mid && j<=high)
    {
        if(tmp[i] <= tmp[j])
        {
            a[k++] = tmp[i++];
            cnt++;
        }
        else 
        {
            a[k++] = tmp[j++];
            cnt++;
        }
    }
    while(i<=mid) a[k++] = tmp[i++];
    while(j<=high) a[k++] = tmp[j++];
}
void mergeSort(int a[], int n)
{
    int size = 1;
    while(size<n)
    {
        for (int i =0;i<n;i +=2*size)
        {
            int low = i;
            int mid = low + size -1;
            int high = min(i+2*size-1,n-1);

            if(mid>=n-1) break;
            merge(a,low,mid,high);
        }
        size *=2;
    }
}
int min(int a, int b)
{
    if (a>b) return b;
    else return a;
}
int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        int numCase;
        scanf("%d",&numCase);
        int a[numCase];
        for(int j=0;j<numCase;j++){
            scanf("%d",&a[j]);
        }
        cnt = 0;
        mergeSort(a,numCase);
        cout << cnt << endl;
    }
}