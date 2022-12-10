#include <iostream>
using namespace std;
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
            scanf("%d",&a[j]);
        }
		for(int j=0;j<numCase;j++)
		{
			cout << a[j] << " ";
		}
	}
}