/*
	------------------Exercicio de Avaliação-----------------------
	
	Exercicios Propostos 7 - cap.8 - pág.298 - Livro Fundamentos da programação de computadores
	____________________________________________________________________________________________________
	Elabore uma sub-rotina que leia um numero não determinado de valores positivos
	e retorne a média aritmética desses valores. Terminar a entrada de dados com o valor zero.
	Quando o usuario digitar 0 o programa termina, o valor 0 não é inserido no vetor.
*/
#include<iostream>
#include<vector>

using namespace std;

int calcular_mediaAritmetica(vector <int> valoresPositivos){
	int soma;
	int media;
		
	for(int i = 0; i < valoresPositivos.size(); i++){
		soma += valoresPositivos[i];
		}
	media = soma / valoresPositivos.size();
	return media;
}	

int main(){
	
	vector <int> valores;
	int valor;
	int escolha;
	
	do{
		cout<<"Digite o valor a ser adicionado: ";
		cin>> valor;
		valores.push_back(valor);
		
		if(valor < 0){
			cout<<"A media so aceita valores positivos, digite um valor positivo."<<endl<<endl;
		}
		
		cout<<"Deseja adicionar outro valor? Se sim digite 1 se nao digite 0"<<endl;
		cin>> escolha;
		
	}while(escolha == 1);
//	calcular_mediaAritmetica(valores); esta linha não é necessária ela já esta sendo chamada no cout abaixo.
	
	cout<<"O valor da media aritmetica eh: "<< calcular_mediaAritmetica(valores) <<endl;
	
	return 0;
}
