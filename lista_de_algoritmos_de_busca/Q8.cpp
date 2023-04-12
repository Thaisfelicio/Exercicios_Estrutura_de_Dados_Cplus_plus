/*
8. Elabore uma matriz com 500 linhas e 50 colunas, que deverá ser preenchida 
com números inteiros aleatórios na faixa de 1 a 10.000. Faça a busca, pelo 
método binário, de um elemento sorteado, indique a quantidade de elementos 
iguais a este presente na matriz e indique a posição (ou as posicoes, caso 
aja repetição) em que ele se encontra (i, j).
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int LINHA = 2;
const int COLUNA = 2;
const int TAM = 5;

void preencheMatriz(int *matriz)
{
	int linha, coluna;
	
	srand(time(NULL));

	
	for(linha=0; linha<LINHA; linha++)
	{
		for(coluna=0; coluna<COLUNA; coluna++)
		{
			//Para identificar o endereco de memoria associado a um determinado elemento M[i][j], eh feita internamente uma
			//conta de enderecamento: o endereco do elemento matriz[i][j] eh &matriz[0][0] + linha · n + coluna
			*(matriz + linha * COLUNA + coluna) = 1+rand()%TAM;
		}	
		cout << endl;
	}
}

void apresentaMatriz(int *matriz)
{
	int linha, coluna;
	
	for(linha=0; linha<LINHA; linha++)
	{
		for(coluna=0; coluna<COLUNA; coluna++)
		{
			//cout << "[" << linha << "][" << coluna << "]" ": ";
			cout << *(matriz + linha * COLUNA + coluna);
			cout << "\t";
		}
		cout << endl;
	}
}

void deMparaV(int *matriz, int vetor[])
{
	int linha, coluna, indice = 0;
	
	for(linha=0; linha<LINHA; linha++)
	{
		for(coluna=0; coluna<COLUNA; coluna++)
		{
			vetor[indice] = *(matriz + linha * COLUNA + coluna);
			indice++;
		}
	}
}

void deVparaM(int *matriz, int vetor[])
{
	int linha, coluna, indice = 0;
	
	for(linha=0; linha<LINHA; linha++)
	{
		for(coluna=0; coluna<COLUNA; coluna++)
		{
			*(matriz + linha * COLUNA + coluna) = vetor[indice];
			indice++;
		}
	}
}

void troca (int vetor[], int i, int j)
{
	int auxVetor;
    
	auxVetor = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = auxVetor;
}

int particao (int vetor[], int p, int r)
{
	int pivo, i, j;
	pivo = vetor[(p+r)/2];
	i = p-1;
	j = r+1;
	
	while (i < j)
	{
		do
		{
			j = j -1;
		}while (vetor[j] > pivo);
		
		do
		{
			i = i + 1;
		}while (vetor[i] < pivo);
		
		if (i < j)
			troca (vetor, i, j);
	}
	return j;
}

void quickSort(int vetor[], int p, int r)
{
	
	int q;
	
	if(p < r)
	{
		q = particao(vetor, p, r);
		quickSort(vetor, p, q);
		quickSort(vetor, q+1, r);
	}
}

int pesquisaBR(int vetor[], int tamanho, int busca)
{
	int inicio = 0;
    int fim = tamanho-1;

    while (inicio <= fim) {  /* Condição de parada */

        int i = (inicio + fim) / 2;  /* Calcula o meio do sub-vetor */

        if (vetor[i] == busca) {  /* Item encontrado */
            return i;
        }

        if (vetor[i] < busca) {  /* Item está no sub-vetor à direita */
            inicio = i + 1;
        } else {  /* vetor[i] > item. Item está no sub-vetor à esquerda */
            fim = i;
        }
    }
    return -1;
}

int main()
{
	int opcao, resultado, busca, linha, coluna, qtd = 0;
	
	int matriz[LINHA][COLUNA];
	
	int indice = LINHA*COLUNA;
	
	int vetor[indice];
	
	srand(time(NULL));
	
	preencheMatriz(&matriz[0][0]);
	
	deMparaV(&matriz[0][0], vetor);
	
	quickSort(vetor, 0, indice-1);
	
	deVparaM(&matriz[0][0], vetor);
	
	do{
		cout << "Procurando um numero sorteado..... " << endl;
		busca = 1+rand()%TAM;
					
		resultado = pesquisaBR(vetor, indice, busca);
						
		if(resultado == -1)
			cout << "Que pena! O numero sorteado " << busca << " nao foi encontrado na matriz" << endl << endl;
		else
			{
				cout << "\tNumero sorteado " << busca << endl;
				
				for(linha=0; linha<LINHA; linha++)
				{
					for(coluna=0; coluna<COLUNA; coluna++)
					{
						if(matriz[linha][coluna] == busca)
						{
							cout << "Encontrado na posicao [" << linha << "][" << coluna << "]" << endl << endl;		
							qtd++;
						}
					}
				}
				cout << qtd << " vezes" << endl;	
			}
		cout << "Procurar outro numero aleatorio? (0 - Sair e !0 - Continuar)" << endl;
		cin >> opcao;
		cout << endl;				
	}while(opcao != 0);
	
	apresentaMatriz(&matriz[0][0]);
	
	return 0;
}
