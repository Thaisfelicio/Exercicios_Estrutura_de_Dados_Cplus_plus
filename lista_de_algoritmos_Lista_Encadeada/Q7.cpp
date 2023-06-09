/*
7. Faça um programa que implemente uma lista encadeada de numeros inteiros com
inserção de dados pelo usuário através de um menu. Escreva uma função que
encontre o nó que contenha o menor valor e outra função que verifique se duas listas
encadeadas são iguais, ou melhor, se têm o mesmo conteúdo. Faça duas versões:
uma iterativa e uma recursiva.
*/

#include <iostream>

using namespace std;

const string INVALIDO = "\tEscolha invalida!";

typedef struct Noh{
	int numero;
	Noh *proximo;
} Noh; //Vai definir o Noh como um tipo -> So precisa digitar no main o Noh sem o struct na frente

typedef struct Lista{
	Noh *inicio, *fim;
	int tamanho;
} Lista;

int menu()
{
	int opcao;
	
	do{
		cout << endl << "MENU DE OPCOES" << endl;
		cout << "1 - Inserir Lista 1" << endl;
		cout << "2 - Inserir Lista 2" << endl;
		cout << "3 - Imprimir Listas" << endl;
		cout << "4 - Menor valor Lista 1 - Interativo" << endl;
		cout << "5 - Menor valor Lista 2 - Recursivo" << endl;
		cout << "6 - Remover Lista 1" << endl;
		cout << "7 - Remover Lista 2" << endl;
		cout << "8 - Comparar Listas - Recursivo" << endl;
		cout << "9 - Comparar Listas - Interativo" << endl;				
		cout << "10 - Esvaziar as Listas" << endl;
		cout << "11 - Sair" << endl;
		
		cout << "Digite sua escolha: ";
		cin >> opcao;
		
		if(opcao < 1 || opcao > 11)
			cout << INVALIDO << endl;
	}while(opcao < 1 || opcao > 11);
	
	return opcao;
}

bool eVazia(Lista *lst)
{
	if (lst->inicio == NULL)
		return true;
	return false;
}

void inserir(Lista *lst, int numero)
{
	Noh *novo = new Noh();
	novo->numero = numero;
	
	if(eVazia(lst))
	{
		novo->proximo = NULL;
		lst->inicio = novo;
		lst->fim = novo;
	}
	else
	{
		novo->proximo = lst->inicio; //O ponteiro do Noh proximo vai apontar para a mesma região que o ponteiro da Lista inicio
		lst->inicio = novo;
	}
	lst->tamanho++;
}

void imprime(Lista *lst)
{
	if(!eVazia(lst))
	{
		Noh *pAux = lst->inicio;
		
		while(pAux != NULL)
		{
			cout << pAux->numero << " ";
			pAux = pAux->proximo;
		}
		cout << endl << "Tamanho da Lista: " << lst->tamanho << endl <<
		endl << endl;
	}
	else
		cout << endl << "Lista vazia... " << endl << endl;
}

void remover(Lista *lst, int valor)
{
	if(!eVazia(lst))
	{
		Noh *pAux = lst->inicio;
		Noh *pApagar = NULL; //Ponteiro para o no a ser removido
		
		if(pAux != NULL && lst->inicio->numero == valor) //Remove o 1º elemento
		{
			pApagar = lst->inicio;
			lst->inicio = pApagar->proximo;
			if(lst->inicio == NULL) //Ocorre quando so existe um elemento na lista
				lst->fim = NULL;
		}
		else
		{
			while(pAux != NULL && pAux->proximo != NULL && pAux->proximo->numero != valor)
				pAux = pAux->proximo;
			
			//realocacao dos ponteiros	
			if(pAux != NULL && pAux->proximo != NULL)
			{
				pApagar = pAux->proximo;
				pAux->proximo = pApagar->proximo;
				if(pAux->proximo == NULL) //Se o ultimo elemento for removido
					lst->fim = pAux;
			}
		}
		if(pApagar)
		{
			delete(pApagar); //libera a memoria do no
			lst->tamanho--; //decrementa o tamanho da lista
		}
	}
	else
		cout << endl << "Lista vazia... " << endl << endl;
}

void esvaziar(Lista *lst)
{
	if(!eVazia(lst))
	{
		Noh *pAux;
		
		while(lst->inicio != NULL)
		{
			pAux = lst->inicio;
			lst->inicio = lst->inicio->proximo;
			delete(pAux);
		}
		lst->tamanho = 0;
	}
	else
		cout << endl << "Lista vazia... " << endl << endl;
}

void menorValorInterativo(Lista *lst)
{
	if(!eVazia(lst))
	{
		Noh *pMenor = lst->inicio;
		Noh *pAux = lst->inicio->proximo;
		
		while(pAux != NULL)
		{
			if(pAux->numero < pMenor->numero)
            	pMenor = pAux;

			pAux = pAux->proximo;
		}
		cout << "Menor valor da lista eh " << pMenor->numero << endl;		
	}
	else
		cout << endl << "Lista vazia... " << endl << endl;
}

void menorValorRecursivo(Noh *pNoh, int &menor)
{
	
    if(pNoh == NULL)
    {
        cout << endl << "Lista vazia... " << endl << endl;
        return;
    }
    
    if(pNoh->numero < menor)
        menor = pNoh->numero;
    
    if(pNoh->proximo != NULL)
        return menorValorRecursivo(pNoh->proximo, menor);
    else
        cout << "Menor valor da lista eh " << menor << endl;
}

int compararListasInterativo(Lista *lst1, Lista *lst2)
{
	if (lst1->tamanho != lst2->tamanho)
		return -1;
    
    Noh* pAux1 = lst1->inicio;
    Noh* pAux2 = lst2->inicio;
    
    while (pAux1 != NULL && pAux2 != NULL)
	{
        if (pAux1->numero != pAux2->numero)
			return -1;
			        
        pAux1 = pAux1->proximo;
        pAux2 = pAux2->proximo;
    }
    
	return 0;
}

int compararListasRecursivo(Noh* pAux1, Noh* pAux2)//minha parte
{
    if (pAux1 == NULL && pAux2 == NULL)
        return 0;//Percorreu toda a lista// as listas são iguais
    else if (pAux1->numero != pAux2->numero)
        return -1;//as listas são diferentes
    else
        return compararListasRecursivo(pAux1->proximo, pAux2->proximo);
}

int main()
{
	Lista pLista;
	Lista sLista;
	
	//inicializacao da primeira lista
	pLista.inicio = NULL;
	pLista.fim = NULL;
	pLista.tamanho = 0;
	
	//inicializacao da segunda lista
	sLista.inicio = NULL;
	sLista.fim = NULL;
	sLista.tamanho = 0;
		
	int escolha, numero, comparar, menor, procura;
	
	do{
		escolha = menu();
		
		switch(escolha)
		{
			case 1:
				cout << endl << "\tLISTA 1" << endl <<
				"Digite o numero a ser inserido: " << endl;
				cin >> numero;
				inserir(&pLista, numero);				
			break;
			case 2:
				cout << endl << "\tLISTA 2" << endl <<
				"Digite o numero a ser inserido: " << endl;
				cin >> numero;
				inserir(&sLista, numero);				
			break;
			case 3:
				cout << endl << "\tLista 1" << endl;
				imprime(&pLista);
				cout << endl << "\tLista 2" << endl;
				imprime(&sLista);
			break;
			case 4:
				cout << "Procurando menor valor Interativo... " << endl;
				menorValorInterativo(&pLista);
			break;
			case 5:
				cout << "Procurando menor valor Recursivo... " << endl;
				procura = pLista.inicio->numero;
				menorValorRecursivo(sLista.inicio, procura);
			break;
			case 6:
				cout << "Digite o numero a ser removido da Lista 1: " << endl;
				cin >> numero;
				remover(&pLista, numero);
			break;
			case 7:
				cout << "Digite o numero a ser removido da Lista 2: " << endl;
				cin >> numero;
				remover(&sLista, numero);
			break;
			case 8:
				cout << "Comparando as listas recursivo... " << endl;
				if(pLista.tamanho != sLista.tamanho)
					cout << "Listas diferentes" << endl;
				else
				{
					comparar = compararListasRecursivo(pLista.inicio, sLista.inicio);
					if(comparar == 0)
						cout << "Listas iguais" << endl;
					else
						cout << "Listas diferentes" << endl;
				}
			break;
			case 9:
				cout << "Comparando as listas interativo... " << endl;
				comparar = compararListasInterativo(&pLista, &sLista);
				if(comparar == 0)
					cout << "Listas iguais" << endl;
				else
					cout << "Listas diferentes" << endl;
			break;
			case 10:
				cout << "Esvaziando as listas... " << endl;
				esvaziar(&pLista);
				esvaziar(&sLista);
			break;
			default:
				cout << "Saindo... ";
		}
	}while(escolha != 11);
}
 
