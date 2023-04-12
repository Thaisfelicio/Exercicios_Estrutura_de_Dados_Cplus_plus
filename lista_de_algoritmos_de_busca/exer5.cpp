/*
Fa�a um programa que cadastre 15 n�meros, n�o permitindo n�meros repetidos.
Ordene-os e, em seguida, verifique se o n�mero digitado pelo usu�rio est� no vetor.
Caso encontre, verifique se est� numa posi��o par ou �mpar do vetor:
a. Usando busca sequencial.
b. Usando busca bin�ria.
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int TAMANHO = 15;

void lerNumeros() {
    cout << "Digite " << tamanho << " n�meros:\n";
    for (int i = 0; i < tamanho; i++) {
        cin >> numeros[i];
        // Verifica se o n�mero j� foi digitado anteriormente
        for (int j = 0; j < i; j++) {
            if (numeros[j] == numeros[i]) {
                cout << "N�mero duplicado! Digite outro n�mero.\n";
                i--;
                break;
            }
        }
    }
}

void ordenarNumeros() {
    sort(numeros, numeros + tamanho);
}

void imprimirNumeros() {
    cout << "N�meros ordenados: ";
    for (int i = 0; i < tamanho; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
}

int buscarSequencial(int num_usuario) {
    for (int i = 0; i < tamanho; i++) {
        if (numeros[i] == num_usuario) {
            return i;
        }
    }
    return -1;
}

int buscarBinaria(int num_usuario) {
    int inicio = 0;
    int fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (numeros[meio] == num_usuario) {
            return meio;
        } else if (numeros[meio] < num_usuario) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    int num_usuario;

    lerNumeros();
    ordenarNumeros();
    imprimirNumeros();
    
    cout << "Digite um n�mero para buscar (busca sequencial): ";
    cin >> num_usuario;
    int posicao_sequencial = buscarSequencial(num_usuario);
    if (posicao_sequencial != -1) {
        cout << "N�mero encontrado na posi��o " << posicao_sequencial;
        if (posicao_sequencial % 2 == 0) {
            cout << " (posi��o par)\n";
        } else {
            cout << " (posi��o �mpar)\n";
        }
    } else {
        cout << "N�mero n�o encontrado.\n";
    }
    
    cout << "Digite um n�mero para buscar (busca bin�ria): ";
    cin >> num_usuario;
    int posicao_binaria = buscarBinaria(num_usuario);
    if (posicao_binaria != -1) {
        cout << "N�mero encontrado na posi��o " << posicao_binaria;
        if (posicao_binaria % 2 == 0) {
            cout << " (posi��o par)\n";
        } else {
            cout << " (posi��o �mpar)\n";
        }
    } else {
        cout << "N�mero n�o encontrado.\n";
    }

    return 0;
}
