/*
	------------------Exercicio de Avalia��o-----------------------
	
	Exercicios Propostos 2 - cap.8 - p�g.298 - Livro Fundamentos da programa��o de computadores
	____________________________________________________________________________________________________
	Crie uma sub-rotina que receba tres(3) numeros inteiros como parametros, representando horas, minutos e segundos, e os
	converta em segundos. Exemplo: 2h, 40 min e 10s correspondem a 9.610 segundos.
*/

#include <iostream>

using namespace std;

int converteParaSegundos(int horas, int minutos, int segundos){	
	minutos = 60;
	horas = minutos*60;
	
	segundos = horas;
	return segundos;
}

int main(){
	int hora, minuto, segundo;
	cout<<"Digite as horas, os minutos e os segundos a serem convertidos: "<<endl;
	cout<<"Hora: ";
	cin>> hora;
	
	cout<<"Minuto: ";
	cin>> minuto;
	
	cout<<"Segundo: ";
	cin>> segundo;
	
	cout<<"Sao "<< converteParaSegundos(hora, minuto, segundo) <<"segundos"<<endl;
}
