/*
	1. Implemente um programa estruturado e recursivo para pesquisa linear. Faça uma
função de busca chamada pesquisaLR que receba como parâmetro o valor a ser
encontrado e a referência do vetor onde a busca será efetuada. A função retornará -1,
caso não encontre o item, ou retornará o índice, caso o encontre
*/
#include<iostream>
#include<locale.h>

using namespace std;

const int TAMANHO = 5;

void inserir_dados(int *vetor);
int busca_pesquisaLR(int *vetor, int valor_buscado, int tamanho_vetor, int indice = 0);

int main(){
	//se não encontrar o valor retorna -1
	//se encontrar o valor retorna o indice do item
	setlocale(LC_ALL,"Portuguese");
	int vetor_numeros[TAMANHO];
	int numero_buscado;
	
	inserir_dados(vetor_numeros);
	cout<<"Digite o numero a ser buscado no vetor: ";
	cin>>numero_buscado;
	
	int indice = busca_pesquisaLR(vetor_numeros, numero_buscado, TAMANHO);
	if(indice == -1)
		cout<<"Valor "<< numero_buscado <<" não encontrado"<<endl;
	else
		cout<<"o numero esta na posição "<< indice <<" do vetor"<<endl;
		
	return 0;
}

void inserir_dados(int *vetor){
	int i;
	
	for(i = 0; i < TAMANHO; i++)
	{
		cout<<"Digite o "<< i + 1<<" número a ser inserido no vetor: ";
		cin>> vetor[i];
		cout<<endl;
	}
}

int busca_pesquisaLR(int *vetor, int valor_buscado, int tamanho_vetor, int indice){
	if(indice == tamanho_vetor)
		return -1;
		
	else if(vetor[indice] == valor_buscado)
		return indice;
	
	else
		return busca_pesquisaLR(vetor, valor_buscado, tamanho_vetor, indice+1);
}

