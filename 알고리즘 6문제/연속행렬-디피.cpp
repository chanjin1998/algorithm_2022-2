#include <iostream>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX 99999999;
using namespace std;

int a[101][101];
int m[101][101];
int d[102];

void cmm(int n);
void print(int i, int j);

int main(){
    int numcase;
    scanf("%d",&numcase);
    while(numcase--){
        int n;
        scanf("%d",&n);
        for(int j=0; j<=n; j++) 
            scanf("%d",&d[j]);

        cmm(n+1);
        print(1, n); 
        cout << endl;

        cout << m[1][n] << endl;
    }
    return 0;
}

void cmm(int n){
    for(int val=0; val<n; val++){
        for(int i=0; i<n-val; i++){
            int j = i + val;
            if(j==i) m[i][j] = 0;
            else {
                m[i][j] = MAX;
                for(int k=i; k<j; k++){
                    if(m[i][j] > (m[i][k] + m[k+1][j]) + (d[i-1]*d[k]*d[j])) 
                        a[i][j] = k;
                    m[i][j] = MIN(m[i][j], (m[i][k] + m[k+1][j]) + (d[i-1]*d[k]*d[j]));
                }
            }
        }
    }
}

void print(int i, int j){
    if(i == j) cout << "M" << i;
    else{
        int k = a[i][j];
        cout << "(";
        print(i, k);
        print(k+1, j);
        cout << ")";
    }
}
