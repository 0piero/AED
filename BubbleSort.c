#include <stdlib.h>
#include <stdio.h>

int bubble_sort(int *V, int n);
int main(void)
{
    int *p, n, i, iterations;
    scanf("%d", &n);
    p = (int*) malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d", p+i);
    }
    iterations = bubble_sort(p, n);
    printf("%d\n", iterations);
    for(i=0;i<n;i++)
    {
        printf("%d ", *(p+i));
    }
    free(p);
}

int bubble_sort(int *V, int n)
{
    int k, i, j, aux;
    k=0;
    for(i=0;i<n;i++){
        for(j=0;j<n-1-i;j++){
            if(V[j] > V[j+1]){
                aux=V[j];
                V[j]=V[j+1];
                V[j+1]=aux;
                k++;
            }
        }
    }
return k;
}


