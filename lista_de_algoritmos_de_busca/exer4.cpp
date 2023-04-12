#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Produto {
    int codigo;
    string descricao;
    double preco;
};

void cadastrarProdutos(Produto produtos[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Produto " << i+1 << ":" << endl;
        cout << "Codigo: ";
        cin >> produtos[i].codigo;
        cout << "Descricao: ";
        cin.ignore();
        getline(cin, produtos[i].descricao);
        cout << "Preco: R$ ";
        cin >> produtos[i].preco;
    }
}

void imprimirProdutos(Produto produtos[], int n) {
    cout << "Produtos cadastrados:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Codigo: " << produtos[i].codigo << endl;
        cout << "Descricao: " << produtos[i].descricao << endl;
        cout << "Preco: R$ " << produtos[i].preco << endl;
        cout << endl;
    }
}

int compararCodigo(const void *a, const void *b) {
    Produto *produtoA = (Produto *)a;
    Produto *produtoB = (Produto *)b;
    return (produtoA->codigo - produtoB->codigo);
}

void trocar(Produto& p1, Produto& p2) {
    Produto temp = p1;
    p1 = p2;
    p2 = temp;
}

void quickSortCodigo(Produto produtos[], int esquerda, int direita) {
    int i = esquerda, j = direita;
    int pivo = produtos[(esquerda + direita) / 2].codigo;

    while (i <= j) {
        while (produtos[i].codigo < pivo)
            i++;
        while (produtos[j].codigo > pivo)
            j--;
        if (i <= j) {
            trocar(produtos[i], produtos[j]);
            i++;
            j--;
        }
    }

    if (esquerda < j)
        quickSortCodigo(produtos, esquerda, j);
    if (i < direita)
        quickSortCodigo(produtos, i, direita);
}

int buscarSequencial(Produto produtos[], int n, int codigo) {
    int comparacoes = 0;
    for (int i = 0; i < n; i++) {
        comparacoes++;
        if (produtos[i].codigo == codigo) {
            return comparacoes;
        }
    }
    return comparacoes;
}

int buscarBinaria(Produto produtos[], int n, int codigo) {
    int comparacoes = 0;
    int esquerda = 0;
    int direita = n - 1;
    while (esquerda <= direita) {
        comparacoes++;
        int meio = (esquerda + direita) / 2;
        if (produtos[meio].codigo == codigo) {
            return comparacoes;
        } else if (produtos[meio].codigo < codigo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return comparacoes;
}

int main() {
    const int n = 12;
    Produto produtos[n];
    cadastrarProdutos(produtos, n);
    cout << endl;
    quickSort(produtos, n, sizeof(Produto), compararCodigo);
    imprimirProdutos(produtos, n);
    cout << endl;
    int codigoBusca;
    cout << "Digite o codigo do produto que deseja buscar: ";
    cin >> codigoBusca;
    cout << "Busca sequencial - numero de comparacoes: " << buscarSequencial(produtos, n, codigoBusca) << endl;
    cout << "Busca binaria - numero de comparações: " << buscarBinaria(produtos, n, codigoBusca) << endl;
    return 0;
}

