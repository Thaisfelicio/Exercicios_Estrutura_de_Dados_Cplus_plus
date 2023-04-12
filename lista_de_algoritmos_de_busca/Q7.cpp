/*
7. Implemente uma versão generalizada para busca binária numa matriz m x n.
*/

#include <iostream>

const int MAX = 10;

using namespace std;

void preencheMatriz(int *matriz, int m, int n)
{
	int linha, coluna;
	
	for(linha=0; linha<m; linha++)
	{
		for(coluna=0; coluna<n; coluna++)
		{
			cout << "[" << linha << "][" << coluna << "]" ": ";
			//Para identificar o endereco de memoria associado a um determinado elemento M[i][j], eh feita internamente uma
			//conta de enderecamento: o endereco do elemento matriz[i][j] eh &matriz[0][0] + linha · n + coluna
			cin >> *(matriz + linha * n + coluna);
		}	
		cout << endl;
	}
}

void apresentaMatriz(int *matriz, int m, int n)
{
	int linha, coluna;
	
	for(linha=0; linha<m; linha++)
	{
		for(coluna=0; coluna<n; coluna++)
		{
			cout << "[" << linha << "][" << coluna << "]" ": ";
			cout << *(matriz + linha * n + coluna);
			cout << "\t";
		}
		cout << endl;
	}
}

void deMparaV(int *matriz, int vetor[], int m, int n)
{
	int linha, coluna, indice = 0;
	
	for(linha=0; linha<m; linha++)
	{
		for(coluna=0; coluna<n; coluna++)
		{
			vetor[indice] = *(matriz + linha * n + coluna);
			indice++;
		}
	}
}

void deVparaM(int *matriz, int vetor[], int m, int n)
{
	int linha, coluna, indice = 0;
	
	for(linha=0; linha<m; linha++)
	{
		for(coluna=0; coluna<n; coluna++)
		{
			*(matriz + linha * n + coluna) = vetor[indice];
			indice++;
		}
	}
}

void insertionSort(int vetor[], int indice)
{
	int i, j, eleito;

	for (i=1; i<indice; i++)
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

int pesquisaBR(int n[], int tamanho, int busca)
{
	int inicio, fim, meio, achou;
	
	achou = 0;
	inicio = 0;
	fim = tamanho;
	meio = (inicio+fim)/2;
	
	while(inicio < fim && achou == 0)
	{
		if(n[meio] == busca)
			achou = 1;
		else
		{
			if(busca < n[meio])
				fim = meio-1;
			else
			{
				inicio = meio+1;
				meio = (inicio+fim)/2;
			}
		}
	}
	
	if(achou == 0)
		return -1;
	else
		return meio;
}

int main()
{
	int m, n, busca, resultado, linha, coluna;
	
	cout << "Quantidade de linhas: ";
	cin >> m;
	
	cout << "Quantidade de colunas: ";
	cin >> n;
	
	int matriz[m][n];
	int vetor[m*n];
	
	preencheMatriz(&matriz[0][0], m, n);
	
	apresentaMatriz(&matriz[0][0], m, n);
	
	deMparaV(&matriz[0][0], vetor, m, n);
	
	insertionSort(vetor, m*n);
		
	deVparaM(&matriz[0][0], vetor, m, n);
	
	apresentaMatriz(&matriz[0][0], m, n);
	
	cout << "Qual numero vc procura ?" << endl;
	cin >> busca;
		
	resultado = pesquisaBR(vetor, m*n, busca);
		
	if(resultado == -1)
		cout << "Nao foi encontrado o numero na matriz";
	else
	{
		for(linha=0; linha<m; linha++)
		{
			for(coluna=0; coluna<n; coluna++)
			{
				if(matriz[linha][coluna] == busca)
					cout << "O numero " << busca << ", foi encontrado na posicao [" << linha << "][" << coluna << "]";
			}
		}
	}
}
