#include <stdio.h> 
#define MAX 4
int data[MAX] = {1,2,3,4};
int select[MAX] = {0,};

void print() {
    for(int i=0; i<MAX; i++) {
        if(select[i]) {
            printf("%d ", data[i]);
        }
    }
    printf("\n");
}

void BT(int find, int sum,int lv) {
    if(lv == MAX) return;
    if(sum > find) {
        return;
    }
    if(sum == find) {
        // print();
    }
    printf("lv %d : ", lv);
    for(int i=lv; i<MAX; i++) 
        printf("%d ", data[i]);
    printf("\n");
    for(int i=lv; i<MAX; i++) {
        if(select[i] == 0) {
            select[i]=1;
            BT(find, sum+data[i], lv + 1);
            select[i]=0;
        }
    }
}

int main() {
    BT(5, 0, 0);
    return 0;
}