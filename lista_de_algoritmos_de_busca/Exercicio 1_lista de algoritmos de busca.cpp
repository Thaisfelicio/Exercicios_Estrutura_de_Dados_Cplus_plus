/*
	1. Implemente um programa estruturado e recursivo para pesquisa linear. Fa�a uma
fun��o de busca chamada pesquisaLR que receba como par�metro o valor a ser
encontrado e a refer�ncia do vetor onde a busca ser� efetuada. A fun��o retornar� -1,
caso n�o encontre o item, ou retornar� o �ndice, caso o encontre
*/
#include<iostream>
#include<locale.h>

using namespace std;

const int TAMANHO = 5;

void inserir_dados(int *vetor);
int busca_pesquisaLR(int *vetor, int valor_buscado, int tamanho_vetor, int indice = 0);

int main(){
	//se n�o encontrar o valor retorna -1
	//se encontrar o valor retorna o indice do item
	setlocale(LC_ALL,"Portuguese");
	int vetor_numeros[TAMANHO];
	int numero_buscado;
	
	inserir_dados(vetor_numeros);
	cout<<"Digite o numero a ser buscado no vetor: ";
	cin>>numero_buscado;
	
	int indice = busca_pesquisaLR(vetor_numeros, numero_buscado, TAMANHO);
	if(indice == -1)
		cout<<"Valor "<< numero_buscado <<" n�o encontrado"<<endl;
	else
		cout<<"o numero esta na posi��o "<< indice <<" do vetor"<<endl;
		
	return 0;
}

void inserir_dados(int *vetor){
	int i;
	
	for(i = 0; i < TAMANHO; i++)
	{
		cout<<"Digite o "<< i + 1<<" n�mero a ser inserido no vetor: ";
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

