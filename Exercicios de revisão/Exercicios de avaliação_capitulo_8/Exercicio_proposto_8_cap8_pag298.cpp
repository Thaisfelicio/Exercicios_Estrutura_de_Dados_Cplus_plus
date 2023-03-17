/*
	------------------Exercicio de Avalia��o-----------------------
	
	Exercicios Propostos 8 - cap.8 - p�g.298 - Livro Fundamentos da programa��o de computadores
	____________________________________________________________________________________________________
	Fa�a uma sub-rotina que receba um valor inteiro e positivo, calcule e mostre seu fatorial.
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
		cout<<"Digite um n�mero positivo: ";
		cin>>numero;
	
		if(numero <= 0)
			cout<<"Este numero � negativo, digite um n�mero positivo!"<<endl;
		else
			cout<<"O fatorial de "<< numero <<"! � "<< calcular_fatorial(numero)<<endl;
	}while(numero < 0);
	
	return 0;
}
