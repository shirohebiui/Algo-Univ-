#include <stdio.h>
#include <string.h>
#define MAX 100
int parent[MAX];
int edge[MAX][3];
int best[MAX][3]; int best_rear;
int size;
int edge_cnt;

void init() {
    for(int i=0; i<size; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if(x == parent[x]) return x;
    return find(parent[x]);
}

void _union(int a, int b) {
    parent[a] = b;
}

void kruskal() {
    for(int i=0; i<size-1; i++) {
        if(find(edge[i][0]) != find(edge[i][1])) {
            _union(edge[i][0], edge[i][1]);
            best[best_rear][0] = edge[i][0];
            best[best_rear][1] = edge[i][1];
            best[best_rear][2] = edge[i][2];
            best_rear++;
        }
    }
}
void print_edge();
void print_parent();
void input_edge();
int main() {
    size = 7;//scanf("%d", &size);
    edge_cnt = 9;
    init();
    input_edge(); //정렬 생략, 정렬된 input가정
    kruskal();
    print_edge();
    print_parent();

    return 0;
}

void input_edge() {
    char start, end;
    int cost;
    for(int i=0; i<edge_cnt; i++) {
        scanf(" %c %c %d", &start, &end, &cost);
        edge[i][0] = start - 'A';
        edge[i][1] = end - 'A';
        edge[i][2] = cost;
    }
}

void print_parent() {
    for (int i = 0; i < size; i++)
    {
        printf("%2c ", parent[i]+ 'A');
    }
    printf("\n");
}

void print_edge() {
    for(int i=0; i<best_rear; i++) {
        printf("%d: ", i);
        printf("%c %c %d\n", best[i][0]+'A', best[i][1]+'A', best[i][2]);
    }
    printf("\n");
}