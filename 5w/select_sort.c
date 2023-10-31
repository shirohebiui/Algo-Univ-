#include <stdio.h>
#define max 9

void sort(int *data) {
    for(int i=0; i<max; i++) {
        int key = data[i];
        int j = i-1;
        while(j>=0 && data[j]>key) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }
}

int main() {
    int data[max] = {5,3,8,4,9,1,6,2,7};
    sort(data);
    for(int i=0; i<max; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}