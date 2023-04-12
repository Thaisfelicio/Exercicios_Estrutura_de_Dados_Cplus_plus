/*
2. Implemente um programa estruturado e recursivo para pesquisa binária. Faça uma
função de busca chamada pesquisaBR que receba como parâmetro o valor a ser
encontrado e a referência do vetor onde a busca será efetuada. A função retornará -1,
caso não encontre o item, ou retornará o índice, caso o encontre.
*/

#include <iostream>
#include <vector>

using namespace std;

void preencheVector(vector <int> &n, int tamanho)
{
	int i, num;
	
	for(i=0; i<tamanho; i++)
	{
		cout << 1+i << ": ";
		cin >> num;		
		n.push_back(num);
		cout << endl;
	}
}

void apresentaVector(vector <int> &n)
{
	int i;
	
	for(i=0; i<n.size(); i++)
	{
		cout << n[i] << endl;
	}
}

int menu()
{
	int escolha;
	
	do{
		cout << "1 - Preencher vetor" << endl;
		cout << "2 - Ordenar numeros" << endl;
		cout << "3 - Pesquisar" << endl;
		cout << "0 - sair." << endl << endl;
		
		cout << "Digite sua escolha: ";
		cin >> escolha;
		if(escolha < 0 || escolha > 3)
			cout <<"\tValor invalido!" << endl << endl;
	}while(escolha < 0 || escolha > 3);
	
	return escolha;
}

void insertionSort(vector <int> &n)
{
	int i, j, eleito;

	for (i=1; i<n.size(); i++)
	{
		eleito = n[i];

		j = i - 1;
		
		while ( j >= 0 && n[j] > eleito)
		{
			n[j+1] = n[j];

			j = j - 1;
		}
		
		n[j+1] = eleito;
	}
}

int pesquisaBR(vector <int> &n, int busca)
{
	int inicio, fim, meio, achou;
	
	achou = 0;
	inicio = 0;
	fim = n.size();
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
	vector <int> num;
	int qtd, opcao, preenchido = 0, ordenado = 0, busca = 0, resultado;	
	
	do{
		opcao = menu();
		
		switch(opcao)
		{
			case 1:
				system("cls");
				do{
					cout << "Quantidade de posicoes para preencher: ";
					cin >> qtd;
				}while(qtd <= 0);
				
				preencheVector(num, qtd);
				preenchido = 1;
			break;
			
			case 2:
				system("cls");
				if(preenchido == 1)
				{
					cout << "Ordenando usando Insertion Sort..." << endl << endl;
					insertionSort(num);
					ordenado = 1;
					cout << endl << "Vetor ordenado" << endl;
				}
				else
					cout << "Primeiro preencha o vetor" << endl;
			break;
			
			case 3:
				system("cls");
				if(ordenado == 1)
				{
					cout << "Qual numero procurar? " << endl;
					cin >> busca;
					
					resultado = pesquisaBR(num, busca);
					if(resultado == -1)
						cout << "Numero nao encontrado no vetor" << endl << endl;
					else
						cout << "Numero encontrado no indice: " << resultado+1 << endl;
				}
				else
					cout << "Primeiro preencha/ordene o vetor" << endl;
			break;
			
			default:
				cout << "Saindo..." << endl;
		}
	}while(opcao != '0');
	
	return 0;
}
