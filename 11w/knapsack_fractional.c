#include "stdio.h"
float knapsack_fractional(float W, int n, int *w, int *v) {
	float V;
	for(int i=0; i<n; i++) {
		if(W > w[i]) {
			V += v[i];
			W -= w[i];
		} else {
			V += v[i] * (W/(float)w[i]);
			break;
		}
	}
	return V;
}
int main() {
	float W = 18, V = 0;
	int w1[10] = {12, 10, 8};
	int v1[10] = {120, 80, 60};
	printf("%.2f\n", knapsack_fractional(W, 3, w1, v1));
	int w2[10] = {12, 10, 8};
	int v2[10] = {120, 90, 60};
	printf("%.2f\n", knapsack_fractional(W, 3, w2, v2));
	return 0;
}