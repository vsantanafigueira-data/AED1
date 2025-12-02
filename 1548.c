#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}

int main(){
    int n;
    scanf("%d", &n);

    while(n--){
        int m;
        scanf("%d", &m);

        int *v = (int*) malloc(m * sizeof(int));
        int *c = (int*) malloc(m * sizeof(int));

        for(int i=0;i<m;i++){
            scanf("%d", &v[i]);
            c[i] = v[i];
        }

        qsort(c, m, sizeof(int), cmp);

        int cont = 0;
        for(int i=0;i<m;i++){
            if(v[i] == c[i]) cont++;
        }

        printf("%d\n", cont);

        free(v);
        free(c);
    }

    return 0;
}
