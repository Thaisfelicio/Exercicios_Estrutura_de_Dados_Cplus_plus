/*
	------------------Exercicio de Avaliação-----------------------
	
	Exercicios Propostos 4 - cap.8 - pág.298 - Livro Fundamentos da programação de computadores
	____________________________________________________________________________________________________
	faça uma sub-rotina que receba como parametro o raio de esfera, calcule e mostre no programa principal
	o seu volume: v= 4*pi*R³/3.
*/
#include<iostream>

using namespace std;

float calcule_raioDeEsfera(float raio){
	float pi = 3.14;
	return 4 * pi * (raio*raio*raio)/3;
}

int main(){
	float raioEsfera;
	cout<<"**********************************"<<endl;
	cout<<"*Calculadora de volume de esfera *"<<endl;
	cout<<"**********************************"<<endl<<endl;
	
	cout<<"Digite o valor do raio da esfera: ";
	cin>> raioEsfera;
	
	cout<<"O volume da esfera eh: " << calcule_raioDeEsfera(raioEsfera) <<endl;
}
