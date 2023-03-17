#include<iostream>

/*
	------------------Exercicio de Avaliação-----------------------
	
	Exercicios Propostos 1 - cap.8 - pág.298 - Livro Fundamentos da programação de computadores
	____________________________________________________________________________________________________
	Faça uma sub-rotina (função) que receba um número inteiro e positivo N como parametro e retorne
	a soma dos numeros inteiros existentes entre o numero 1 e N (inclusive).
*/
using namespace std;

int soma(int N){
	int i, total;
	
		for(i = 1; i <= N; i++){
			total += i;
		}
		return total;
}


int main(){
	int numero;
	
	do{
		cout<<"Digite um numero inteiro positivo: "<<endl;
		cin>> numero;
		
		if(numero < 0)
			cout<<"Numero invalido, digite somente numeros positivos."<<endl;
		else
			cout<<"A soma dos numeros inteiros entre 1 eh " << numero << " eh: " << soma(numero)<<endl;
	}while(numero < 0);
	
	
}
