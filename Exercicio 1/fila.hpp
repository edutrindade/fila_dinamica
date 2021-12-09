#ifndef FILA_H
#define FILA_H

typedef struct TipoItem {
    char nome[20];
    char telefone[15];
    char solicitacao[100];
} TipoItem;

typedef struct TipoElemento {
    TipoItem item;
    struct TipoElemento *prox;
} TipoElemento;

typedef struct TipoElemento *Apontador;

typedef struct TipoFila {
    Apontador inicio, fim;
    int tamanho;
} TipoFila;

void InicializaFila(TipoFila *fila);

bool VerificaFilaVazia(TipoFila *fila);

void Enfileira(TipoFila *fila, TipoItem item);

void Desenfileira(TipoFila *fila);

void ImprimeProximo(TipoFila *fila);

#endif