/*
8. Elabore uma matriz com 500 linhas e 50 colunas, que deverá ser preenchida com 
números inteiros aleatórios na faixa de 1 a 10.000. Faça a busca, pelo método binário, 
de um elemento sorteado, indique a quantidade de elementos iguais a este presente 
na matriz e indique a posição (ou as posições, caso aja repetição) em que ele se 
encontra (i, j)
*/

#include<iostream>
#include<cstdlib>
#include<ctime> // essa biblioteca será utilizada para usar a função
				//'time', para que utilize o relógio do sistema para
				//gerar numeros pseudoaleatórios.
using namespace std;

const int linhas = 3;
const int colunas = 4;

//máximo de 25.000 numeros em uma matriz de 500x50

int gerar_numeroAleatorio(int minimo, int maximo);
void preencher_matriz(int *matriz, int linhas, int colunas, int minimo, int maximo);
void matriz_para_array(int *matriz, int num_linhas, int num_colunas, int *array);
void array_para_matriz(int *array, int linhas, int colunas, int *matriz);
void trocar(int *array, int i, int j, int colunas);
void ordenar_array_quickSort(int *array, int esquerda, int direita, int colunas);
void imprimir_matriz(int *matriz, int linhas, int colunas);

int main(){
	const int valorMaximo_numeros = 12;
	//fazer uma funçao que adiciona numeros aleatorios[x]
	//fazer uma função para preencher a matriz[x]
	//fazer a ordenação da matriz
	//usar a função binaria para buscar um numero
	//indicar a quantidade de elementos iguais ao sorteado na matriz
	//inidcar a posiçao ou posições que esta o numero buscado, neste formato (i, j), exemplo: [3,4]
	int matriz_utilizada[linhas][colunas];
	int array[linhas * colunas];
	
	gerar_numeroAleatorio(1, valorMaximo_numeros);
	preencher_matriz(&matriz_utilizada[0][0], linhas, colunas, 1, valorMaximo_numeros);
	imprimir_matriz(&matriz_utilizada[0][0], linhas, colunas);
	 
	cout<<endl<<endl;
	matriz_para_array(&matriz_utilizada[0][0], linhas, colunas, array);
	ordenar_array_quickSort(array, 0, linhas*colunas-1, colunas);
	imprimir_matriz(&matriz_utilizada[0][0], linhas, colunas);
	
	return 0;
}
int gerar_numeroAleatorio(int minimo, int maximo){
	static bool inicializado = false;
	
	if(!inicializado)
	{
		srand(time(NULL));
		inicializado = true;	
	}	
	return rand() % (maximo - minimo) + minimo;
}

void preencher_matriz(int *matriz, int linhas, int colunas, int minimo, int maximo){
	for(int i = 0; i < linhas; i++)
		for(int j = 0; j < colunas; j++)
			matriz[i * colunas + j] = gerar_numeroAleatorio(minimo, maximo);
}

void matriz_para_array(int *matriz, int num_linhas, int num_colunas, int *array){
	int i, j, array[num_linhas*num_colunas], index = 0, tamanho;
	
	for(int i = 0; i < linhas; i++) {
	  for(int j = 0; j < colunas; j++) {
	    array[index] = matriz[i][j];
	    index++;
	  }
	}
}

void array_para_matriz(int *array, int linhas, int colunas, int *matriz){
	int i, j, matriz[linhas][colunas], index = 0;

	for(int i = 0; i < linhas; i++) {
	  for(int j = 0; j < colunas; j++) {
	    matriz[i][j] = array[index];
	    index++;
	  }
	}
}
//função auxiliar da quicksort
void trocar(int *array, int i, int j, int colunas){
    int temp = *(array + i*colunas + j);
    *(array + i*colunas + j) = *(array + i*colunas + j+1);
    *(array + i*colunas + j+1) = temp;
}
//Algoritmo de ordenação quicksort
void ordenar_array_quickSort(int *array, int esquerda, int direita, int colunas){
    int i = esquerda, j = direita;
    int pivo = array[(esquerda + direita) / 2 * colunas];

    while (i <= j) {
        while (array[i*colunas + j] > pivo)
            i++;
        while (array[j*colunas + i] < pivo)
            j--;
        if (i <= j) {
            trocar(array, i, j, colunas);
            i++;
            j--;
        }
    }

    if (esquerda < j)
        ordenar_array_quickSort(array, esquerda, j, colunas);
    if (i < direita)
        ordenar_array_quickSort(array, i, direita, colunas);
}

void imprimir_matriz(int *matriz, int linhas, int colunas){
	int i, j;
	
	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
			cout<< matriz[i * colunas + j] <<" ";
		cout<<endl;
	}
}
