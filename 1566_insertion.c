#include <stdio.h>
#include <stdlib.h>

void insertion(int *v, int n){
    for(int i=1;i<n;i++){
        int x = v[i];
        int j = i - 1;
        while(j >= 0 && *(v + j) > x){
            *(v + j + 1) = *(v + j);
            j--;
        }
        *(v + j + 1) = x;
    }
}

int main(){
    int nc;
    scanf("%d", &nc);

    while(nc--){
        int n;
        scanf("%d", &n);

        int *v = (int*) malloc(n * sizeof(int));

        for(int i=0;i<n;i++) scanf("%d", v + i);

        insertion(v, n);

        for(int i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d", *(v + i));
        }
        printf("\n");

        free(v);
    }

    return 0;
}
