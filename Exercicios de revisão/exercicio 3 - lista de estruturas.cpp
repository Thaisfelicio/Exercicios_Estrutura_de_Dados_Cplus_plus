/*
3. Uma empresa de casas pré-fabricadas fabrica diversos modelos de casa. Cada modelo tem um número de identificação,
 um nome comercial (ex, “Casa Veraneio”, “Chalé Suíço Luxo”, etc...),
  o número de quartos, a área útil e o preço de venda.
a. Crie uma estrutura chamada ModeloDeCasa que tenha um inteiro para armazenar o número de identificação,
 uma string de 30 caracteres para o nome comercial do modelo, um inteiro para o número de quartos,
  um real simples para a área útil e outro para o preço de venda. Quanta memória foi alocada?
b. Crie 3 variáveis para armazenar modelos de casa, chamadas mod1, mod2 e modStandard. Quanta memória foi alocada?
c. Faça um programa que crie três modelos de casa, inicializando-os no momento da declaração e imprima o resultado.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ModeloDeCasa
{
	int id;
	vector<string> nome;
	int quartos;
	float areaUtil;
	float precoVenda;	
	
	void modelo1()
	{
//		vector<string> *Nome = this -> &nome;
//		int *Id = this -> &id;
//		this->id = Id;
		int ID;
		string Onome;
		int OsQuartos;
		float AAreaUtil;
		float OPrecoVenda;
		
		this -> id = ID;
		this -> nome;
		this -> quartos = OsQuartos;
		this -> areaUtil = AAreaUtil;
		this -> precoVenda = OPrecoVenda;
		
		cout<<"Qual o numero de id do modelo 1?"<<endl;
		cin>> ID;
		cout<<"Qual o nome o nome comercial?"<<endl;
		cin>> Onome;
		nome.push_back(Onome);
		cout<<"Quantos quartos tem o modelo 1?"<<endl;
		cin>> OsQuartos;
		cout<<"Qual a area util do imovel?"<<endl;
		cin>> AAreaUtil;
		cout<<"Qual o preco do imovel?"<<endl;
		cin>> OPrecoVenda;
		
		//impressao do dados
		cout<<"Modelo 1\n"<<endl;
		cout<<"ID: "<< ID <<endl;
		cout<<"NOME: "<< Onome <<endl;
		cout<<"QUARTOS: "<< OsQuartos <<endl;
		cout<<"AREA UTIL: "<< AAreaUtil <<" m quadrados"<<endl;
		cout<<"PRECO: R$ "<< OPrecoVenda <<",00"<<endl;
	}
	
	void modelo2()
	{
		int ID2;
		string Onome2;
		int OsQuartos2;
		float AAreaUtil2;
		float OPrecoVenda2;
		
		this -> id = ID2;
		this -> nome;
		this -> quartos = OsQuartos2;
		this -> areaUtil = AAreaUtil2;
		this -> precoVenda = OPrecoVenda2;
		
		cout<<"Qual o numero de id do modelo 2?"<<endl;
		cin>> ID2;
		cout<<"Qual o nome o nome comercial?"<<endl;
		cin>> Onome2;
		nome.push_back(Onome2);
		cout<<"Quantos quartos tem o modelo 2?"<<endl;
		cin>> OsQuartos2;
		cout<<"Qual a area util do imovel?"<<endl;
		cin>> AAreaUtil2;
		cout<<"Qual o preco do imovel?"<<endl;
		cin>> OPrecoVenda2;
		
		//impressao do dados
		cout<<"Modelo 2\n"<<endl;
		cout<<"ID: "<< ID2 <<endl;
		cout<<"NOME: "<< Onome2 <<endl;
		cout<<"QUARTOS: "<< OsQuartos2 <<endl;
		cout<<"AREA UTIL: "<< AAreaUtil2 <<" m quadrados"<<endl;
		cout<<"PRECO: R$ "<< OPrecoVenda2 <<",00"<<endl;
	}
	
	void ModPadrao()
	{
		cout<<"Modelo Standard\n"<<endl;
		cout<<"ID: 5"<<endl;
		cout<<"NOME: Imovel padrao"<<endl;
		cout<<"QUARTOS: 3"<<endl;
		cout<<"AREA UTIL: 300 m quadrados"<<endl;
		cout<<"PRECO: R$ 500.000,00"<<endl;
	}
};

int menu()
{
	int opcao;
	do
	{
	
	cout<<"MENU DE OPCOES\n"<<endl;
	cout<<"Escolha o modelo de casa"<<endl;
	cout<<"1 - modelo 1"<<endl;
	cout<<"2 - modelo 2"<<endl;
	cout<<"3 - modelo Standard"<<endl;
	cout<<"4 - Sair"<<endl;
	
	cout<<"Digite sua opcao: "<<endl;
	cin>> opcao;
	
	if(opcao < 0 || opcao > 4)
		cout<<"Opcao inválida"<<endl;
	}while(opcao < 0 || opcao > 4);
	
	return opcao;
}

int main()
{
	ModeloDeCasa mod1;
	
	int escolha;
	
	
	do
	{
		escolha = menu();
		
		switch(escolha)
		{
		
		case 1:
			mod1.modelo1();
		break;
			
		case 2:
			mod1.modelo2();
		break;
		
		case 3:
			mod1.ModPadrao();
		break;
		
		default:
			cout<<"Saindo ...";
		}
	}while(escolha > 0 || escolha < 4);
	
	cout<<"Foi alocado na memoria: "<< sizeof(ModeloDeCasa) <<" bytes"<<endl;
}
