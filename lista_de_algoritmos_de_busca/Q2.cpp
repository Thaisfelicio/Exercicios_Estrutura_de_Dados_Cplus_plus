/*
2. Implemente um programa estruturado e recursivo para pesquisa binaria. Faça uma
funcao de busca chamada pesquisaBR que receba como parametro o valor a ser
encontrado e a referência do vetor onde a busca sera efetuada. A função retornara -1,
caso nao encontre o item, ou retornara o indice, caso o encontre.
*/

#include <iostream>

using namespace std;

const string ERRO = "\aInvalido. Digite novamente";

void cabecalho();

void preencheVetor(int* vetor, int tamanho);

void imprimeVetor(int* vetor, int tamanho);

void insertionSort(int* vetor, int tamanho);

int pesquisaBR(int* vetor, int busca, int inicio, int fim);

int main()
{
	int tamanho, *pVetor, busca, resultado;
	char continua;
	
	cabecalho();
	
	do{
		cout << "Qual o tamanho do vetor?" << endl;
		cin >> tamanho;
		if(tamanho <= 0)
			cout << ERRO << endl << endl;
	}while(tamanho <= 0);
	
	pVetor = new int(tamanho);
			
	preencheVetor(pVetor, tamanho);
	
	insertionSort(pVetor, tamanho);
	
	imprimeVetor(pVetor, tamanho);
	
	do{
		cout << "Pesquisar qual numero?" << endl;
		cin >> busca;
		
		resultado = pesquisaBR(pVetor, busca, 0, tamanho);
		
		if(resultado == -1)
			cout << "Numero nao encontrado no vetor" << endl << endl;
		else
			cout << "Numero encontrado no indice: " << resultado << endl << endl;
		
		do{
			cout << "Pesquisar outro numero? (S/N)" << endl;
			cin >> continua;
			continua = toupper(continua);
			if(continua != 'N' && continua != 'S')
				cout << ERRO << endl << endl;
		}while(continua != 'N' && continua != 'S');						
	}while(continua != 'N');
	
	cout << "Saindo ...";
		
	delete(pVetor);
		
	return 0;
}

void cabecalho()
{
	cout << "\t ++ Programa de Pesquisa Binaria ++ " << endl;
}

void preencheVetor(int* vetor, int tamanho)
{
	int i;
	
	cout << "Preenchendo vetor ..." << endl ;
	
	for(i=0; i<tamanho; i++)
	{
		cout << "[" << i << "]: ";
		cin >> vetor[i];
	}
	
	cout << "Vetor preenchido ..." << endl << endl;
}

void imprimeVetor(int* vetor, int tamanho)
{
	int i;
	
	cout << "Vetor" << endl << endl;
	
	for(i=0; i<tamanho; i++)
	{
		cout << vetor[i] << endl;
	}
}

void insertionSort(int* vetor, int tamanho)
{
	int i, j, eleito;

	for (i=1; i<tamanho; i++)
	{
		eleito = vetor[i];

		j = i - 1;
		
		while ( j >= 0 && vetor[j] > eleito)
		{
			vetor[j+1] = vetor[j];

			j = j - 1;
		}	
		vetor[j+1] = eleito;
	}
}

int pesquisaBR(int* vetor, int busca, int inicio, int fim)
{	
	int meio = (inicio+fim)/2;
	if(inicio > fim)
		return -1;
	else if(vetor[meio] == busca)
		return meio;
	else if(vetor[meio] < busca)
		return pesquisaBR(vetor, busca, meio+1, fim);
	else
		return pesquisaBR(vetor, busca, inicio, meio-1);
}
