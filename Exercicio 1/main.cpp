#include <iostream>
#include <windows.h>
#include "fila.cpp"

using namespace std;

void menu();
void InsereContato(TipoFila *fila);
void ProximoContato(TipoFila *fila);

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    TipoFila f;
    TipoItem i;

    InicializaFila(&f);

    if (VerificaFilaVazia(&f)) {
        cout << "Fila vazia.\n\n";
    }

    int opcao;
    system("cls");

    do {
        menu();
        while((cout << "Escolha a opção: ") && !(cin >> opcao)) {
            cout << "Digite uma opção válida.\n\n";
            cin.clear(); cin.ignore();
        }
        system("cls");
        switch (opcao) {
        case 1: 
            InsereContato(&f);
            break;
        case 2: 
            ProximoContato(&f); 
            break;
        }
    } while (opcao != 3);

    return 0;
}

void menu() {    
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                         CALL CENTER                          �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 1 - INSERIR CONTATO                                          �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 2 - PRÓXIMO CONTATO                                          �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 3 - SAIR                                                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n\n";
}

void InsereContato(TipoFila *fila) { 
    TipoItem i;
    cout << "***********************************\n";
    cout << "        CADASTRO DE CONTATO        \n";
    cout << "***********************************\n\n";
    cin.ignore();
    cout << "Nome: ";
    gets(i.nome);
    cout << "Telefone: ";
    gets(i.telefone);
    cout << "Solicitação: ";
    gets(i.solicitacao);

    Enfileira(fila, i);

    cout << "\nContato registrado com sucesso!\n\n";
    Sleep(1000);
    system("cls");
}

void ProximoContato(TipoFila * fila) {
    cout << "***********************************\n";
    cout << "        PRÓXIMO ATENDIMENTO        \n";
    cout << "***********************************\n\n";

    ImprimeProximo(fila);
    
    system("PAUSE");
    system("cls");
}
