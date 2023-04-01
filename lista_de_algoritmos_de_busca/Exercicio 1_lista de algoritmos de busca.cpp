/*
	1. Implemente um programa estruturado e recursivo para pesquisa linear. Faça uma
função de busca chamada pesquisaLR que receba como parâmetro o valor a ser
encontrado e a referência do vetor onde a busca será efetuada. A função retornará -1,
caso não encontre o item, ou retornará o índice, caso o encontre
*/
#include<iostream>

using namespace std;

void busca_pesquisaLR(int *vetor[], int valor_buscado);

int main(){
	//se não encontrar o valor retorna -1
	//se encontrar o valor retorna o indice do item
	int vetor_numeros[], numero;
	
	cout<<"Digite o número a ser buscado no vetor: ";
	cin>> numero;
	cout<<endl;
	
	busca_pesquisaLR(vetor_numeros, numero);
}

void busca_pesquisaLR(int *vetor[], int valor_buscado){
	int i = 0, achou = 0;
	
	while(i <= 9 && achou == 0 && n >= vetor[i])
	{
		if(vetor[i] == valor_buscado)
			achou = 1;
		else
			i++;
	}
	if(achou == 0)
		cout<<"Numero nao encontrado no vetor"<<endl;
	else
		cout<<"Numero encontrado na posicao "<< i + 1<<endl;
	
//	getch();
}
