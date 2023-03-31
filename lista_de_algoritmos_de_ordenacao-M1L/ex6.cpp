/*6-Elabore um programa que implemente um vetor de estruturas com os seguintes
dados: nome, idade e sexo. O programa deve apresentar os dados em:
a. Ordem crescente alfabatica de nome (use o quick sort).
b. Ordem decrescente de idade (use o bubble sort).
*/


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int TAMANHO = 5;

struct Pessoa {
    string nome;
    int idade;
    char sexo;
};

// Função auxiliar para trocar dois elementos de um vetor
void trocar(Pessoa& p1, Pessoa& p2) {
    Pessoa temp = p1;
    p1 = p2;
    p2 = temp;
}

// Implementação do quicksort para ordenar por nome
void quickSortNome(Pessoa pessoas[], int esquerda, int direita) {
    int i = esquerda, j = direita;
    string pivo = pessoas[(esquerda + direita) / 2].nome;

    while (i <= j) {
        while (pessoas[i].nome < pivo)
            i++;
        while (pessoas[j].nome > pivo)
            j--;
        if (i <= j) {
            trocar(pessoas[i], pessoas[j]);
            i++;
            j--;
        }
    }

    if (esquerda < j)
        quickSortNome(pessoas, esquerda, j);
    if (i < direita)
        quickSortNome(pessoas, i, direita);
}

// Implementação do bubble sort para ordenar por idade
void bubbleSortIdade(Pessoa pessoas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pessoas[j].idade < pessoas[j + 1].idade) {
                trocar(pessoas[j], pessoas[j + 1]);
            }
        }
    }
}

// Função para imprimir as informações de uma pessoa
void imprimirPessoa(Pessoa pessoa) {
    cout << "Nome: " << pessoa.nome << ", Idade: " << pessoa.idade << ", Sexo: " << pessoa.sexo << endl;
}

int menu(){
	// Menu de opções
    int opcao;
    do
    {
    	cout<<"\t\t MENU DE OPCOES"<<endl;
    	cout << "1. Ordem crescente alfabetica de nome" << endl;
    	cout << "2. Ordem decrescente de idade" << endl;
    	cout<<"3. Sair"<<endl;
    	cout << endl << "Digite sua opcao de ordenacao:" << endl;
    	cin >> opcao;
    	
    	if(opcao < 1 || opcao > 3)
			cout<<"Opcao invalida"<<endl;
	}while(opcao < 1 || opcao > 3);
    return opcao;
}

void inserir_dados(struct Pessoa *cadastrarPessoa){
    // Preenchimento das informações das pessoas
    for (int i = 0; i < TAMANHO; i++) {
        cout << "Preencha as informacoes da pessoa " << i + 1 << endl;
        cout << "Nome: ";
        cin >> cadastrarPessoa[i].nome;
        cout << "Idade: ";
        cin >> cadastrarPessoa[i].idade;
        cout << "Sexo (M/F): ";
        cin >> cadastrarPessoa[i].sexo;
    }
}
int main() {
    Pessoa pessoas[TAMANHO];
	int escolha;
	
	inserir_dados(pessoas);
	
	do
	{
		escolha = menu();
		switch (escolha) 
		{
        	case 1:
            	// Ordenação por nome usando quicksort
            	quickSortNome(pessoas, 0, TAMANHO - 1);
            	for(int i = 0; i < TAMANHO; i++) 
                	imprimirPessoa(pessoas[i]);
            	break;

        	case 2:
            	// Ordenação por idade usando bubble sort
            	bubbleSortIdade(pessoas, TAMANHO);
            	for(int i = 0; i < TAMANHO; i++) 
                	imprimirPessoa(pessoas[i]);
            	break;
            
        	default:
           		cout << "Saindo ..."<< endl;
            	break;
		}
	}while(escolha != 3);
    
return 0;
}

