#include <stdio.h>
#include <stdlib.h>

void selection(int *v, int n){
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(*(v+j)<*(v+m)) m=j;
        }
        int t=*(v+i);
        *(v+i)=*(v+m);
        *(v+m)=t;
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

        selection(v, n);

        for(int i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d", *(v+i));
        }
        printf("\n");

        free(v);
    }

    return 0;
}
