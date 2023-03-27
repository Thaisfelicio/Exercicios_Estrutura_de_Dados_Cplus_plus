/*
	Exercicio 3 - Lista de ordenação
	_____________________________________________________________________________________
	3. Faça um programa que cadastre 8 alunos. Para cada aluno devem ser cadastrados:    
	nome, nota1 e nota2. Primeiro, liste todos os alunos cadastrados, ordenando-os pela 
	média ponderada das notas, tendo a primeira nota peso 2 e a segunda, peso 3. Em 
	seguida, ordene os alunos, de forma crescente, pela nota1, e liste-os. Finalmente, 
	considerando que, para ser aprovado, o aluno deve ter no mínimo média 7, liste, em 
	ordem alfabética, os alunos reprovados. Em cada ordenação use um algoritmo 
	diferente.
*/

#include<iostream>
#include<string>
//#include<limits>

using namespace std;

const int TAMANHO = 3;

struct Aluno;

void cabecalho();

void entrada_de_dados(struct Aluno *student);

//menu com as opcoes de listagem
int menu();

void calcular_mediaPonderada(struct Aluno *student);

//ordenar pela media podenrada de forma crescente
void intercala_do_merge(struct Aluno *student, int inicio, int fim, int meio);
void ordenar_mergeSort_mediaPonderada(struct Aluno *student, int inicio, int fim);

//ordena os alunos pela nota1 de forma crescente
void ordenar_inserctionSort_crescente(struct Aluno *student);

//ordena os alunos reprovados com media menor que 7 em ordem alfabetica
void ordenarReprovados_bubbleSort_v2_alfabetica(struct Aluno *student);

void imprime_dados(struct Aluno *student);

struct Aluno{
	string nome;
	float nota1;
	float nota2;
	
	float mediaPonderada;
};

//----------------------------------------------------------------
int main(){
	int opcao, i;
	struct Aluno cadastrar_aluno[TAMANHO];
	/*
		1 - ordenar primeiro por ordem de media e listar
		2 - ordenar de forma crescente pela nota1 e listar
		3 - ordenar em ordem alfabetica os alunos reprovados e listar
	*/
	cabecalho();
	entrada_de_dados(cadastrar_aluno);
	opcao = menu();
	do
	{
		switch(opcao)
		{
			case 1:
				cout<<"Ordenados por media ponderada"<<endl;
				ordenar_mergeSort_mediaPonderada(cadastrar_aluno, 0, TAMANHO);
				
				cout<<"ALUNO \t MEDIA PONDERADA"<<endl;
				for(i = 0; i <= TAMANHO-1; i++)
				{
					cout<< cadastrar_aluno[i].nome <<"\t\t";
					cout<< cadastrar_aluno[i].mediaPonderada <<endl;
					cout<<"---------------------------------------------------------------------------------------------- \t\t"<<endl;
				}
//				imprime_dados(cadastrar_aluno);
				break;
			case 2:
				cout<<"Ordenando alunos pela sua primeira nota"<<endl;
				ordenar_inserctionSort_crescente(cadastrar_aluno);
				imprime_dados(cadastrar_aluno);
				break;
			case 3:
				cout<<"Reprovados por ordem alfabetica"<<endl;
				ordenarReprovados_bubbleSort_v2_alfabetica(cadastrar_aluno);
				break;
			default:
				cout<<"Saindo ...";
		}
		}while(opcao < 0 || opcao > 3);
	
}
//----------------------------------------------------------------

void entrada_de_dados(struct Aluno *student){
	int i;
	struct Aluno *ponteiro_auxiliar = student;
	
	for(i = 0; i <= TAMANHO-1; i++)
	{
		cout<<"Digite o nome do "<< i+1 <<" aluno(a): ";
		getline(cin, ponteiro_auxiliar[i].nome);
		
		cout<<endl;
		
		cout<<"Digite a primeira nota do aluno(a): ";
		cin>>ponteiro_auxiliar[i].nota1;
		
		cout<<endl;
		
		cout<<"Digite a segunda nota do aluno(a): "; 
		cin>>ponteiro_auxiliar[i].nota2;

		calcular_mediaPonderada(student);
		
		cin.ignore();//descarta o caractere '\n' deixado pelo cin no getline
		cout<<"----------------------------------------------"<<endl;
	}
}

void cabecalho(){
	cout<<"*****************************************************"<<endl;
	cout<<"**       Ordenador de notas - Passou ou nao        **"<<endl;
	cout<<"*****************************************************"<<endl;
}

int menu(){
	int escolha;
	
	do
	{
		cout<<"MENU DE OPCOES"<<endl<<endl;
		cout<<"(1)- Digite 1 para ordenar por ordem de media ponderada e listar"<<endl;
		cout<<"(2)- Digite 2 para ordenar por ordem crescente da nota 1 e listar"<<endl;
		cout<<"(3)- Digite 3 para ordenar os alunos reprovados por ordem alfabetica e listar"<<endl;
		cout<<"(0)- Sair"<<endl;
		
		cout<<"Digite a sua escolha:";
		cin>>escolha;
		if(escolha < 0 || escolha > 3)
			cout<<"Opcao invalida"<<endl;
	}while(escolha < 0 || escolha > 3);
	
	return escolha;
}

void intercala_do_merge(struct Aluno *student, int inicio, int fim, int meio){
	int posicao_livre, inicio_vetor1, inicio_vetor2, i;	
	struct Aluno *ponteiro_auxiliar = student;
	struct Aluno vetor_auxiliar[TAMANHO];
	
	inicio_vetor1 = inicio;
    inicio_vetor2 = meio + 1;
    posicao_livre = inicio;
    
    while (inicio_vetor1 <= meio && inicio_vetor2 <= fim)
    {
        if(ponteiro_auxiliar[inicio_vetor1].mediaPonderada <= ponteiro_auxiliar[inicio_vetor2].mediaPonderada)
        {
            vetor_auxiliar[posicao_livre].nome = ponteiro_auxiliar[inicio_vetor1].nome;
            vetor_auxiliar[posicao_livre].nota1 = ponteiro_auxiliar[inicio_vetor1].nota1;
            vetor_auxiliar[posicao_livre].nota2 = ponteiro_auxiliar[inicio_vetor1].nota2;
            vetor_auxiliar[posicao_livre].mediaPonderada = ponteiro_auxiliar[inicio_vetor1].mediaPonderada;
            
            inicio_vetor1 = inicio_vetor1 + 1;
        }
        else
        {
            vetor_auxiliar[posicao_livre].nome = ponteiro_auxiliar[inicio_vetor2].nome;
            vetor_auxiliar[posicao_livre].nota1 = ponteiro_auxiliar[inicio_vetor2].nota1;
            vetor_auxiliar[posicao_livre].nota2 = ponteiro_auxiliar[inicio_vetor2].nota2;
            vetor_auxiliar[posicao_livre].mediaPonderada = ponteiro_auxiliar[inicio_vetor2].mediaPonderada;
            
            inicio_vetor2 = inicio_vetor2 + 1;
        }
        posicao_livre = posicao_livre + 1;
    }
    for(i = inicio_vetor1; i<= meio; i++)
    {
    	vetor_auxiliar[posicao_livre].nome = ponteiro_auxiliar[i].nome;
    	vetor_auxiliar[posicao_livre].nota1 = ponteiro_auxiliar[i].nota1;
        vetor_auxiliar[posicao_livre].nota2 = ponteiro_auxiliar[i].nota2;
        vetor_auxiliar[posicao_livre].mediaPonderada = ponteiro_auxiliar[i].mediaPonderada;
            
    	posicao_livre = posicao_livre + 1;
	}
	for(i = inicio_vetor2; i <= fim; i++)
	{
		vetor_auxiliar[posicao_livre].nome = ponteiro_auxiliar[i].nome;
    	vetor_auxiliar[posicao_livre].nota1 = ponteiro_auxiliar[i].nota1;
        vetor_auxiliar[posicao_livre].nota2 = ponteiro_auxiliar[i].nota2;
        vetor_auxiliar[posicao_livre].mediaPonderada = ponteiro_auxiliar[i].mediaPonderada;
            
    	posicao_livre = posicao_livre + 1;
	}
	for(i = inicio; i <= fim; i++)
	{
		ponteiro_auxiliar[i].nome = vetor_auxiliar[i].nome;
		ponteiro_auxiliar[i].nota1 = vetor_auxiliar[i].nota1;
		ponteiro_auxiliar[i].nota2 = vetor_auxiliar[i].nota2;
		ponteiro_auxiliar[i].mediaPonderada = vetor_auxiliar[i].mediaPonderada;
	}
}

void ordenar_mergeSort_mediaPonderada(struct Aluno *student, int inicio, int fim){
	int meio, i;
	struct Aluno *ponteiro_auxiliar = student;
	
	if(inicio < fim)
	{
		meio = (inicio + fim)/2;
        ordenar_mergeSort_mediaPonderada(ponteiro_auxiliar, inicio, meio);
        ordenar_mergeSort_mediaPonderada(ponteiro_auxiliar,meio + 1, fim);
        intercala_do_merge(ponteiro_auxiliar, inicio, fim, meio);
	}
	
}

void ordenar_inserctionSort_crescente(struct Aluno *student){
	int i, j;
	float eleito;
	struct Aluno *ponteiro_auxiliar = student;
	
	for(i = 1; i <= TAMANHO - 1; i++)
	{
		eleito = ponteiro_auxiliar[i].nota1;
		j = i - 1;
		
		while(j >= 0 && ponteiro_auxiliar[j].nota1 > eleito)
		{
			ponteiro_auxiliar[j+1].nome = ponteiro_auxiliar[j].nome;
			ponteiro_auxiliar[j+1].nota1 = ponteiro_auxiliar[j].nota1;
			ponteiro_auxiliar[j+1].nota2 = ponteiro_auxiliar[j].nota2;
			ponteiro_auxiliar[j+1].mediaPonderada = ponteiro_auxiliar[j].mediaPonderada;
			
			j -= 1;
		}
		ponteiro_auxiliar[j+1].nota1 = eleito;
	}
}

void ordenarReprovados_bubbleSort_v2_alfabetica(struct Aluno *student){
	int i, n, troca;
	string aux_nome;
	float aux_nota1, aux_nota2, aux_mediaPonderada;
	struct Aluno *ponteiro_auxiliar = student;
	struct Aluno alunosReprovados[TAMANHO];//vetor para armazenar os alunos que foram reprovados
	
	//preenchendo o vetor com os alunos que foram reprovados
	for(i=0; i<= TAMANHO-1; i++)
	{
		if(ponteiro_auxiliar[i].mediaPonderada < 7)
		{
			alunosReprovados[i].nome = ponteiro_auxiliar[i].nome;
			alunosReprovados[i].nota1 = ponteiro_auxiliar[i].nota1;
			alunosReprovados[i].nota2 = ponteiro_auxiliar[i].nota2;
			alunosReprovados[i].mediaPonderada = ponteiro_auxiliar[i].mediaPonderada;
		}	
	}
	
		//ordenando o vetor de alunos reprovados
		while(n <= TAMANHO && troca == 1)
		{
			troca = 0;
			for(i = 0; i <=6; i++)
			{
				if(alunosReprovados[i].nome < alunosReprovados[i+1].nome)
				{
					troca = 1;
					aux_nome = alunosReprovados[i].nome;
					alunosReprovados[i].nome = alunosReprovados[i+1].nome;
					alunosReprovados[i+1].nome = aux_nome;
					
					aux_nota1 = alunosReprovados[i].nota1;
					alunosReprovados[i].nota1 = alunosReprovados[i+1].nota1;
					alunosReprovados[i+1].nota1 = aux_nota1;
					
					aux_nota2 = alunosReprovados[i].nota2;
					alunosReprovados[i].nota2 = alunosReprovados[i+1].nota2;
					alunosReprovados[i+1].nota2 = aux_nota2;
					
					aux_mediaPonderada = alunosReprovados[i].mediaPonderada;
					alunosReprovados[i].mediaPonderada = alunosReprovados[i+1].mediaPonderada;
					alunosReprovados[i+1].mediaPonderada = aux_mediaPonderada;
				}
			}n += 1;	
		}
	cout<<"ALUNO \t PRIMEIRA NOTA  \t SEGUNDA NOTA \t MEDIA PONDERADA"<<endl;
		for(i = 0; i <= TAMANHO-1; i++)
		{
			cout<< alunosReprovados[i].nome <<"\t\t";
				
			cout<< alunosReprovados[i].nota1 <<"\t\t";
					
			cout<< alunosReprovados[i].nota2 <<"\t\t";
		
			cout<< alunosReprovados[i].mediaPonderada <<endl;

			cout<<"---------------------------------------------------------------------------------------------- \t\t"<<endl;
		
		}
}

void calcular_mediaPonderada(struct Aluno *student){
	
	const int peso_nota1 = 2, peso_nota2 = 3;
	int soma_pesos = peso_nota1 + peso_nota2;
	
	struct Aluno *ponteiro_auxiliar = student;
	for(int i = 0; i <=TAMANHO-1; i++)
	{
		float soma_notas_EPesos = (ponteiro_auxiliar[i].nota1 * peso_nota1) + (ponteiro_auxiliar[i].nota2 * peso_nota2);
		ponteiro_auxiliar[i].mediaPonderada = soma_notas_EPesos/soma_pesos;	
	}
}

void imprime_dados(struct Aluno *student){
	int i;
	struct Aluno *pAux = student;
	
	cout<<"ALUNO \t PRIMEIRA NOTA  \t SEGUNDA NOTA \t MEDIA PONDERADA"<<endl;
	for(i = 0; i <= TAMANHO-1; i++)
	{
		cout<< pAux[i].nome <<"\t\t";
		cout<< pAux[i].nota1 <<"\t\t";
		cout<< pAux[i].nota2 <<"\t\t";
		cout<< pAux[i].mediaPonderada <<endl;

		cout<<"---------------------------------------------------------------------------------------------- \t\t"<<endl;
	}	
}

