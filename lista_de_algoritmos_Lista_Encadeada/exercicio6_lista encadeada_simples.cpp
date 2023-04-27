/*
	6. Faça um programa que implemente uma lista encadeada de números inteiros com
inserção de dados pelo usuário através de um menu. Escreva uma função que
verifique se esta lista está em ordem crescente e outra função que faça uma busca na
lista, dado um elemento passado pelo usuário. Faça versões recursiva e iterativa.
*/

#include<iostream>

using namespace std;

typedef struct Noh{
	int numero;
	Noh *proximo;
}Noh;

typedef struct Lista{
	Noh *inicio, *fim;
	int tamanho;
}Lista;

int menu(){
	int opcao;
	
	do
	{
		cout<<endl << "MENU DE OPCOES" <<endl;	
		cout<< "1 - Inserir no inicio da lista" <<endl;
		cout<< "2 - Inserir no fim da lista" <<endl;
		cout<< "3 - Imprimir toda a lista" <<endl;
		cout<< "4 - Buscar numero na lista" <<endl;
		cout<< "5 - Esvaziar lista" <<endl;
		cout<< "6 - Sair" <<endl;
		
		cout<<"Digite sua escolha: ";
		cin>>opcao;
		
		if(opcao < 1 || opcao > 6)
			cout<<"\tEscolha invalida!"<<endl;
	}while(opcao < 1 || opcao > 6);
	
	return opcao;
}

bool eVazia(Lista *list)
{
	if(list->inicio == NULL)
		return true;
	return false;
}

int main(){
	
}
