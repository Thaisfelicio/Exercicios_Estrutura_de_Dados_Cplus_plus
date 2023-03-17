#include <iostream>

using namespace std;

void dadosPessoais()
{
	cout<<"**************DADOS PESSOAIS****************"<<endl;
	cout<<"Nome: Thaís Felício"<<endl;
	cout<<"Endereço: Viela limeira, n 4"<<endl;
	cout<<"Telefone: (12) 991 ....."<<endl;
	cout<<"E-mail: thsfelicio@gmail.com"<<endl;
	
}

void dadosProfissionais()
{
	cout<<"Nome empresa: Nooobes"<<endl;
	cout<<"Endereco: Rua de baixo, n 240"<<endl;
	cout<<"Telefone da empresa: (332) 896578-54967"<<endl;
	cout<<"Funcao: Empresa de treinamento de alunos recem formados"<<endl;
	
}

int menu()
{
	int opcao = 0;
	
	do
	{
		cout<<"MENU DE OPCOES"<<endl;
		cout<<" 1 - Imprimir dados pessoais"<<endl;
		cout<<" 2 - Imprimir dados Profissionais"<<endl;
		cout<<" 3 - Sair do programa"<<endl;
		
		cin>> opcao;
		
		if(opcao < 0 || opcao > 3)
		{
			cout<<"Opcao invalida!";
		}
	}while(opcao < 1 && opcao > 4);
}

int main()
{
	 int escolha;
	 escolha = menu();
	
	
	
	switch(escolha)
	{
		case 1:
			dadosPessoais();
			break;
			
		case 2:
			dadosProfissionais();
			break;
			
		default:
			cout<<"Saindo ..."<< endl;
			
	}
}
