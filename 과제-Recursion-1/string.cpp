#include <iostream>
#include <cstring>
using namespace std;
void reverseAraay(char s[], int i, int j);
void swap(char s[], int i, int j);

void swap(char s[], int i, int j)
{
    int tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
void reverseArray(char s[], int i, int j)
{
    if(i<j)
    {
        swap(s,i,j);
        reverseArray(s, i+1, j-1);
    }
}
int main()
{
    int num;
    scanf("%d",&num);
    for (int k=0;k<num;k++)
    {
        char *s = new char[100];
        cin >> s;
        int i = 0;
        int j = strlen(s)-1;
        reverseArray(s,i,j);
        for(int l=0;l<strlen(s);l++)
        {
            cout << s[l];
        }
        cout<<endl;
    }
}