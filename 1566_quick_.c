#include <stdio.h>
#include <stdlib.h>

int particao(int *v, int l, int r){
    int p = v[r];
    int i = l - 1;
    for(int j=l;j<r;j++){
        if(v[j] <= p){
            i++;
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
        }
    }
    int t = v[i+1];
    v[i+1] = v[r];
    v[r] = t;
    return i+1;
}

void quicksort(int *v, int l, int r){
    if(l < r){
        int p = particao(v, l, r);
        quicksort(v, l, p-1);
        quicksort(v, p+1, r);
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

        quicksort(v, 0, n-1);

        for(int i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");

        free(v);
    }

    return 0;
}
