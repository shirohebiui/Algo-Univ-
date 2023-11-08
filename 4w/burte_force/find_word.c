#include <stdio.h>
#include <string.h>

char T[100] = "HELLO WORLD";
char P[100] = "LO";

int find_word() {
    int n = strlen(T);
    int m = strlen(P);

    for(int i=0; i<n-m-1; i++) {
        int j=0;
        if(T[i] == P[j]) {
            for(;j<m;j++) {
                if(T[i+j] != P[j]) {
                    break;
                }
                if(j == m-1) {
                    return i;
                }
            }
        }
    }
    return -1;
}

int main() {
    
    printf("%d\n", find_word());

    return 0;
}