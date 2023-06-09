/*
	4. Faça um programa que receba 20 números e armazene os pares em uma lista 
simplesmente encadeada e não ordenada e os ímpares em uma segunda lista 
simplesmente encadeada e não ordenada. Posteriormente, o programa deve montar 
uma terceira lista, duplamente encadeada e ordenada de forma crescente, com os 
números das duas listas anteriores. Para finalizar, o programa deve mostrar todos os 
números da terceira lista das seguintes formas:
a. Crescente.
b. Decrescente.
*/
#include<iostream>

using namespace std;
typedef struct Noh_simples{
	int numero;
	Noh_simples *proximo;
}Noh_simples;

typedef struct Noh_dupla{
	int numero;
	Noh_dupla *proximo;
	Noh_dupla *anterior;
}Noh_dupla;

typedef struct Lista{
	Noh_simples *inicio_simples, *fim_simples;
	Noh_dupla *inicio, *fim;
	int tamanho;
	bool alteracao;
}Lista;

int menu(){
	int opcao;
	
	do
	{
		cout<<endl << "MENU DE OPCOES" <<endl;	
		cout<< "1 - Inserir no inicio da lista" <<endl;
		cout<< "2 - Inserir no fim da lista" <<endl;
		cout<< "3 - Imprimir a terceira lista de forma crescente" <<endl;
		cout<< "4 - Imprimir a terceira lista de forma decrescente" <<endl;
		cout<< "5 - Esvaziar lista" <<endl;
		cout<< "6 - Sair" <<endl;
		
		cout<<"Digite sua escolha: ";
		cin>>opcao;
		
		if(opcao < 1 || opcao > 6)
			cout<<"\tEscolha invalida!"<<endl;
	}while(opcao < 1 || opcao > 6);
	
	return opcao;
}

void inserirInicio(Lista *list, int numero)
{
	Noh_simples *novo = new Noh_simples();
	novo->numero = numero;
	
	if(list->inicio_simples == NULL)
	{
		novo->proximo = NULL;
		list->inicio_simples = novo;
		list->fim_simples = novo;
	}
	else
	{
		novo->proximo = list->inicio_simples;
		list->inicio_simples = novo;
	}
	list->tamanho++;
}

void inserirFim(Lista *list, int numero)
{
	Noh_simples *novo = new Noh_simples();
	novo->numero = numero;
	novo->proximo = NULL;
	
	if(list->inicio_simples == NULL)
	{
		list->inicio_simples = novo;
		list->fim_simples = novo;
	}
	else
	{
		list->fim_simples->proximo = novo;
		list->fim_simples = novo;
	}
	list->tamanho++;
}

void inserirCrescente(Lista *lista_dupla, int numero){
	Noh_dupla *novo = new Noh_dupla();
	novo->numero = numero;
	
	if(lista_dupla->inicio == NULL)
	{
		novo->proximo = NULL;
		novo->anterior = NULL;
		lista_dupla->inicio = novo;
		lista_dupla->fim = novo;
	}
	else
	{
		Noh_dupla *pAux = lista_dupla->inicio;
		
		while(pAux != NULL && novo->numero > pAux->numero)//ordenando em ordem crescente
		{
			pAux = pAux->proximo;
		}
		
		if(pAux == lista_dupla->inicio)
		{
			novo->proximo = lista_dupla->inicio;
			novo->anterior = NULL;
			lista_dupla->inicio->anterior = novo;
			lista_dupla->inicio = novo;
		}
		else if(pAux == NULL)
		{
			novo->anterior = lista_dupla->fim;
			novo->proximo = NULL;
			lista_dupla->fim->proximo = novo;
			lista_dupla->fim = novo;
		}
		else
		{
			novo->proximo = pAux;
			novo->anterior = pAux->anterior;
			pAux->anterior->proximo = novo;
			pAux->anterior = novo;
		}
	}
	lista_dupla->tamanho++;
}

void concatenar_listas(Lista *list1, Lista *list2, Lista *lista_dupla){
	Noh_simples *pAux1 = list1->inicio_simples;
	Noh_simples *pAux2 = list2->inicio_simples;
	
	while(pAux1 != NULL)
	{
		inserirCrescente(lista_dupla, pAux1->numero);
		pAux1 = pAux1->proximo;
	}	
	while(pAux2 != NULL)
	{
		inserirCrescente(lista_dupla, pAux2->numero);
		pAux2 = pAux2->proximo;
	}
}

void esvaziar(Lista *lista1, Lista *lista2, Lista *lista_dupla){
	if(lista1->inicio_simples != NULL)
	{
		Noh_simples *pAux1;
		
		while(lista1->inicio_simples != NULL)
		{
			pAux1 = lista1->inicio_simples;
			lista1->inicio_simples = lista1->inicio_simples->proximo;
			delete(pAux1);
			
			lista1->tamanho--;
		}
	}
	if(lista2->inicio_simples != NULL)
	{
		Noh_simples *pAux2;
		
		while(lista2->inicio_simples != NULL)
		{
			pAux2 = lista2->inicio_simples;
			lista2->inicio_simples = lista2->inicio_simples->proximo;
			delete(pAux2);
			
			lista2->tamanho--;
		}
	}
	if(lista_dupla->inicio != NULL)
	{
		Noh_dupla *pAux_dupla;
		
		while(lista_dupla->inicio != NULL)
		{
			pAux_dupla = lista_dupla->inicio;
			lista_dupla->inicio = lista_dupla->inicio->proximo;
			delete(pAux_dupla);
			
			lista_dupla->tamanho--;
		}
	}
	else
		cout<< endl <<"Lista vazia ..."<< endl << endl;
}

void imprime_listaSimples(Lista *lista_simples){
	if(lista_simples->inicio_simples != NULL)
	{
		Noh_simples *pAux = lista_simples->inicio_simples;
		
		while(pAux != NULL)
		{
			cout<< pAux->numero<< " ";//impressão do nó atual
			pAux = pAux->proximo;
		}
		cout<< endl <<"Tamanho da lista: "<< lista_simples->tamanho << endl;
		cout<<endl<<endl; 
	}
	else
		cout<<"Lista vazia!"<<endl<<endl;
}

void imprime_crescente(Lista *lista_dupla){
	if(lista_dupla->inicio != NULL)
	{
		Noh_dupla *pAux = lista_dupla->inicio;
		
		while(pAux != NULL)
		{
			cout<< pAux->numero<< " ";//impressão do nó atual
			pAux = pAux->proximo;
		}
		cout<< endl <<"Tamanho da lista: "<< lista_dupla->tamanho << endl;
		cout<<endl<<endl; 
	}
	else
		cout<<"Lista vazia!"<<endl<<endl;
}

void imprime_decrescente(Lista *lista_dupla){
	if(lista_dupla->inicio != NULL)
	{
		Noh_dupla *pAux = lista_dupla->fim;
		
		while(pAux != lista_dupla->inicio)
		{
			cout<< pAux->numero<< " ";//impressão do nó atual
			pAux = pAux->anterior;
		}
		cout<<lista_dupla->inicio->numero;
		cout<< endl <<"Tamanho da lista: "<< lista_dupla->tamanho << endl;
		cout<<endl<<endl; 
	}
	else
		cout<<"Lista vazia!"<<endl<<endl;
}
int main(){
	Lista listaSimples_pares;
	
	listaSimples_pares.inicio_simples = NULL;
	listaSimples_pares.fim_simples = NULL;
	listaSimples_pares.tamanho = 0;
	listaSimples_pares.alteracao = false;
	
	Lista listaSimples_impares;
	
	listaSimples_impares.inicio_simples = NULL;
	listaSimples_impares.fim_simples = NULL;
	listaSimples_impares.tamanho = 0;
	listaSimples_impares.alteracao = false;
	
	Lista lista_dupla;
	
	lista_dupla.inicio = NULL;
	lista_dupla.fim = NULL;
	lista_dupla.tamanho = 0;
	lista_dupla.alteracao = false;
	
	int escolha, numero;
	
	do
	{
		escolha = menu();
		
		switch(escolha){
			case 1:
				cout<<"Digite o numero a ser inserido no inicio da lista: ";
				cin>> numero;
				if(numero % 2 == 0)
					inserirInicio(&listaSimples_pares, numero);
				else
					inserirInicio(&listaSimples_impares, numero);
				listaSimples_pares.alteracao = true;
				listaSimples_impares.alteracao = true;
			break;
			
			case 2:
				cout<<"Digite o numero a ser inserido no fim da lista: ";
				cin>> numero;
				if(numero % 2 == 0)
					inserirFim(&listaSimples_pares, numero);
				else
					inserirFim(&listaSimples_impares, numero);
				listaSimples_pares.alteracao = true;
				listaSimples_impares.alteracao = true;
			break;
			
			case 3:
				cout<<"Imprimindo de forma crescente ..."<<endl<<endl;
				cout<<"LISTA DE NUMEROS PARES"<<endl;
				imprime_listaSimples(&listaSimples_pares);
				
				cout<<"LISTA DE NUMEROS IMPARES"<<endl;
				imprime_listaSimples(&listaSimples_impares);
				
				if(listaSimples_pares.alteracao || listaSimples_impares.alteracao)//essa flag serve para que quando chame esse case de novo não se concatene as listas novamente
				{
					concatenar_listas(&listaSimples_pares, &listaSimples_impares, &lista_dupla);
					listaSimples_pares.alteracao = false;
					listaSimples_impares.alteracao = false;
				}
				
				cout<<"A TERCEIRA LISTA"<<endl;
				imprime_crescente(&lista_dupla);
			break;
			
			case 4:
				cout<<"Imprimindo de forma decrescente ..."<<endl<<endl;
				cout<<"LISTA DE NUMEROS PARES"<<endl;
				imprime_listaSimples(&listaSimples_pares);
				
				cout<<"LISTA DE NUMEROS IMPARES"<<endl;
				imprime_listaSimples(&listaSimples_impares);
				
				if(listaSimples_pares.alteracao || listaSimples_impares.alteracao)
				{
					concatenar_listas(&listaSimples_pares, &listaSimples_impares, &lista_dupla);
					listaSimples_pares.alteracao = false;
					listaSimples_impares.alteracao = false;
				}
				cout<<"A TERCEIRA LISTA"<<endl;
				imprime_decrescente(&lista_dupla);
			break;
			
			case 5:
				cout<<"Esvaziando a lista ...";
				esvaziar(&listaSimples_pares, &listaSimples_impares, &lista_dupla);
			break;
			
			default:
				cout<<"Saindo ...";
				
		}
	}while(escolha != 6);
}
