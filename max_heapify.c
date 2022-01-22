#include <stdlib.h>
#include <stdio.h>

// altura heap 0(log(n))
// operações O(log(n))
// max-heapify O(log(n))
// build-max-heap O(n)
// heap-sort O(nlog(n))

void max_heapify(int *A, int i, int len){

	int l = 2*i;
	int r = 2*i+1;
	int maior;

	if(l <= len && *(A+l-1) > *(A+i-1)){
		maior = l;
	}
	else{
		maior = i;
	}
	if(r <= len && *(A+r-1) > *(A+maior-1)){
		maior = r;
	}
	if(maior != i){
		int aux = *(A+i-1);
		*(A+i-1) = *(A+maior-1);
		*(A+maior-1) = aux;
		max_heapify(A, maior, len);
	}
}

void max_heapify_iterative(int *A, int i, int len){
	while(i < len){
		int l = 2*i;
		int r = 2*i+1;
		int maior = i;
	
		if(l <= len && *(A+l) > *(A+i)){
			maior = l;
		}
	
		if(r <= len && *(A+r) > *(A+maior)){
			maior = r;
		}
		if(maior != i){
			int aux = *(A+i);
			*(A+i) = *(A+maior);
			*(A+maior) = aux;
		}
	}
}
void build_heap(int *A, int len){
	for(int i=len;i>1;i--){
		max_heapify(A, i/2, len);	
	}
}
void main(){
	int n;
	scanf("%d", &n);
	int *p = (int*) malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d", (p+i));
	}
	build_heap(p, n);
	for(int i=0;i<n;i++){
		printf("*%d ", *(p+i));		
	}
}
