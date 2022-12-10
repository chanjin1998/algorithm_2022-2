#include <iostream>
using namespace std;
void hanoi(int n, int a, int b, int c);
int i = 1;
int cnt = 0;
int value[100] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};

void hanoi(int n, int a, int b, int c)
{
    if(n>0)
    {
        hanoi(n-1,a,c,b);
        if (c==3)
        {
            value[i]=n;
            if(value[i]!= value[i-1])
            {   
                cout << value[i] << " ";
                i = i + 1;
            }

        }
        else if(a==3)
        {
            i = i -1 ;
            if(i==0)
                cout << 0 << " ";
            else
            {
                cout << value[i-1] << " ";
            }
        }        
        hanoi(n-1,b,a,c);
        
    }
}
int main()
{
    int num;
    scanf("%d",&num);
    for(int k=0;k<num;k++)
    {
        int numCase;
        cin >> numCase;
        i = 0;
        hanoi(numCase,1,2,3);
        // for (int j=0;j<i;j++)
        // {
        //     cout<<value[j]<<" ";
        // }   
        cout << endl;
    }
}