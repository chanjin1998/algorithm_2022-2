#include <iostream>
#define MAX 17
using namespace std;

int col[MAX];
int N, total = 0;
int val;
bool check(int level)
{
    for(int i = 0; i < level; i++)
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i)
            return false;
    return true;
}

void nqueen(int x)
{   
    int i;
    if(val!=0) return ;

    if (check(x)){
        if(x == N-1){
            for(i=0;i<N;i++) cout << col[i] + 1 <<" ";
            cout << endl;
            val =1;
        }
        else{  
            for(i=0;i<N;i++){
                col[x+1] = i;
                nqueen(x+1);
            }     
        }
    }
}
int main() {
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&N);
        val = 0;
        for(int j=0;j<N;j++){
            col[0] = j;
            nqueen(0);
        }
    }
    return 0;
    
}