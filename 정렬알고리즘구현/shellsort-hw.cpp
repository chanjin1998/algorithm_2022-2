#include <stdio.h>
#define MAX_SIZE 1000
void ShellSort(int a[], int n);
int main(){
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i){
        int num;
        int a[MAX_SIZE];
        scanf("%d", &num);
        for (int j = 0; j < num; j++) scanf("%d", &a[j]);
        ShellSort(a, num);
    }
    return 0; 
}
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}
void ShellSort(int a[], int n){
    int countCmpOps = 0; 
    int countSwaps = 0; 

    int shrinkRatio = 2;
    int gap = n/shrinkRatio;
    
    while(gap >0){
        for(int i=gap; i<n; i++){
            int tmp = a[i];
            for(int j=i; j>=gap;j-=gap){
                countCmpOps++;
                if(a[j-gap]>tmp){
                    
                    swap(&a[j-gap],&a[j]);
                    countSwaps++;
                }
                else break;
            }
        }
        gap/=shrinkRatio;
    }
    printf("%d %d \n", countCmpOps, countSwaps);
}