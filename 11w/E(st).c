#include "stdio.h"
#include "string.h"
#define MAX 1000

char S[MAX];
char T[MAX];
int rec(int m, int n) {
	if(!m) return n;
	if(!n) return m;

	if(S[m-1] == S[n-1]) return rec(m-1, n-1);

	int min = rec(m, n-1) + 1 < rec(m-1, n) ? rec(m, n-1) : rec(m-1, n);
	min = min < rec(m-1, n-1) ? min : rec(m-1, n-1);
	return min + 1;
}
// O(3^N)

int mem[MAX][MAX];
int dp(int m, int n) {
	if(!m) return n;
	if(!n) return m;

	if(mem[m][n] == 0)
		if(S[m-1] == S[n-1]) {
			mem[m][n] = dp(m-1, n-1);
		}

	int min = dp(m-1, n) < dp(m, n-1) ? dp(m-1, n) : dp(m, n-1);
	min = min < dp(m-1, n-1) ? min : dp(m-1, n-1);

	mem[m-1][n-1] = 1 + min;
}


int main() {
	char *s;
	s = S;
	s = "tuesday";
	s = T;
	s = "thursday";
	dp(strlen(S), strlen(T));
	printf("%d\n", mem[strlen(S)][strlen(T)]);
	return 0;
}