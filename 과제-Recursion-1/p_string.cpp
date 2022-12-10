#include <iostream>
#include <cstring>
using namespace std;

void permute(char *str);
void permuteString(char *str, int begin, int end);
void swap(int* a, int* b);
int cnt =0;

int main(){
    int num;
    scanf("%d",&num);
    for (int i=0;i<num;i++)
    {
        cnt = 0;
        char *str= new char[100];
        cin >> str;
        permute(str);
        printf("%d\n",cnt);
    }
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}
void permuteString(char *str, int begin, int end){
    int i;
    int range = end - begin;
    if (range == 1){
        int sum=0;
        int value[strlen(str)];
        for (i=0;i<strlen(str);i++){
            value[i] = int(str[i])-97;
        }
        for (i=0;i<strlen(str);i++){
            if (i%2==0) {
                sum = sum + value[i];
            }
            else {
                sum = sum - value[i];
            }
        }
        if (sum>0) 
            {
                cnt = cnt + 1;
            }
    } 
    else{
        for (i=0; i<range; i++){
            swap(str[begin], str[begin+i]);
            permuteString(str, begin+1, end);
            swap(str[begin], str[begin+i]);
            }
    }
}
void permute(char *str)
{
    permuteString(str, 0, strlen(str));
}