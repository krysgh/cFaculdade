#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct arv{
	char info;
	struct arv * sae;
	struct arv * sad;
};
typedef struct arv Arv;

Arv * inicializa(){
	return NULL;
}

int vazia(Arv * pA){
	return pA == NULL;
}

Arv* criar(char c,  Arv * sae,  Arv * sad){
	Arv* no =(Arv*) malloc(sizeof(Arv));
	no->info = c;
	no->sae = sae;
	no->sad = sad;
	return no;
}


void imprime(Arv * pA){
	if(!vazia(pA)){
		imprime(pA->sae);
		printf("%c ", pA->info);
		imprime(pA->sad);

	}	
}

void inserir(Arv ** pNoRaiz, char c){
	if(*pNoRaiz == NULL){
		*pNoRaiz = (Arv *) malloc(sizeof(Arv));
		(*pNoRaiz)->info = c;
		(*pNoRaiz)->sae = NULL;
		(*pNoRaiz)->sad = NULL;
	}
	else{
		if(c < (*pNoRaiz)->info)
			inserir(&(*pNoRaiz)->sae, c);
		else
			inserir(&(*pNoRaiz)->sad, c);
	}
}

bool noEncontrado(Arv *pNoRaiz, char c){
    if (pNoRaiz == NULL) {
        return false;
    }
    if (c == pNoRaiz->info) {
        return true;
    } else if (c < pNoRaiz->info) {
        return noEncontrado(pNoRaiz->sae, c);
    } else {
        return noEncontrado(pNoRaiz->sad, c);
    }
}


int alturaArvore(Arv *pNoRaiz){
    if (pNoRaiz == NULL) {
        return 0;
    } else {
        int altEsq = alturaArvore(pNoRaiz->sae);
        int altDir = alturaArvore(pNoRaiz->sad);
        if (altEsq > altDir)
            return altEsq + 1;
        else
            return altDir + 1;
    }
}


int main(){
	Arv * NoRaiz;

	
	NoRaiz = inicializa();
	if(!vazia(NoRaiz)){
		printf("No com dado!\n");
		//printf("%c ", NoRaiz->info);
	}
	else{
		printf("Nao existe no na arvore!\n");
	}
/*
	Arv * D = criar('d', inicializa(), inicializa());
	Arv * B = criar('b', inicializa(), D);
	Arv * E = criar('e', inicializa(), inicializa());
	Arv * F = criar('f', inicializa(), inicializa());
	Arv * C = criar('c', E, F);
	A = criar('a', B, C);
*/

	inserir(&NoRaiz, 'c');
	inserir(&NoRaiz, 'b');
	inserir(&NoRaiz, 'd');
	inserir(&NoRaiz, 'a');
	inserir(&NoRaiz, 'e');
	

	if(!vazia(NoRaiz)){
		printf("\nNo com dado!\n");
		//printf("%c ", NoRaiz->info);
	}
	else{
		printf("\nNao existe no na arvore!\n");
	}
    
    
    //ATIVIDADE 
    
    char valor = 'F';
    bool encontrado = noEncontrado(NoRaiz, valor);
    
        if(encontrado)
            printf("\n'%c' foi encontrado!\n", valor);
        else
            printf("\n'%c' não foi encontrado!\n", valor);
    
    int altura = alturaArvore(NoRaiz);
    
    printf("\nA altura da árvore é %d", altura -1);
    
    puts("\n");
    
	imprime(NoRaiz);


}