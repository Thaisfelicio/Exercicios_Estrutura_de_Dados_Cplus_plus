#include<iostream>
//passo 1 - fazer a funcao FparaC e declarar as variaveis
//passo 2 - fazer a formula de faren para graus
//passo 3 - fazer um loop para sempre converter f para c(provalvemente irei usar do, while.

using namespace std;

float FparaC(float fah)
{	
	return (fah - 32) * 5/9; // opcao 1
}

float CparaF(float celsius)
{
	return (celsius * 9/5) + 32; // opcao 2
}

float CparaK(float celsius)
{
	return celsius + 273.15; //opcao 3
}

float KparaC(float kelvin)
{
	return kelvin - 273.15; // opcao 4
}

float KparaF(float kelvin)
{
	return (kelvin - 273.15) * 9/5 + 32; // opcao 5
}

float FparaK(float fah)
{
	return (fah - 32) * 5/9 + 273.15; // opcao 6
}

int menu()
{
	int opcao;
	
	do
	{
		cout<<"\t MENU DE OPCOES"<< endl << endl;
		cout<<"1 - Converter fahrenheit para celsius"<< endl;
		cout<<"2 - Converter celsius para fahrenheit"<< endl;
		cout<<"3 - Converter celsius para kelvin"<< endl;
		cout<<"4 - Converter kelvin para celsius"<< endl;
		cout<<"5 - Converter kelvin para fahrenheit"<< endl;
		cout<<"6 - Converter fahrenheit para kelvin"<< endl;
		cout<<"7 - Nao quero converter nada!\n"<< endl;
		
		cin>> opcao;
		
		if(opcao < 1 || opcao > 7)
			cout<<"Opcao invalida!!!\n Tente novamente"<< endl; 
	}while(opcao < 1 || opcao > 7);
	
	return opcao;
}

int main()
{
	float fah;
	float temperatura;
	int escolha;	
	
	do
	{
		escolha = menu();
		
		switch(escolha)
		{
			case 1:
				cout<<"Digite o valor em grau fahrenheit:"<< endl;
				cin>> temperatura;
	
				cout<<" Em celsius e: " << FparaC(temperatura)<< endl;
				
			break;
			
			case 2:
				cout<<"Digite o valor em grau celsius:"<< endl;
				cin>> temperatura;
				
				cout<<" Em fahrenheit e: " << CparaF(temperatura)<< endl;
			break;
			
			case 3:
				cout<<"Digite o valor em grau celsius:"<< endl;
				cin>> temperatura;
				
				cout<<" Em kelvin e: " << CparaK(temperatura)<< endl;
			break;
			
			case 4:
				cout<<"Digite o valor em grau kelvin:"<< endl;
				cin>> temperatura;
				
				cout<<" Em celsius e: " << KparaC(temperatura)<< endl;
			break;
			
			case 5:
				cout<<"Digite o valor em grau kelvin:"<< endl;
				cin>> temperatura;
				
				cout<<" Em fahrenheit e: " << KparaF(temperatura)<< endl;
			break;
			
			case 6:
				cout<<"Digite o valor em grau fahrenheit:"<< endl;
				cin>> temperatura;
				
				cout<<" Em kelvin e: " << FparaK(temperatura)<< endl;
			break;
			
			default:
				cout<<"Saindo ........."<< endl;
		}
	}while(escolha != 7);
}
