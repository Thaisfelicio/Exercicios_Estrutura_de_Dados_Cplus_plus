/*
	6. Fa�a um programa que implemente uma lista encadeada de n�meros inteiros com
inser��o de dados pelo usu�rio atrav�s de um menu. Escreva uma fun��o que
verifique se esta lista est� em ordem crescente e outra fun��o que fa�a uma busca na
lista, dado um elemento passado pelo usu�rio. Fa�a vers�es recursiva e iterativa.
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
