#include<iostream>
#include<string>
#include<iomanip>

/*
	1. Faça um programa que cadastre o nome e o salário de 5 funcionários. Usando um
		método de ordenação diferente para cada item a seguir, liste todos os dados dos
		funcionários das seguintes formas:
	a. Em ordem crescente de salário;
	b. Em ordem decrescente de salário;
	c. Em ordem alfabética.
*/
using namespace std;

const int TAM = 5;

struct Funcionario{
	string nome;
	float salario;
};

void cabecalho(){
	cout<<"*****************************************************"<<endl;
	cout<<"**        Organizador de folhas de pagamento       **"<<endl;
	cout<<"*****************************************************"<<endl;
}

void entrada_de_dados(struct Funcionario *vfuncionarios){
	int i;
	
	struct Funcionario *pAux = vfuncionarios;// o nome do vetor, no caso vfuncionarios é um ponteiro fixo que so aponta para o primeiro elemento, por isso é criado um ponteiro auxiliar *pAux para percorrer o vetor
	
	for(i=0; i<= TAM - 1; i++){
		cout<<"Digite o nome do " << i+1 <<"o. funcionario"<<endl;
		_flushall();
		getline(cin, pAux->nome);
		
		cout<<"\tSalario: ";
		cin>> pAux->salario;
		pAux = pAux + 1;
	}
}

void imprime_vetor(struct Funcionario *vfuncionarios){
	int i;
	struct Funcionario *pAux = vfuncionarios;
	
	cout<<"NOME\t SALARIO"<<endl;
	
	for(i = 0; i<TAM; i++){
		cout<<pAux->nome<< "\t\t" <<pAux->salario<<endl;
		pAux = pAux + 1;
	}
	cout<<endl;
}

int menu(){
	int escolha;
	
	do{
		cout<<"1 - Ordenar por salario (crescente)."<<endl;
		cout<<"2 - Ordenar por salario (decrescente)."<<endl;
		cout<<"3 - Ordenar por nome (crescente)."<<endl;
		cout<<"0 - sair."<<endl<<endl;
		
		cout<<"Digite sua escolha: ";
		cin>> escolha;
		if(escolha<0 || escolha >3)
			cout<<"\tValor invalido!"<<endl;
	}while(escolha < 0 || escolha > 3);
	
	return escolha;
}

void bubblesort_v0_C(struct Funcionario *vfuncionarios){
	int i,n;
	struct Funcionario *pAux = vfuncionarios;
	struct Funcionario *pAux2 = vfuncionarios;
	
	for(n=1; n<=5; n++){
		for(i=0; i<=3; i++){
			if(vfuncionarios[i].salario > vfuncionarios[i+1].salario){
				pAux->salario = vfuncionarios[i].salario;
				vfuncionarios[i].salario = vfuncionarios[i+1].salario;
				vfuncionarios[i+1].salario = pAux->salario;	
				
				pAux2->nome = vfuncionarios[i].nome;
				vfuncionarios[i].nome = vfuncionarios[i+1].nome;
				vfuncionarios[i+1].nome = pAux2->nome;	
			}
		}
	}
}

void bubblesort_v1_D(struct Funcionario *vfuncionarios){
	int i, j;
	struct Funcionario *pAux = vfuncionarios;
	struct Funcionario *pAux2 = vfuncionarios;
	
	for(j=1; j<=4; j++){
		for(i=4; i>=j; i--){
			if(vfuncionarios[i].salario < vfuncionarios[i-1].salario){
				pAux->salario = vfuncionarios[i].salario;
				vfuncionarios[i].salario = vfuncionarios[i-1].salario;
				vfuncionarios[i-1].salario = pAux->salario;
				
				pAux2->nome = vfuncionarios[i].nome;
				vfuncionarios[i].nome = vfuncionarios[i+1].nome;
				vfuncionarios[i-1].nome = pAux2->nome;
			}
		}
	}
}

void bubblesort_v2_C(struct Funcionario *vfuncionarios){
	int n, i;
	bool troca;
	
	struct Funcionario *pAux = vfuncionarios;
	struct Funcionario *pAux2 = vfuncionarios;
	
	n = 1;
	troca = true;
	
	while(n <= 5 && troca == true){
		troca = false;
		
		for(i = 0;i<= 3; i++){
			if(vfuncionarios[i].salario > vfuncionarios[i+1].salario){
				pAux->salario = vfuncionarios[i].salario;
				vfuncionarios[i].salario = vfuncionarios[i+1].salario;
				vfuncionarios[i+1].salario = pAux->salario;	
				
				pAux2->nome = vfuncionarios[i].nome;
				vfuncionarios[i].nome = vfuncionarios[i+1].nome;
				vfuncionarios[i+1].nome = pAux2->nome;	
			}
		}
		n += 1;
	}
}
int main(){
	struct Funcionario folha[TAM];//como ele é um vetor já quer dizer q ele é um ponteiro
	int opcao;
	
	cabecalho();
	
	entrada_de_dados(folha);//o folha é o ponteiro que contem o endereço para o primeiro elemento do vetor, não precisa por o &, porque o vetor criado no main já é um ponteiro, o endereço do vetor é o proprio nome dele
	
	//imprimindo o vetor original
	cout<<endl<< "Vetor Original: "<<endl;
	imprime_vetor(folha);
	
	do{
		opcao = menu();
		
		switch(opcao)
		{
			case 1:
				cout<<"Ordenando por salario crescente ..."<<endl;
				bubblesort_v0_C(folha);
				cout<< endl << "Vetor ordenado: "<<endl;
				imprime_vetor(folha);
				break;
			
			case 2:
				cout<<"Ordenando por salario decrescente ..."<<endl;
				bubblesort_v1_D(folha);
				cout<< endl<< "Vetor ordenado: "<<endl;
				imprime_vetor(folha);
				break;
				
			case 3:
				cout<<"Ordenando por ordem alfabetica ..."<<endl;
				bubblesort_v2_C(folha);
				cout<< endl<< "Vetor ordenado: "<<endl;
				imprime_vetor(folha);
				break;
				
			default:
				cout<<"Saindo ..."<<endl;
		}
	}while(opcao != 0);
}
