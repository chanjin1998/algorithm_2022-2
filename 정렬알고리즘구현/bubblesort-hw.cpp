#include <stdio.h>


#define MAX_SIZE 1000

void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);

int main()
{
    int numTestCases;
    scanf("%d>>", &numTestCases);
    for (int i = 0; i < numTestCases; ++i){
        int num;
        int a[MAX_SIZE], b[MAX_SIZE];
        
        scanf("%d >>", &num);
        for (int j = 0; j < num; j++) scanf("%d", &b[j]);
        
        copyArray(a, b, num);
        bubbleSort(a, num);
        
        copyArray(a, b, num);
        bubbleSortImproved1(a, num);
        
        copyArray(a, b, num);
        bubbleSortImproved2(a, num);
        printf("\n");
    }
return 0; 
}
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp; 
    }

void bubbleSort(int a[], int n){
    int countCmpOps = 0;
    int countSwaps = 0; 

    for(int pass=0; pass<n; pass++){
        for(int i=1; i<n-pass; i++){
            if(a[i-1]>a[i]){
                swap(&a[i-1],&a[i]);
                countSwaps++;
            }
            countCmpOps++;
        }
        
    }

    printf("%d %d ", countCmpOps, countSwaps);
    }


void bubbleSortImproved1(int a[], int n){
    int countCmpOps = 0; 
    int countSwaps = 0; 

    for(int pass=1; pass<n; pass++){
        bool swapped = false;
        for(int i=1; i<=n-pass; i++){
            if(a[i-1] > a[i]){
                swap(&a[i-1], &a[i]);
                swapped = true;
                countSwaps++;
            }
            countCmpOps++;
        }
        if (swapped == false) break;
        
    }
    printf("%d %d ", countCmpOps, countSwaps);
    }


void bubbleSortImproved2(int a[], int n){
    int countCmpOps = 0;  
    int countSwaps = 0; 

    int lastSwappedPos = n;
    
    while(lastSwappedPos>0){
        int swappedPos = 0;
        for(int i=1; i < lastSwappedPos; i++){
            if(a[i-1] > a[i]){
                swap(&a[i-1], &a[i]);
                swappedPos =i;
                countSwaps++;
            }
            countCmpOps++;
            
        }
        lastSwappedPos = swappedPos;
    }
        printf("%d %d ", countCmpOps, countSwaps);
    }

void copyArray(int a[], int b[], int n){
    for (int i = 0; i < n; i++)
        a[i] = b[i];
    }