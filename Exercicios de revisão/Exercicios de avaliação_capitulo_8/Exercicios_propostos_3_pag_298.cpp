/*
	------------------Exercicio de Avaliação-----------------------
	
	Exercicios Propostos 3 - cap.8 - pág.298 - Livro Fundamentos da programação de computadores
	____________________________________________________________________________________________________
	Elabore uma sub-rotina que receba dois numeros como parametros e retorne 0, se o primeiro numero for 
	divisivel pelo segundo numero. Caso contrario, deverá retornar o próximo divisor.
*/
#include <iostream>

using namespace std;

int divisivel(int numero1, int numero2){
	int resultado;
	resultado = numero1 % numero2;
	if(resultado == 0){
		return 0;
	}
	else{
		resultado = ((numero1 / numero2) + 1) * numero2;
		return resultado;
	}
}

int main(){
	int firstNumber, secondNumber;
	
	cout<<"Digite o primeiro numero para divisao: ";
	cin>> firstNumber;
	cout<<endl;
	cout<<"Digite o segundo numero: ";
	cin>>secondNumber;
	
	if(divisivel(firstNumber, secondNumber) == 0){
		cout<<"O numero "<< firstNumber <<" eh divisivel por "<< secondNumber<<endl;
	}
	else{
		cout<<"O proximo numero divisivel por "<< firstNumber <<" eh o " << divisivel(firstNumber, secondNumber) <<endl;
	}
}
