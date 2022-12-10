#include <iostream>
#include <stdio.h>

using namespace std;
void copyArray(int a[], int b[], int n);
void sortHoare(int a[],int low,int high);
void sortLomuto(int a[], int low, int high);
int partitionLomuto(int a[], int low, int high);
int partitionHoare(int a[], int low, int high);

int swapLomu=0, swapHoare=0; 
int compareLomu=0, compareHoare =0;
int main(){
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        int numCase;
        swapLomu=0, swapHoare=0, compareLomu=0, compareHoare =0;
        scanf("%d",&numCase);
        int a[numCase];
        int b[numCase];
        for(int j=0;j<numCase;j++){
            scanf("%d",&b[j]);
        }
        
        copyArray(a,b,numCase);
        sortHoare(a,0,numCase-1);
        // for(int k=0;k<numCase;k++)
        // {
        //     cout << a[k] << " ";
        // }
        copyArray(a,b,numCase);
        sortLomuto(a,0,numCase-1);
        cout << swapHoare<<" "<<swapLomu<<" "<<compareHoare<<" "<<compareLomu<<'\n';  
    }
}

void sortHoare(int a[],int low,int high){
    
    int pivotPos;
    if(low>=high) return;
    pivotPos = partitionHoare(a, low, high); 
    sortHoare(a, low, pivotPos); 
    sortHoare(a, pivotPos+1, high);
}
int partitionHoare(int a[], int low, int high){

    int pivot; 
    int i, j;
    pivot = a[low];
    i = low - 1;
    j = high + 1;
    while (true) {
        compareHoare++;
        while(a[++i]<pivot){
            compareHoare++;
        }
        compareHoare++;
        while(a[--j]>pivot){
            compareHoare++;
        }
        if(i<j){
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            swapHoare++;
        } 
        else return j;
    }
}
void sortLomuto(int a[],int low,int high){
    
    int pivotPos;
    if (low>=high) return;
    pivotPos = partitionLomuto(a, low, high); 
    sortLomuto(a, low, pivotPos-1); 
    sortLomuto(a, pivotPos+1, high);
    
}
int partitionLomuto(int a[], int low, int high){
    int i,j;
    int pivot, pivotPos, tmp;
    pivot = a[low];
    j= low;
    for(i=low+1;i<=high;i++){
        compareLomu++;
        if(a[i]<pivot){
            j++;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            swapLomu++;
        }
    }
    pivotPos=j;
    tmp = a[low];
    a[low] = a[pivotPos];
    a[pivotPos] = tmp;
    swapLomu++;
    return pivotPos;
}
void copyArray(int a[], int b[], int n){
    for (int i = 0; i < n; i++)
    a[i] = b[i]; 
    }

