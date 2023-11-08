#include <stdio.h>
#include <string.h>
#define MAX 100


char std[MAX] = "HELLO WORLD";
char cmp[MAX] = "GAME OVER";

//worst rec func
int LCS_rec(char *X, char *Y, int m, int n) {
	if(m==0 && n==0) {
		return 0;
	} else if(X[m-1] == Y[n-1]) {
		return 1 + LCS_rec(X, Y, m-1, n-1);
	} else {
		return LCS_rec(X, Y, m, n-1) > LCS_rec(X, Y, m-1, n) ? LCS_rec(X, Y, m, n-1) : LCS_rec(X, Y, m-1, n);
	}
}


void print(int DP[][MAX], int m, int n) {
	printf(" ");
	for(int i=0; i<=m; i++)
		printf(" %c", std[i]);
	printf("\n");
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(j==1)
				printf("%c", cmp[i-1]);
			printf(" %d", DP[j][i]);
		}
		printf("\n");
	}
}
//dp func
void LCS_dp(char *X, char *Y) {
	int m = strlen(X);
	int n = strlen(Y);
	int DP[MAX][MAX] = {0, };
	
	for(int i=0; i<=m; i++) {
		for(int j=0; j<=n; j++) {
			if(i==0 || j==0) {
				DP[i][j] = 0;
			} else if(X[i-1] == Y[j-1]) {
				DP[i][j] = DP[i-1][j-1] + 1;
			} else {
				DP[i][j] = DP[i-1][j] > DP[i][j-1] ? DP[i-1][j] : DP[i][j-1];
			}
		}
	}
	print(DP, m, n);
}


int main() {
	LCS_dp(std, cmp);
	return 0;
}