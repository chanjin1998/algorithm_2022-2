#include <iostream>

using namespace std;

void balanceScale(int a[],int n);
int cnt;
void balanceScale(int a[],int n)
{
    int balance[7] = {100,50,20,10,5,2,1};
    cnt = 0;
    int right_scale=0, left_scale=0;
    for(int i=0;i<n;i++)
    {
        if(right_scale>left_scale) left_scale+=a[i];
        else if(right_scale<left_scale) right_scale+=a[i];
        else right_scale+=a[i];
    }
    int disc = right_scale - left_scale;
    int value = (disc > 0) ? disc : disc*-1;
    for(int i =0 ; i<7; i++) {
        for(;;) {
            if(value>=balance[i]) {
                value-=balance[i];
                cnt++;
            }else break;
        }
    }
    // return cnt;
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
            scanf("%d",&a[j]);
        }
        balanceScale(a,numCase);
        printf("%d",cnt);
        cout << endl;
    }
}
