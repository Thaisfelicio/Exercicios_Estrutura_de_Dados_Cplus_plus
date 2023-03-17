/*
	------------------Exercicio de Avaliação-----------------------
	
	Exercicios Propostos 8 - cap.8 - pág.298 - Livro Fundamentos da programação de computadores
	____________________________________________________________________________________________________
	Faça uma sub-rotina que receba um valor inteiro e positivo, calcule e mostre seu fatorial.
*/
#include<iostream>
#include<locale.h>

using namespace std;

int calcular_fatorial(int numeroPositivo){
	int total;
	
	for(int i = 1; i < numeroPositivo; i++){
		total += numeroPositivo*i;
	}
	return total;
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int numero;
	do{
		cout<<"Digite um número positivo: ";
		cin>>numero;
	
		if(numero <= 0)
			cout<<"Este numero é negativo, digite um número positivo!"<<endl;
		else
			cout<<"O fatorial de "<< numero <<"! é "<< calcular_fatorial(numero)<<endl;
	}while(numero < 0);
	
	return 0;
}
