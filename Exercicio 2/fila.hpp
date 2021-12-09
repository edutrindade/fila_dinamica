#ifndef FILA_H
#define FILA_H

typedef struct TipoItem {
    int valor;
} TipoItem;

typedef struct TipoElemento {
    TipoItem item;
    struct TipoElemento *prox;
} TipoElemento;

typedef struct TipoElemento *Apontador;

typedef struct TipoFilaCircular {
    Apontador inicio, fim;
    int tamanho;
} TipoFilaCircular;

void InicializaFilaCircular(TipoFilaCircular *fila);

bool VerificaFilaVazia(TipoFilaCircular *fila);

void Enfileira(TipoFilaCircular *fila, TipoItem item);

void Desenfileira(TipoFilaCircular *fila);

void EsvaziaFila(TipoFilaCircular *fila);

void ImprimeFilaCircular(TipoFilaCircular *fila);

#endif