/*
	------------------Exercicio de Avalia��o-----------------------
	
	Exercicios Propostos 5 - cap.8 - p�g.298 - Livro Fundamentos da programa��o de computadores
	____________________________________________________________________________________________________
	Fa�a uma sub-rotina que receba um valor inteiro e verifique se ele � positivo ou negativo.
*/
#include<iostream>

using namespace std;

void verifique_inteiroPositivoOuNegativo(int numero){
	if(numero < 0){
		cout<<"Este numero inteiro eh negativo!"<<endl;
	}
	else{
		cout<<"Este numero inteiro eh positivo!"<<endl;
	}
}

int main(){
	int numeroTeste;
	cout<<"****************************************************"<<endl;
	cout<<"* Eh positivo ou negativo?                         *"<<endl<<"* Descubra agora!                                  *"<<endl;
	cout<<"****************************************************"<<endl<<endl;
	
	cout<<"Digite um numero: ";
	cin>>numeroTeste;
	verifique_inteiroPositivoOuNegativo(numeroTeste);
	
}
