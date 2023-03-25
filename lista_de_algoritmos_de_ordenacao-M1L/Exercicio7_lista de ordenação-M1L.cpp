/*
	7. Crie um vetor que armazene dados de 10 funcionários de uma empresa. Deverão ser
considerados os campos: código funcional, nome, salário e data de admissão.
Elabore um programa que: preencha o vetor com os dados fornecidos pelo usuário e
ordene de forma crescente os elementos pelo campo de código funcional, usando o
quick sort.
*/
#include<iostream>
#include<string>

using namespace std;

const int TAMANHO = 10;

struct Funcionario{
	string nome;
	int codigo_funcional;
	float salario;
	string data_admissao;
};

void entrada_de_dados(struct Funcionario *vFuncionarios){
	int i;
	struct Funcionario *aux_funcionario = vFuncionarios;
	
	for(i = 0; i <= TAMANHO-1; i++)
	{
		cout<<"Digite o nome do "<< i+1 <<" funcionario: ";
		_flushall();
		getline(cin, aux_funcionario[i].nome);
		
		cout<<endl;
		cout<<"Digite o codigo funcional do funcionario: ";
		cin>>aux_funcionario[i].codigo_funcional;
		
		cout<<endl;
		
		cout<<"Digite o salario do funcionario: "; 
		cin>>aux_funcionario[i].salario;
		
		cout<<endl;
		
		cout<<"Digite a data de admissao do funcionario: "; 
		_flushall();
		getline(cin, aux_funcionario[i].data_admissao);
		
		cout<<endl;

		cout<<"----------------------------------------------"<<endl;
	}
}

void imprime_dados(struct Funcionario *vFuncionarios){
	int i;
	struct Funcionario *aux_funcionario = vFuncionarios;
	
	for(i = 0; i <= TAMANHO-1; i++)
	{
		cout<< i+1 <<" Funcionario: "<< aux_funcionario[i].nome <<"\t\t";
				
		cout<<"Codigo funcional: "<< aux_funcionario[i].codigo_funcional <<"\t\t";
				
		cout<<"Salario: "<< aux_funcionario[i].salario <<"\t\t";
		
		cout<<"Data de admissao: "<< aux_funcionario[i].data_admissao <<"\t\t";

		cout<<"---------------------------------------------------------------------------------------------- \t\t"<<endl;
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
/*Algoritmo quick sort*/

void troca(struct Funcionario *vFuncionarios, int i, int j){
	string aux_nome;	
	int aux_codigoFuncional;
	float aux_salario;
	string aux_dataAdmissao;
	
	aux_nome = vFuncionarios[i].nome;
	vFuncionarios[i].nome = vFuncionarios[j].nome;
	vFuncionarios[j].nome = aux_nome;
	
	aux_codigoFuncional = vFuncionarios[i].codigo_funcional;
	vFuncionarios[i].codigo_funcional = vFuncionarios[j].codigo_funcional;
	vFuncionarios[j].codigo_funcional = aux_codigoFuncional;
	
	aux_salario = vFuncionarios[i].salario;
	vFuncionarios[i].salario = vFuncionarios[j].salario;
	vFuncionarios[j].salario = aux_salario;
	
	aux_dataAdmissao = vFuncionarios[i].data_admissao;
	vFuncionarios[i].data_admissao = vFuncionarios[j].data_admissao;
	vFuncionarios[j].data_admissao = aux_dataAdmissao;
}

int particao(struct Funcionario *vFuncionarios, int p, int r){
	int pivo, i, j;
	pivo = vFuncionarios[(p+r)/2].codigo_funcional;
	i = p - 1;
	j = r + 1;
	
	while(i < j)
	{
		do
		{
			j = j -1;
		}while(vFuncionarios[j].codigo_funcional > pivo);
		do
		{
			i = i + 1;
		}while(vFuncionarios[i].codigo_funcional < pivo);
		
		if(i < j)
			troca(vFuncionarios, i, j);
	}
	return j;
}

void ordenar_codigoFuncional_quickSort(struct Funcionario *vFuncionarios, int p, int r){
	int q;
	if(p < r)
	{
		q = particao(vFuncionarios, p, r);
		ordenar_codigoFuncional_quickSort(vFuncionarios, p, q);
		ordenar_codigoFuncional_quickSort(vFuncionarios, q+1, r);
	}
}

int main(){
	struct Funcionario cadastrar_funcionario[TAMANHO];
	
	entrada_de_dados(cadastrar_funcionario);
	cout<<"Vetor Original"<<endl<<endl;
	imprime_dados(cadastrar_funcionario);
	cout<<"################################################################################################"<<endl;
	ordenar_codigoFuncional_quickSort(cadastrar_funcionario, 0, TAMANHO-1);
	cout<<"Vetor ordenado por codigo funcional"<<endl;
	imprime_dados(cadastrar_funcionario);
}
