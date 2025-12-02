#include <stdio.h>
#include <stdlib.h>

void heapify(int *v, int n, int i){
    int m = i;
    int e = 2*i + 1;
    int d = 2*i + 2;

    if(e < n && v[e] > v[m]) m = e;
    if(d < n && v[d] > v[m]) m = d;

    if(m != i){
        int t = v[i];
        v[i] = v[m];
        v[m] = t;
        heapify(v, n, m);
    }
}

void heapsort(int *v, int n){
    for(int i=n/2-1;i>=0;i--) heapify(v, n, i);
    for(int i=n-1;i>0;i--){
        int t = v[0];
        v[0] = v[i];
        v[i] = t;
        heapify(v, i, 0);
    }
}

int main(){
    int nc;
    scanf("%d", &nc);

    while(nc--){
        int n;
        scanf("%d", &n);

        int *v = (int*) malloc(n * sizeof(int));

        for(int i=0;i<n;i++) scanf("%d", v+i);

        heapsort(v, n);

        for(int i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");

        free(v);
    }

    return 0;
}
