/*
Faça um programa que cadastre 15 números, não permitindo números repetidos.
Ordene-os e, em seguida, verifique se o número digitado pelo usuário está no vetor.
Caso encontre, verifique se está numa posição par ou ímpar do vetor:
a. Usando busca sequencial.
b. Usando busca binária.
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int TAMANHO = 15;

void lerNumeros() {
    cout << "Digite " << tamanho << " números:\n";
    for (int i = 0; i < tamanho; i++) {
        cin >> numeros[i];
        // Verifica se o número já foi digitado anteriormente
        for (int j = 0; j < i; j++) {
            if (numeros[j] == numeros[i]) {
                cout << "Número duplicado! Digite outro número.\n";
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
    cout << "Números ordenados: ";
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
    
    cout << "Digite um número para buscar (busca sequencial): ";
    cin >> num_usuario;
    int posicao_sequencial = buscarSequencial(num_usuario);
    if (posicao_sequencial != -1) {
        cout << "Número encontrado na posição " << posicao_sequencial;
        if (posicao_sequencial % 2 == 0) {
            cout << " (posição par)\n";
        } else {
            cout << " (posição ímpar)\n";
        }
    } else {
        cout << "Número não encontrado.\n";
    }
    
    cout << "Digite um número para buscar (busca binária): ";
    cin >> num_usuario;
    int posicao_binaria = buscarBinaria(num_usuario);
    if (posicao_binaria != -1) {
        cout << "Número encontrado na posição " << posicao_binaria;
        if (posicao_binaria % 2 == 0) {
            cout << " (posição par)\n";
        } else {
            cout << " (posição ímpar)\n";
        }
    } else {
        cout << "Número não encontrado.\n";
    }

    return 0;
}
