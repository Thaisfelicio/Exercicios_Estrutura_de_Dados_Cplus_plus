/*
3. Um vetor de tamanho n, pode conter elementos do alfabeto e numerais 0 a 9.
Escreva um algoritmo que seja capaz de localizar, pelo metodo binario, um caractere fornecido pelo usuario.
Se esse caractere for uma letra, o usuario podera forneca-la para a busca no formato maiusculo ou minusculo.
*/

#include <iostream>

using namespace std;

const string ERRO1 = "Invalido. Digite novamente";
const string ERRO2 = "Primeiro preencha/ordene o vetor";

int menu()
{
	int escolha;
	
	do{
		cout << "  Menu de opcoes" << endl << endl;
		cout << "1 - Preencher vetor" << endl;
		cout << "2 - Ordenar vetor" << endl;
		cout << "3 - Pesquisar" << endl;
		cout << "4 - Apresenta vetor" << endl;
		cout << "0 - sair." << endl << endl;
		
		cout << "Digite sua escolha: ";
		cin >> escolha;
		cout << endl;
		if(escolha < 0 || escolha > 4)
			cout << ERRO1 << endl << endl;
	}while(escolha < 0 || escolha > 4);
	
	return escolha;
}

void preencheVetor(char vetor[], int tamanho)
{
	int i;
	
	for(i=0; i<tamanho; i++)
	{
		do{
			cout << i << ": ";
			cin >> vetor[i];
						 
			if(isalnum(vetor[i]) == 0)
				cout << ERRO1 << endl;
		}while(isalnum(vetor[i]) == 0);
	}
}

void apresentaVetor(char vetor[], int tamanho)
{
	int i;
	
	for(i=0; i<tamanho; i++)
	{
		cout << vetor[i] << endl;
	}
}

void troca (char vetor[], int i, int j)
{
	char auxVetor;
    
	auxVetor = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = auxVetor;
}

int particao (char vetor[], int p, int r)
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

void quickSort(char vetor[], int p, int r){
	
	int q;
	
	if(p < r)
	{
		q = particao(vetor, p, r);
		quickSort(vetor, p, q);
		quickSort(vetor, q+1, r);
	}
}

int pesquisaBR(char vetor[], int tamanho, char busca)
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
        } else {  /* vector[i] > item. Item está no sub-vetor à esquerda */
            fim = i;
        }
    }

    return -1;
}

int main()
{
	int opcao, tamanho, preenche = 0, ordene = 0, resultado;
	char busca;
	
	do{
		cout << " Qual o tamanho do vetor?" << endl;
		cin >> tamanho;
		cout << endl;
		if(tamanho <= 0)
			cout << ERRO1 << endl << endl;
	}while(tamanho <= 0);
				
	char vetor[tamanho];
	
	do{
		opcao = menu();
		
		switch(opcao)
		{
			case 1:
				system("cls");
				
				preencheVetor(vetor, tamanho);
								
				preenche = 1;
				ordene = 0;
			break;
			
			case 2:
			    if(preenche == 1)
			    {
			     	quickSort(vetor, 0, tamanho-1);
			     	cout << "Vetor Ordenado";
			     	ordene = 1;
			    }
			    else
			        cout << ERRO2 << endl;
			break;
				
			case 3:	
				if(preenche == 1 && ordene == 1)
				{	
					cout << "Qual caractere vc procura ?" << endl;
					cin >> busca;
						
					resultado = pesquisaBR(vetor, tamanho, busca);
						
					if(resultado == -1)
						cout << "Nao foi encontrado o caractere no vetor";
					else
					{
						cout << "O numero " << busca << ", foi encontrado na posicao [" << resultado << "]" << endl << endl;
												
					}
				}
				else
					cout << ERRO2 << endl << endl;				
			break;
			
			case 4:
				if(preenche == 1)
					apresentaVetor(vetor, tamanho);
				else
					cout << ERRO2 << endl;
			break;
			
			default:
				cout << "Saindo....." << endl;
		}
	}while(opcao != 0);
	
	return 0;
}
