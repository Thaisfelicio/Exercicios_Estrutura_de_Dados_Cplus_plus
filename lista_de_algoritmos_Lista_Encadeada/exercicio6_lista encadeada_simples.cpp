/*
	6. Faça um programa que implemente uma lista encadeada de números inteiros com
inserção de dados pelo usuário através de um menu. Escreva uma função que
verifique se esta lista está em ordem crescente e outra função que faça uma busca na
lista, dado um elemento passado pelo usuário. Faça versões recursiva e iterativa.
*/

#include<iostream>
#include<locale.h>

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
		cout<< "[1] - Inserir no inicio da lista" <<endl;
		cout<< "[2] - Inserir no fim da lista" <<endl;
		cout<< "[3] - Imprimir toda a lista" <<endl;
		cout<< "[4] - Buscar numero na lista" <<endl;
		cout<< "[5] - Esvaziar lista" <<endl;
		cout<< "[6] - Verificar se a lista está em ordem crescente" <<endl;
		cout<< "[7] - Sair" <<endl;
		
		cout<<"Digite sua escolha: ";
		cin>>opcao;
		
		if(opcao < 1 || opcao > 7)
			cout<<"\tEscolha invalida!"<<endl;
	}while(opcao < 1 || opcao > 7);
	
	return opcao;
}

bool eVazia(Lista *list)
{
	if(list->inicio == NULL)
		return true;
	return false;
}

void inserirInicio(Lista *list, int numero)
{
	Noh *novo = new Noh();
	novo->numero = numero;
	
	if(eVazia(list))
	{
		novo->proximo = NULL;
		list->inicio = novo;
		list->fim = novo;
	}
	else
	{
		novo->proximo = list->inicio;
		list->inicio = novo;
	}
	list->tamanho++;
}

void inserirFim(Lista *list, int numero)
{
	Noh *novo = new Noh();
	novo->numero = numero;
	novo->proximo = NULL;
	
	if(eVazia(list))
	{
		list->inicio = novo;
		list->fim = novo;
	}
	else
	{
		list->fim->proximo = novo;
		list->fim = novo;
	}
	list->tamanho++;
}

void imprime(Lista *list){
	cout<< endl <<"Tamanho da lista: "<< list->tamanho << endl;
	if(eVazia(list))
		cout<<"Lista vazia!"<<endl;
	else
	{
		Noh *pAux = list->inicio;
		
		while(pAux != NULL)
		{
			cout<< pAux->numero<< " ";
			pAux = pAux->proximo;
		}
		cout<<endl<<endl; 
	}
}

void esvaziar(Lista *list){
	if(!eVazia(list))
	{
		Noh *pAux;
		
		while(list->inicio != NULL)
		{
			pAux = list->inicio;
			list->inicio = list->inicio->proximo;
			delete(pAux);
			
			list->tamanho--;
		}
		
	}
	else
		cout<< endl <<"Lista vazia ..."<< endl << endl;
}

int buscarValor_iterativa(Lista *list, int valor){
	if(!eVazia(list))
	{
		Noh *pAux = list->inicio;
		int indice = 0;
		
		while(pAux != NULL)
		{
			if(pAux->numero == valor)
				return indice;
			
			else
			{
				pAux = pAux->proximo;
				indice ++;
			}	
		}
		return -1;
	}
}

int buscarValor_recursiva(Lista *list, Noh *node, int valor, int indice = 0){//o indice é parametro opcional
	if(node == NULL)
		return -1;
		
	else if(node->numero == valor)
		return indice;
	
	return buscarValor_recursiva(list, node->proximo, valor, indice+1);
}

bool verificarOrdem_crescente_iterativa(Lista *list){
	if(!eVazia(list))
	{
		Noh *pAux = list->inicio;
		
		while(pAux->proximo != NULL)
		{
			if(pAux->numero > pAux->proximo->numero)
				return false;
			
			pAux = pAux->proximo;
		}
		return true;		
	}
}

bool verificarOrdem_crescente_recursiva(Noh *node){
	if(node->proximo == NULL || node == NULL)
		return true;

	else if(node->numero <= node->proximo->numero)
			return verificarOrdem_crescente_recursiva(node->proximo);
		
		return false;
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	Lista lista;
	Noh noh;
	
	//inicialização da lista: (zerada para uso)
	lista.inicio = NULL;
	lista.fim = NULL;
	lista.tamanho = 0;
	
	int escolha, numero, indice, eCrescente;
	bool opcaoBusca, opcaoVerificar;
	
	do
	{
		escolha = menu();
		
		switch(escolha){
			case 1:
				cout<<"Digite o numero a ser inserido no inicio na lista: ";
				cin>>numero;
				inserirInicio(&lista, numero);
			break;
			
			case 2:
				cout<<"Digite o numero a ser inserido no fim na lista: ";
				cin>>numero;
				inserirFim(&lista, numero);
			break;
			
			case 3:
				cout<<"Imprimindo a lista ...";
				imprime(&lista);
			break;
			
			case 4:
				if(eVazia(&lista))
				{
					cout<<endl<<"A lista está vazia, não há o que buscar"<<endl<<"Preencha a lista primeiro"<<endl;
					break;
				}
					
					
				cout<<endl<<"Digite 1 para buscar o numero de forma iterativa ou "<<endl<<"\tdigite 0 para buscar o numero de forma recursiva"<<endl;
				cin>>opcaoBusca;
				
				if(opcaoBusca == 1)
				{
					cout<<"Digite o numero a ser buscado na lista: ";
					cin>>numero;
					cout<<endl<<"Buscando . . ."<<endl;
					indice = buscarValor_iterativa(&lista, numero);
				}
				else
				{
					cout<<"Digite o numero a ser buscado na lista: ";
					cin>>numero;
					cout<<endl<<"Buscando . . ."<<endl;
					indice = buscarValor_recursiva(&lista, lista.inicio, numero);
				}
				if(indice == -1)
						cout<<endl<<"[!] O número não está na lista"<<endl;
					else
						cout<<endl<<"[*] O número "<< numero <<" foi encontrado na posição: "<< indice <<endl;
			break;
			
			case 5:
				cout<<endl<<"Esvaziando a lista ...";
				esvaziar(&lista);
			break;
			
			case 6:
				if(eVazia(&lista))
				{
					cout<<endl<<"A lista está vazia, não há o que verificar"<<endl<<"Preencha a lista primeiro"<<endl;
					break;
				}
				cout<<endl<<"Digite 1 para verificar a lista de forma iterativa ou "<<endl<<"\tdigite 0 para verificar a lista de forma recursiva"<<endl;
				cin>>opcaoVerificar;
				
				if(opcaoVerificar == 1)
					eCrescente = verificarOrdem_crescente_iterativa(&lista);
				else
					eCrescente = verificarOrdem_crescente_recursiva(lista.inicio);
					
				cout<<endl<<"Verificando . . ."<<endl;
				
				if(eCrescente == false)
					cout<<endl<<"[!] A lista está uma bagunça ou vazia"<<endl;
				else
					cout<<endl<<"[*] Esta lista está em ordem crescente"<<endl;
				
			break;
			default:
				cout<<"Saindo ...";
				
		}
	}while(escolha != 7);
}
