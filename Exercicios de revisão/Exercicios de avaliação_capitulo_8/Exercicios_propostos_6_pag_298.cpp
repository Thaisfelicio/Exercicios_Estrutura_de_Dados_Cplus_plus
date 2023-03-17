/*
	------------------Exercicio de Avaliação-----------------------
	
	Exercicios Propostos 6 - cap.8 - pág.298 - Livro Fundamentos da programação de computadores
	____________________________________________________________________________________________________
	Crie uma sub-rotina que receba como parametro a altura (alt) e o sexo de uma pessoa e retorne
	seu peso ideal.
	Para homens, deverá calcular o peso ideal usando a formula: peso ideal = 72.7*alt-58; para mulheres:
	peso ideal = 62.1*alt-44.7.
*/
#include<iostream>
#include<string>

using namespace std;

float pesoIdeal(float alt, string genero){
	float peso_ideal = 0;
	
	if(genero == "feminino"){
		peso_ideal = 62.1*alt-44.7;
		return peso_ideal;
	}
	else if(genero == "masculino"){
		peso_ideal = 72.7*alt-58;
		return peso_ideal;
	}
	
}

int main(){
	int opcao;
	float altura;
	string generoEscolhido;
	
	cout<<"Qual eh o seu genero?"<<endl<<"Digite 1 para o genero feminino ou digite 2 para o genero masculino: "<<endl;
	cin>>opcao;
	cout<<"Qual eh a sua altura?";
	cin>> altura;
	
	switch(opcao){
		case 1:
			generoEscolhido = "feminino";
			cout<<"Genero escolhido "<< generoEscolhido <<endl;
			cout<<"Seu peso ideal eh: "<< pesoIdeal(altura, generoEscolhido) <<endl;
			break;
			
		case 2:
			generoEscolhido = "masculino";
			cout<<"Genero escolhido "<< generoEscolhido <<endl;
			cout<<"Seu peso ideal eh: "<< pesoIdeal(altura, generoEscolhido) <<endl;
			break;
			
		default:
			cout<<" ... ";
	}
}
