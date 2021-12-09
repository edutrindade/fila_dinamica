#include <iostream>
#include "fila.cpp"

using namespace std;

int main() {
    TipoFilaCircular f;
    TipoItem i;

    InicializaFilaCircular(&f);

    if (VerificaFilaVazia(&f)) {
        cout << "Fila vazia.\n";
    }

    i.valor = 5;
    Enfileira(&f, i);

    i.valor = 6;
    Enfileira(&f, i);

    i.valor = 8;
    Enfileira(&f, i);

    ImprimeFilaCircular(&f);
    cout << "Tamanho: " << f.tamanho;

    Desenfileira(&f);
    ImprimeFilaCircular(&f);
    cout << "Tamanho: " << f.tamanho;

    Desenfileira(&f);
    ImprimeFilaCircular(&f);
    cout << "Tamanho: " << f.tamanho;

    return 0;
}
