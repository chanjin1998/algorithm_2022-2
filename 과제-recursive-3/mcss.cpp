#include <iostream>
#include <limits.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
int max(int a, int b, int c)
{
    return MAX(MAX(a, b), c);
}

int maxSum(int a[], int low, int mid, int high)
{
	int sum = 0;
	int left_sum = INT_MIN;
	for (int i=mid;i >=low;i--) 
    {
		sum = sum + a[i];
		if (sum > left_sum)
			left_sum = sum;
	}
	sum = 0;
	int right_sum = INT_MIN;
	for (int i=mid;i<=high;i++) {
		sum = sum + a[i];
		if (sum > right_sum)
			right_sum = sum;
	}
	return max(left_sum + right_sum - a[mid], left_sum, right_sum);
}

int maxSubsequenceSum(int a[],int low,int high)
{
	if (low > high)
		return INT_MIN;
	if (low == high)
		return a[low];
	int mid = (low + high) / 2;
    if (max(maxSubsequenceSum(a, low, mid - 1),
			maxSubsequenceSum(a, mid + 1, high),
			maxSum(a, low, mid, high))<=0)
        return 0;
    else{
        return max(maxSubsequenceSum(a, low, mid - 1),
                maxSubsequenceSum(a, mid + 1, high),
                maxSum(a, low, mid, high));
    }
}

int main()
{
    int num;
    cin >> num;
    for(int i=0;i<num;i++)
    {
        int numcase;
        cin >> numcase;
        int a[numcase];
        for(int j=0;j<numcase;j++)
        {
            scanf("%d",&a[j]);
        }
        int n = sizeof(a) / sizeof(a[0]);
	    int max_sum = maxSubsequenceSum(a, 0, n - 1);
	    printf("%d\n", max_sum);
    }
	return 0;
}
