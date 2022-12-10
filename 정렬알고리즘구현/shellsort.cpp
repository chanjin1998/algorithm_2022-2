// #include <stdio.h>
// #include <cmath>
// #define MAX_SIZE 1000
// void ShellSort(int a[], int n);
// void swap(int* a, int* b);
// void inc_insertion_sort(int a[], int first, int last, int gap);
// int main()
// {
//     int numTestCases;
//     scanf("%d", &numTestCases);
//     for (int i = 0; i < numTestCases; ++i)
//     {
//         int num;
//         int a[MAX_SIZE];
//         scanf("%d", &num);
//         for (int j = 0; j < num; j++)
//             scanf("%d", &a[j]);
//         ShellSort(a, num);
//     }
//     return 0; 
// }
// void swap(int* a, int* b)
// {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp; 
// }
// /* Shell Sort 함수 */

// void inc_insertion_sort(int a[], int first, int last, int gap){
//     int i, j, key;

//     for(i=first+gap; i<=last; i=i+gap){
//         key = a[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

//     // 현재 정렬된 배열은 i-gap까지이므로 i-gap번째부터 역순으로 조사한다.
//     // j 값은 first 이상이어야 하고
//     // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+gap번째로 이동
//         for(j=i-gap; j>=first && a[j]>key; j=j-gap){
//             a[j+gap] = a[j]; // 레코드를 gap만큼 오른쪽으로 이동
//     }

//     a[j+gap] = key;
//   }
// }

// // 셸 정렬
// void Shellsort(int a[], int n){
//     int i, gap;
//     int countCmpOps = 0; // 비교 연산자 실행 횟수 
//     int countSwaps = 0; // swap 함수 실행 횟수

//     for(gap=n/2; gap>0; gap=gap/2){
//         if((gap%2) == 0){
//             gap++; // gap을 홀수로 만든다.
//             countSwaps++;
//         }
//             // 부분 리스트의 개수는 gap과 같다.
//         for(i=0; i<gap; i++){
//             // 부분 리스트에 대한 삽입 정렬 수행
//             inc_insertion_sort(a, i, n-1, gap);
//         }
//     }
// }
# include <stdio.h>
# define MAX_SIZE 10

// gap만큼 떨어진 요소들을 삽입 정렬
// 정렬의 범위는 first에서 last까지
void inc_insertion_sort(int list[], int first, int last, int gap){
  int i, j, key;

  for(i=first+gap; i<=last; i=i+gap){
    key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

    // 현재 정렬된 배열은 i-gap까지이므로 i-gap번째부터 역순으로 조사한다.
    // j 값은 first 이상이어야 하고
    // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+gap번째로 이동
    for(j=i-gap; j>=first && list[j]>key; j=j-gap){
      list[j+gap] = list[j]; // 레코드를 gap만큼 오른쪽으로 이동
    }

    list[j+gap] = key;
  }
}

// 셸 정렬
void shell_sort(int list[], int n){
  int i, gap;
  int countCmpOps = 0;
  int countSwaps= 0;
  for(gap=n/2; gap>0; gap=gap/2){
    if((gap%2) == 0){
      gap++; // gap을 홀수로 만든다.
    }

    // 부분 리스트의 개수는 gap과 같다.
    for(i=0; i<gap; i++){
      // 부분 리스트에 대한 삽입 정렬 수행
      countSwaps++;
      inc_insertion_sort(list, i, n-1, gap);
    }
  }
  printf("%d",countSwaps);
}

int main(){
    int i;
    // 셸 정렬 수행
    int numTestCases;
    int num;
    int list[MAX_SIZE];
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
            scanf("%d", &list[j]);
        shell_sort(list, num);
    }
    // 정렬 결과 출력
    for(i=0; i<num; i++){
    printf("%d", list[i]);
    }
}