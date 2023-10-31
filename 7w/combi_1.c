#include <stdio.h>
#define MAX 10000

int combi(int n, int r) {
    if(n == r || r == 0) {
        return 1;
    }
    return combi(n-1, r-1) + combi(n-1 ,r);
}

int main() {

    printf("%d\n", combi(4, 2));

    return 0;
}