#include <stdio.h>
#include <math.h>


float distance(int *a, int *b) {
    return sqrt(pow(a[0]-b[0] ,2) + pow(a[1]-b[1], 2));
}

int p[6][2] = {
    {2,3}, {12,30}, {40,50}, {5,1}, {12,10}, {3,4}
};
int max = sizeof(p)/(sizeof(int) * 2);

float closest_pair(int p[][2]) {
    float min = 10000*10000;
    for(int i=0; i<max; i++) {
        for(int j=i+1; j<max;j++) {
            min = min > distance(p[i], p[j]) ? distance(p[i], p[j]) : min;
        }
    }
    return min;
}

int main() {
    printf("%f\n", closest_pair(p));
    return 0;
}