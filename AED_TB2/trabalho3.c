// Informações do estudante
// Nome: Gustavo Lamin Honda
// Curso: Ciência da Computação
// RA: 811716

#include <stdio.h>
#include <stdlib.h>

typedef struct celula Celula;
struct celula {
    int conteudo;
    Celula *prox;
};

void insere(Celula *lst, int x) {
    Celula *nova;
    nova = (Celula*) malloc(sizeof(Celula));
    nova->conteudo = x;
    nova->prox = lst->prox;
    lst->prox = nova;
}


void Remove(Celula *lst) {
    Celula *morta;
    morta = lst->prox;
    lst->prox = morta->prox;
    free(morta);
}

int resolveJosephus(int n, int m) {
    Celula *ini;
    ini = (Celula*) malloc(sizeof(Celula));
    ini->conteudo = 1;
    ini->prox = ini;
    
    Celula* temp = ini;
    for(int i = 2; i <= n; i++) {
        insere(temp, i);
        temp = temp->prox; 
    }

    temp = ini;
    Celula* homicidio;
    for(int i = 1; i <= n-1; i++) {
        int j = 0;
        homicidio = temp;
        while (j < m-1) {
            temp = temp->prox;
            j++;
        }
        if (temp->prox->conteudo == homicidio->conteudo && !(m == 1)) {
            temp = temp->prox;
        }
        Remove(temp);
        temp = temp->prox;
    }

    return temp->conteudo;
}

int main () {
    int nroexecs; 
    scanf ("%d", & nroexecs );
    int n[nroexecs];  
    int m[nroexecs];
    for (int i = 0; i < nroexecs ; i ++) { 
        scanf ("%d", & n [ i ]) ;
        scanf ("%d", & m [ i ]) ;
    }

    for (int i = 0; i < nroexecs ; i ++) {
        printf ("Usando n=%d, m=%d, resultado=%d\n", n [ i ] , m [i] , resolveJosephus ( n [ i ] , m [ i ]));
    }

    return 0;
}