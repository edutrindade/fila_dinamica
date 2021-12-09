#include<iostream>
#include "fila.hpp"

using namespace std;

void InicializaFilaCircular(TipoFilaCircular *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

bool VerificaFilaVazia(TipoFilaCircular *fila) {
    if (fila->inicio == NULL) { 
        return true;        
    } else {
        return false;
    }
}

void Enfileira(TipoFilaCircular *fila, TipoItem i) {
    Apontador novo;
    novo = new TipoElemento;
    novo->item = i;
    novo->prox = NULL;
    
    if (VerificaFilaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
        novo->prox = fila->inicio;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
        fila->fim->prox = fila->inicio;
    }
    fila->tamanho++;
}

void Desenfileira(TipoFilaCircular *fila) {
    Apontador aux;
    if (VerificaFilaVazia(fila)) {
        cout << "\nFila vazia.\n\n";
    }

    if (fila->inicio == fila->inicio->prox) {
        InicializaFilaCircular(fila);
    } else {
        aux = fila->inicio;
        cout << endl << fila->inicio->item.valor << " removido da fila.\n";
        fila->inicio = fila->inicio->prox;
        fila->fim->prox = fila->inicio;
        free(aux);
        fila->tamanho--;
    }
}

void EsvaziaFila(TipoFilaCircular *fila) {
    Apontador aux;
    if (VerificaFilaVazia(fila)) {
        cout << "\nFila vazia.\n\n";
    }
    
    aux = fila->inicio;
    do {
        fila->inicio = fila->inicio->prox;
        free(aux);
        aux = fila->inicio;
    } while (aux != NULL);
    cout << "\nFila esvaziada.\n";
    fila->tamanho = 0;
    fila->inicio = NULL;
    fila->fim = NULL;
}

void ImprimeFilaCircular(TipoFilaCircular *fila) {
    Apontador aux;
    if (VerificaFilaVazia(fila)) {
        cout << "\nFila vazia.\n\n";
    } else {
        aux = fila->inicio;
        cout << "\nFila Circular: ";
        do {
            cout << aux->item.valor << " -> " << aux->prox->item.valor << " | ";
            aux = aux->prox;
        } while (aux != fila->inicio);
    }

}
