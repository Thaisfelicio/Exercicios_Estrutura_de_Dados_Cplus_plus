/*
	8. Fa�a um programa que implemente uma lista encadeada de n�meros inteiros com 
inser��o de dados pelo usu�rio atrav�s de um menu. Escreva uma fun��o que fa�a 
uma c�pia da lista e outra fun��o que concatene duas listas encadeadas (isto �, 
engate a segunda no fim da primeira). Fa�a duas vers�es da fun��o: uma iterativa e 
uma recursiva.
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

int menu();
bool eVazia(Lista *list);
void imprime(Lista *list);
void inserir(Lista *list, int numero);
Lista* copiaLista(Lista *list);
void concatenarListas_iterativa();
void concatenarListas_recursiva();


int main(){
	/*
		Fazer uma fun��o que fa�a uma c�pia da lista
		fazer uma fun��o que concatene duas listas encadeadas(iterativa e recursiva)
	*/
	
	Lista lista;
	
	//inicializa��o da lista: (zerada para uso)
	lista.inicio = NULL;
	lista.fim = NULL;
	lista.tamanho = 0;
	
	int escolha, numero;
	
	do
	{
		escolha = menu();
		
		switch(escolha){
			case 1:
				cout<<"Digite o numero a ser inserido na lista: ";
				cin>> numero;
				inserir(&lista, numero);
			break;
			
			case 2:
				cout<<"Imprimindo a lista ...";
				imprime(&lista);
				imprime(copiaLista(&lista));
			break;
			
			case 3:
				cout<<"Digite o numero a ser removido da lista: ";
				cin>>numero;
//				remover(&lista, numero);
			break;
			
			case 4:
				cout<<"Esvaziando a lista ...";
//				esvaziar(&lista);
			break;
			
			default:
				cout<<"Saindo ...";
				
		}
	}while(escolha != 5);
}
Lista* copiaLista(Lista *list){
	Noh *novo = NULL;
	Noh *pAux = NULL;
	
	if(!eVazia(list))
	{
		novo = new Noh();
		novo->numero = list->inicio->numero;
		novo->proximo = NULL;
		
		pAux = novo;
		Noh *atual = list->inicio->proximo;
		
		while(atual != NULL)
		{
			Noh *novoNode = new Noh();//cria um novo n� para a nova lista
			novoNode->numero = atual->numero;
			novoNode->proximo = NULL;
			
			pAux->proximo = novoNode;
			pAux = novoNode;
			
			atual = atual->proximo;
		}
	}
	return list;
}

int menu(){
	int opcao;
	
	do
	{
		cout<<endl << "MENU DE OPCOES" <<endl;	
		cout<< "1 - Inserir na lista" <<endl;
		cout<< "2 - Imprimir toda a lista" <<endl;
		cout<< "3 - Remover da lista" <<endl;
		cout<< "4 - Esvaziar lista" <<endl;
		cout<< "5 - Sair" <<endl;
		
		cout<<"Digite sua escolha: ";
		cin>>opcao;
		
		if(opcao < 1 || opcao > 5)
			cout<<"\tEscolha invalida!"<<endl;
	}while(opcao < 1 || opcao > 5);
	
	return opcao;
}

bool eVazia(Lista *list)
{
	if(list->inicio == NULL)
		return true;
	return false;
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

void inserir(Lista *list, int numero){
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
		Noh *pAnterior = NULL;
		Noh *pAux = list->inicio;
		
		while(pAux != NULL && novo->numero < pAux->numero)//ordenando em ordem decrescente
		{
			pAnterior = pAux;
			pAux = pAux->proximo;
		}
		
		if(pAnterior == NULL)
		{
			novo->proximo = list->inicio;
			list->inicio = novo;
		}
		else if(pAux == NULL)
		{
			list->fim->proximo = novo;
			list->fim = novo;
		}
		else
		{
			pAnterior->proximo = novo;
			novo->proximo = pAux;
		}
	}
	list->tamanho++;
}


