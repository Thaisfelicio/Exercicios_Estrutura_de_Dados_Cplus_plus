/*
	3. Faça um programa que cadastre 5 alunos. Para cada aluno devem ser cadastrados 
nome e nota final. Os dados devem ser armazenados em uma lista duplamente 
encadeada e não ordenada. Em seguida, o programa deve mostrar apenas o nome 
dos alunos aprovados, ou seja, alunos com nota final de no mínimo 7. Se nenhum 
aluno estiver aprovado, mostrar mensagem.
*/

#include<iostream>

using namespace std;

const int MAXIMO_ALUNOS_CADASTRADOS = 3;
const string ERRO1 = "Lista vazia";
const string ERRO2 = "Nao ha alunos aprovados";

typedef struct Aluno{
	string nome;
	float notaFinal;
	Aluno *proximo;
	Aluno *anterior;
}Aluno;

typedef struct Lista{
	Aluno *inicio, *fim;
	int tamanho;
}Lista;

int menu(){
	int opcao;
	
	do
	{
		cout<<endl << "MENU DE OPCOES" <<endl;	
		cout<< "1 - Inserir no inicio da lista" <<endl;
		cout<< "2 - Inserir no fim da lista" <<endl;
		cout<< "3 - Imprimir a lista do inicio ao fim" <<endl;
		cout<< "4 - Imprimir a lista do fim ao inicio" <<endl;
		cout<< "5 - Mostrar o nome dos alunos aprovados" <<endl;
		cout<< "6 - Esvaziar lista" <<endl;
		cout<< "7 - Sair" <<endl;
		
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

void inserirInicio(Lista *list, string nome_aluno, float notaFinal_aluno){
	Aluno *novo = new Aluno();
	novo->nome = nome_aluno;
	novo->notaFinal = notaFinal_aluno;
	
	if(eVazia(list))
	{
		novo->proximo = NULL;
		novo->anterior = NULL;
		list->inicio = novo;
		list->fim = novo;
	}
	else
	{
		novo->proximo = list->inicio;
		novo->anterior = NULL;
		list->inicio->anterior = novo;
		list->inicio = novo;
	}
	list->tamanho++;
}

void inserirFim(Lista *list, string nome_aluno, float notaFinal_aluno){
	Aluno *novo = new Aluno();
	novo->nome = nome_aluno;
	novo->notaFinal = notaFinal_aluno;
	
	if(eVazia(list))
	{
		list->inicio = novo;
		list->fim = novo;
		novo->proximo = NULL;
		novo->anterior = NULL;
	}
	else
	{
		list->fim->proximo = novo;
		novo->anterior = list->fim;
		novo->proximo = NULL;
		list->fim = novo;
	}
	list->tamanho++;
}

void imprimeInicio_aoFim(Lista *list){
	if(!eVazia(list))
	{
		Aluno *pAux = list->inicio;
		
		cout<<"Nome do aluno  |  Nota Final "<<endl;
		while(pAux != NULL)
		{
			cout<< pAux->nome<< " ";
			cout<<"\t\t\t"<<pAux->notaFinal<<endl;
			pAux = pAux->proximo;
		}
		cout<< endl <<"Tamanho da lista: "<< list->tamanho << endl;
		cout<<endl<<endl; 
	}
	else
		cout<< ERRO1 <<endl<<endl;
}

void imprimeFim_aoInicio(Lista *list){
	if(!eVazia(list))
	{
		Aluno *pAux = list->fim;
		
		cout<<"Nome do aluno  |  Nota Final "<<endl;
		while(pAux != NULL)
		{
			cout<< pAux->nome<< " ";
			cout<<"\t\t\t"<<pAux->notaFinal<<endl;
			pAux = pAux->anterior;
		}
		cout<< endl <<"Tamanho da lista: "<< list->tamanho << endl;
		cout<<endl<<endl; 
	}
	else
		cout<< ERRO1 <<endl<<endl;
}

void esvaziar(Lista *list){
	if(!eVazia(list))
	{
		Aluno *pAux;
		
		while(list->inicio != NULL)
		{
			pAux = list->inicio;
			list->inicio = list->inicio->proximo;
			delete(pAux);
			
			list->tamanho--;
		}
		
	}
	else
		cout<< endl << ERRO1 << endl << endl;
}

void alunos_aprovados(Lista * list){
	Aluno *pAux = list->inicio;
	
	if(eVazia(list))
		cout<< ERRO1 <<endl;
		
	
		
	while(pAux != NULL)
	{
		if(pAux->notaFinal >= 7)
			cout<< pAux->nome<<endl;
			
		else if(pAux->proximo == NULL)
		cout<< ERRO2 <<endl;	
		
		pAux = pAux->proximo;
	}
}

int main(){
	Lista lista;
	
	lista.inicio = NULL;
	lista.fim = NULL;
	lista.tamanho = 0;
	
	int escolha, i = 1;
	string nomeAluno;
	float nota_finalAluno;
	
	do
	{
		escolha = menu();
		
		switch(escolha){
			case 1:
				i = 1;
				while(i <= MAXIMO_ALUNOS_CADASTRADOS)
				{
					cout<<"Digite o nome do aluno a ser inserido no inicio na lista: ";
					cin>> nomeAluno;
					
					do
					{
						cout<<"Digite a nota final do aluno: ";
						cin>> nota_finalAluno;
						
						if(nota_finalAluno < 0 || nota_finalAluno > 10)
							cout<<endl<<"Nota invalida! Digite um numero de 0 a 10."<<endl<<endl;
					}while(nota_finalAluno < 0 || nota_finalAluno > 10);
									
					inserirInicio(&lista, nomeAluno, nota_finalAluno);
					i++;
				}
				
			break;
			
			case 2:
				i = 1;
				while(i <= MAXIMO_ALUNOS_CADASTRADOS)
				{
					cout<<"Digite o nome do aluno a ser inserido no fim na lista: ";
					cin>>nomeAluno;
					
					do
					{
						cout<<"Digite a nota final do aluno: ";
						cin>> nota_finalAluno;
						
						if(nota_finalAluno < 0 || nota_finalAluno > 10)
							cout<<endl<<"Nota invalida! Digite um numero de 0 a 10."<<endl<<endl;
					}while(nota_finalAluno < 0 || nota_finalAluno > 10);
					
					inserirFim(&lista, nomeAluno, nota_finalAluno);
					i++;
				}
				
			break;
			
			case 3:
				cout<<"Imprimindo a lista do comeco ao fim ..."<<endl;
				imprimeInicio_aoFim(&lista);
			break;
			
			case 4:
				cout<<"Imprimindo a lista do fim ao comeco ..."<<endl;
				imprimeFim_aoInicio(&lista);
				break;
			
			case 5:
				cout<<"Alunos aprovados"<<endl;
				alunos_aprovados(&lista);
				break;
				
			case 6:
				cout<<"Esvaziando a lista ...";
				esvaziar(&lista);
			break;
			
			default:
				cout<<"Saindo ...";
				
		}
	}while(escolha != 7);
}
