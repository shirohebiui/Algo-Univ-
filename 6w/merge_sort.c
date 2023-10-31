#include <stdio.h>
#include <string.h>
#include <time.h>

int arr[100] = { 49, 56, 23, 10, 78, 3, 30, 19, 66, 91, 53, 70, 41, 45, 84, 61, 14, 5, 77, 36, 
99, 72, 83, 47, 90, 25, 57, 79, 21, 89, 34, 60, 9, 58, 68, 67, 39, 6, 51, 93, 
2, 33, 26, 12, 97, 18, 65, 35, 15, 80, 96, 98, 22, 13, 92, 75, 16, 69, 7, 46, 
1, 71, 64, 55, 20, 11, 86, 27, 73, 94, 44, 87, 37, 8, 74, 38, 81, 95, 63, 85, 
54, 40, 42, 48, 62, 32, 88, 29, 82, 43, 76, 52, 4, 50, 59, 31, 28, 17, 100, 24 };

void merge(int *data, int left, int mid, int right) {
    int tmp[100] = {0, };
    int i = left, j = mid+1;
    int now = left;
    while(i <= mid && j <= right) {
        if(data[i] < data[j]) {
            tmp[now] = data[i++];
        } else {
            tmp[now] = data[j++];
        }
        now++;
    }
    while(i<=mid) {
        tmp[now++] = data[i++];
    }
    while(j<=right) {
        tmp[now++] = data[j++];
    }
    int s = left;
    
    // for(int s = left; s<=right; s++) {
    //     data[s] = tmp[s];
    // }
    memcpy(&data[s], &tmp[s], sizeof(int)*(right - left + 1));
}

void merge_sort(int *data, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        merge_sort(data, left, mid);
        merge_sort(data, mid+1, right);
        merge(data, left, mid, right);
    }
}

int main() {
clock_t st, et;
st = clock();
    merge_sort(arr, 0, 99);
et = clock();
    for(int i=0; i<100; i++)
        printf("%d ", arr[i]);
    printf("\n");
printf("%f ms\n", (float)(et - st));
    return 0;
}