#include <iostream>
using namespace std;

int table[3][1001] = {0,};
char ch[3] = {'A', 'B', 'C'};
void dfa(string s);
int suffix(string a, string b);
int cnt;
int ans;


int suffix(string a, string b) {
	int i, j;
	int p = a.length();
	int s = b.length();
	if(p > s) {
        return 0;
    }

	for(i=p-1,j=s-1; i>=0; i--,j--)
    {
		if(a[i] != b[j]) {
            return 0;
        }
	}
	return 1;
}


void dfa(string s) {
	int state = 0;
	int i, j;
	for(state=0; state<s.length()+1; state++) {
		for(i=0; i<3; i++) {
			string k = s.substr(0, state);
			k += ch[i];
			string m = s.substr(0, state+1);
			j = m.length();
			while(!suffix(m, k)) 
            {
				j --;
				m = s.substr(0, j);
			}
			table[i][state] = j;
			if(j!=0) {
                ans ++;
            }
		}
	}
}


void string_matching(string a, int n) {
	int i,j;
	int state = 0;
	for(i=0;i<a.length();i++) 
    {
		if (a[i] == ch[0]) j=0;
		if (a[i] == ch[1]) j=1;
		if (a[i] == ch[2]) j=2;
		state = table[j][state];	
		if(state==n) cnt ++;
	}
}


int main() {
	int t, i;
	scanf("%d",&t);
	while (t){
        string a, b;
		cin >> a >> b;
		cnt = 0; ans = 0;
        dfa(a);
		string_matching(b, a.length());	
		cout << ans << " " << cnt << endl;
        t--;
    }
	return 0;
}
