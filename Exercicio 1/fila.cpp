#include<iostream>
#include "fila.hpp"

using namespace std;

void InicializaFila(TipoFila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

bool VerificaFilaVazia(TipoFila *fila) {
    if (fila->inicio == NULL) { // Ninguém na fila
        return true;        
    } else {
        return false;
    }
}

void Enfileira(TipoFila *fila, TipoItem i) {
    Apontador novo;
    novo = new TipoElemento;
    novo->item = i;
    novo->prox = NULL;
    
    if (VerificaFilaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    fila->tamanho++;
}

void Desenfileira(TipoFila *fila) {
    Apontador aux;
    if (VerificaFilaVazia(fila)) {
        cout << "\nFila vazia.\n\n";
    }
    
    aux = fila->inicio;
    fila->inicio = fila->inicio->prox;
    free(aux);
    fila->tamanho--;
}

void EsvaziaFila(TipoFila *fila) {
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

void ImprimeProximo(TipoFila *fila) {
    if (VerificaFilaVazia(fila)) {
        cout << "\nFila vazia.\n\n";
    } else {
        cout << "\nNome: " << fila->inicio->item.nome; 
        cout << "\nTelefone: " << fila->inicio->item.telefone;
        cout << "\nSolicitação: " << fila->inicio->item.solicitacao << endl << endl;
        Desenfileira(fila);
    }
}
