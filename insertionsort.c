#include <stdlib.h>
#include <stdio.h>

void insertion_sort(int *A, int len){
	for(int j=1;j<len;j++){

		int chave = *(A+j);
		int i = j-1;

		while(i>-1 && *(A+i)>chave){
			*(A+i+1) = *(A+i);
			i = i - 1;
		}
		*(A+i+1) = chave;
	}
}

int main(void){
	int *p, x, i;
	int n;
	scanf("%d", &n);
	p = (int*) malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d", &x);
		*(p+i) = x; 
	}
	insertion_sort(p, n);
	for(i=0;i<n;i++){
		printf("*%d ", *(p+i));
	}
}

