#include<stdio.h>
#include<stdlib.h>

void gerarVetor(int*, int);
void print_vet(int*, int);
int busca(int, int, int*, int);
void ord(int*, int);

int main(){
	int n, *vet, dado, aux=1, achou;
	puts("\n\n\tqnt d elem: ");
	scanf("%d", &n);
	vet=malloc(n*sizeof(int));
	
	gerarVetor(vet, n);
	
	//print_vet(vet, n);
	
	ord(vet,n);
	print_vet(vet, n);
	while(aux){
		puts("\n\tnum a ser buscado:");
		scanf("%d", &dado);
		achou=busca(0, n-1, vet, dado);
		if(achou<0) puts("\n\telemento nao encontrado!");
		else printf("\n\telem %d esta na posicao %d", dado, achou+1);
		puts("\n\tdeseja continuar buscando? 1-S 0-N");
		scanf("%d", &aux);
	}
	//puts("ord");
	return 0;
}

int busca(int i, int j, int *vet, int dado){
	int mid;
	
	if(dado==vet[i]) return i;
	
	if(dado==vet[j]) return j;
	
	mid = (j-i)*dado/(vet[j]-vet[i]);
	
	while(i<j && vet[mid]!=dado){
		if(vet[mid]>dado)
			j=mid-1;
		else
			i=mid+1;
		mid=(j-i)*dado/(vet[j]-vet[i]);
	}
	if(vet[mid]==dado) return mid;
	else return(-1);
}


void print_vet(int* vet, int n){
	int i=0;
	puts("\n\n");
	for(i=0; i<n; i++)
		printf("\t[%d]", *(vet+i));
	return;
}

void gerarVetor(int *vet, int n){
	int i=0;
	srand(time(NULL));
	for (i = 0;i < n;i++) 
    	vet[i] = rand() % (n * 10);    
}

void ord(int* vet, int n){
	int i, j, k, l, valor; // k = gap // i, j , l = auxiliares para as iteraçoes
	k = 1;
	while (k < n/2)
		k = 3*k + 1; // calcula passo inicial
	while (k != 1)
		{ k = k/3;
		for (l=0; l<k; l++){ // insertion ajustado para passo k
	
			for (i=l+k; i<n; i=i+k){
				valor = vet[i];
				j = i;
				while (j-k>=0 && vet[j-k] > valor){ 
					vet[j] = vet[j-k];
					j=j-k;
				}
				vet[j] = valor;
			}
		}
	
	}
	return;
}

