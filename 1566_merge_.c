#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int *a = (int*) malloc(n1 * sizeof(int));
    int *b = (int*) malloc(n2 * sizeof(int));

    for(int i=0;i<n1;i++) a[i] = v[l+i];
    for(int j=0;j<n2;j++) b[j] = v[m+1+j];

    int i=0, j=0, k=l;

    while(i<n1 && j<n2){
        if(a[i] <= b[j]) v[k++] = a[i++];
        else v[k++] = b[j++];
    }

    while(i<n1) v[k++] = a[i++];
    while(j<n2) v[k++] = b[j++];

    free(a);
    free(b);
}

void mergesort(int *v, int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergesort(v, l, m);
        mergesort(v, m+1, r);
        merge(v, l, m, r);
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

        mergesort(v, 0, n-1);

        for(int i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");

        free(v);
    }

    return 0;
}
