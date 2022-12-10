#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 1000
void insertionSort(int a[], int n);
void swap(int *a, int *b);
int main()
{
   int numTestCases;
   scanf("%d", &numTestCases);
   for (int i = 0; i < numTestCases; ++i)
   {
      int num;
      int a[MAX_SIZE];
      scanf("%d", &num);
      for (int j = 0; j < num; j++)
         scanf("%d", &a[j]);
      insertionSort(a, num);
   }
   return 0;
}
void swap(int *a, int *b)
{
   int tmp = *a;
   *a = *b;
   *b = tmp;
}
/* Insertion Sort 함수 */
void insertionSort(int a[], int n)
{
   int i, j, tmp, cnt;
   int countCmpOps = 0; // 비교 연산자 실행 횟수
   int countSwaps = 0;  // swap 함수 실행 횟수
   // insertion sort 알고리즘 구현
   for (i = 1; i < n; i++)
   {
      tmp = a[i];
      for (j = i - 1; j >= 0; j--)
      {
         countCmpOps++;

         if (a[j] > tmp)
         {
            countSwaps++;
            a[j + 1] = a[j];
         }
         else break;
      }
      a[j + 1] = tmp;
   }
   printf("%d %d \n", countCmpOps, countSwaps);
}