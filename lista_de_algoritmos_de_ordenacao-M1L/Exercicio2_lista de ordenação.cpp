#include<iostream>
/*
2. Faça um programa que cadastre 10 números, ordene-os pelo bubble sort e em 
	seguida encontre e mostre:
		a. O menor número e quantas vezes ele aparece no vetor.
		b. O maior número e quantas vezes ele aparece no vetor.
*/
using namespace std;

const int TAMANHO = 10;

void entrada_de_dados(int vetor[]){
	int i;
	
	for(i = 0; i <=9; i++)
	{
		cout<<"Digite o "<< i + 1 <<" o numero ";
		cin>> vetor[i];
	}
}

void ordenar_insertionSort(int vetor[]){
	int i, j, eleito;
	
	for(i = 1; i<= 9; i++)
	{
		eleito = vetor[i];
		j = i - 1;
		
		while(j >= 0 && vetor[j]> eleito)
		{
			vetor[j + 1] = vetor[j];
			j = j - 1;
		}
		vetor[j + 1] = eleito;
	}
}

int mostrar_numeroDeVezesQueAparece_menor(int vetor[]){
	ordenar_insertionSort(vetor);
	
	int contador = 0;
	
	for(int i = 0; i <= 9; i++)
	{
		if(vetor[0] == vetor[i])
			contador++;
	}
	return contador;
}

int mostrar_numeroDeVezesQueAparece_maior(int vetor[]){
	ordenar_insertionSort(vetor);
	
	int contador = 0;
	
	for(int i = 0; i <= 9; i++)
	{
		if(vetor[9] == vetor[i])
			contador++;
	}
	return contador;
}

void imprime_vetor(int vetor[]){
	int i;
	
	for(i = 0; i <= 9; i++)
	{
		cout<< i + 1 <<"o numero: "<< vetor[i] <<endl;
	}
}
int main(){
	int vetor_main[TAMANHO];
	
	entrada_de_dados(vetor_main);
	
	cout<<"Vetor original"<<endl;
	imprime_vetor(vetor_main);
	
	cout<<"Vetor ordenado"<<endl;
	ordenar_insertionSort(vetor_main);
	imprime_vetor(vetor_main);
	
	cout<<"O menor numero eh: " << vetor_main[0]<<" \t";
	cout<<"Vezes que ele apareceu no vetor: "<< mostrar_numeroDeVezesQueAparece_menor(vetor_main) <<endl;
		
	cout<<"O maior numero eh: "<< vetor_main[9]<<" \t";
	cout<<"Vezes que ele apareceu no vetor: "<< mostrar_numeroDeVezesQueAparece_maior(vetor_main) <<endl;
}
