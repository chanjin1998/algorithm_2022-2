#include <iostream>
using namespace std;
void maxSubsequenceSum(int a[],int n,int start,int end);

void maxSubsequenceSum(int a[],int n,int start,int end)
{
	int i,j;
	int maxSum = 0;
	int thisSum = 0;
	start = end = -1;
	for(i=0,j=0;j<n;j++)
	{
		thisSum += a[j];
		if(thisSum > maxSum)
		{
			maxSum = thisSum;
			start = i;
			end = j;
			if(a[start]==0) start++;
		}
		else if(thisSum<0)
		{
			i = j+1;
			thisSum = 0;
		}
	}
	cout<<maxSum<<" " << start << " " << end << "\n";
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
		maxSubsequenceSum(a, n, 0 ,n-1);
;
    }
	return 0;
}