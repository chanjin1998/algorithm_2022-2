#include <iostream>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int mulRec(int a[], int i, int j);

int main(){
    int numcase; 
    scanf("%d",&numcase);

    while(numcase--){
        int n; 
        scanf("%d",&n);
        int a[n+1];
        for(int i=0; i<=n; i++)  scanf("%d",&a[i]);
        cout << mulRec(a, 1, n) << endl;
    }
    return 0;
}

int mulRec(int a[], int i, int j){
    int m, tmp;
    if(i == j) return 0;
    m = 999999999;
    
    for(int k=i; k<j; k++){
        tmp = mulRec(a, i, k) + mulRec(a, k+1, j) + (a[i-1] * a[k] * a[j]);
        m = MIN(m, tmp);
    }
    return m;
}