#include <stdio.h>
#define MAX 10000
long mem[MAX];

long fib_dp(int n) {
    if(mem[n] == 0) {
        if(n < 2)
            mem[n] = n;
        else
            mem[n] = fib_dp(n-1) + fib_dp(n-2);
    }
    return mem[n];
}

int main() {

    printf("%ld\n", fib_dp(10));

    return 0;
}