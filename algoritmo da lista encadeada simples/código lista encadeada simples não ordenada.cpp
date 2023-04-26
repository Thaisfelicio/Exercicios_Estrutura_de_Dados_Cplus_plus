//implementação do exemplo de lista simples não ordenada

#include<iostream>

using namespace std;

typedef struct Noh{//typedef é pra definir um tipo de dado, no caso do tipo noh, como um int ou float
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
		cout<< "4 - Remover da lista" <<endl;
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

void remover(Lista *list, int valor){
	if(!eVazia(list))
	{
		Noh *pAux = list->inicio;
		Noh *pApagar = NULL;
		
		if(pAux != NULL && list->inicio->numero == valor)
		{//remover primeiro elemento
			pApagar = list->inicio;
			list->inicio = pApagar->proximo;
			if(list->inicio == NULL)
				list->fim = NULL;
		}	
		else
		{//remoção no meio ou no final
			while(pAux !=NULL && pAux->proximo != NULL && pAux->proximo->numero != valor)
				pAux = pAux->proximo;
				
			if(pAux != NULL && pAux->proximo !=NULL)
			{
				pApagar = pAux->proximo;
				pAux->proximo = pApagar->proximo;
				if(pAux->proximo == NULL)//se o último for removido
					list->fim = pAux;
			}
		}
		if(pApagar)
		{
			delete(pApagar);
			list->tamanho--;
		}
	}
	else
	{
		cout<<endl<<"Lista vazia ..."<<endl<<endl;
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

int main(){
	Lista lista;
	
	//inicialização da lista: (zerada para uso)
	lista.inicio = NULL;
	lista.fim = NULL;
	lista.tamanho = 0;
	
	int escolha, numero;
	
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
				cout<<"Digite o numero a ser removido da lista: ";
				cin>>numero;
				remover(&lista, numero);
			break;
			
			case 5:
				cout<<"Esvaziando a lista ...";
				esvaziar(&lista);
			break;
			
			default:
				cout<<"Saindo ...";
				
		}
	}while(escolha != 6);
}
