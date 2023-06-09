/*
	1. Faça um programa que cadastre 5 produtos. Para cada produto devem ser 
cadastrados código do produto, preço e quantidade estocada. Os dados devem ser 
armazenados em uma lista simplesmente encadeada e não ordenada. Posteriormente, 
receber do usuário a taxa de desconto (ex.: digitar 10 para taxa de desconto de 10%). 
Aplicar a taxa digitada ao preço de todos os produtos cadastrados e finalmente 
mostrar um relatório com o código e o novo preço. O final desse relatório deve 
apresentar também a quantidade de produtos com quantidade estocada superior a 
500

*/

#include<iostream>

using namespace std;

const int QUANTIDADE_MAXIMA_ESTOQUE = 500;

typedef struct Noh_produto{
	string codProduto;
	float preco;
	int quantidadeEstocada;
	Noh_produto *proximo;
}Noh_produto;

typedef struct Lista{
	Noh_produto *inicio, *fim;
	int tamanho;
}Lista;

int menu(){
	int opcao;
	
	do
	{
		cout<<endl << "MENU DE OPCOES" <<endl;	
		cout<< "[1] - Inserir no fim da lista" <<endl;
		cout<< "[2] - Imprimir toda a lista" <<endl;
		cout<< "[3] - Aplicar desconto" <<endl;
		cout<< "[4] - Esvaziar lista" <<endl;
		cout<< "[5] - Sair" <<endl;
		
		cout<<"Digite sua escolha: ";
		cin>>opcao;
		
		if(opcao < 1 || opcao > 5)
			cout<<"\tEscolha invalida!"<<endl;
	}while(opcao < 1 || opcao > 5);
	
	return opcao;
}

bool eVazia(Lista *list)
{
	if(list->inicio == NULL)
		return true;
	return false;
}

void inserirFim(Lista *list, string codigo, float precoProduto, int estoque)
{
	Noh_produto *novo = new Noh_produto();
	novo->codProduto = codigo;
	novo->preco = precoProduto;
	novo->quantidadeEstocada = estoque;
	novo->proximo = NULL;
	
	if(eVazia(list))
	{
		list->inicio = novo;
		list->fim = novo;
	}
	else
	{
		list->fim->proximo = novo;
		list->fim = novo;
	}
	list->tamanho++;
}

int quantidade_excedida(Lista *list){
	int produtos_com_quantidadeMaxima_excedida = 0;
	
	if(eVazia(list))
		cout<<"A lista esta vazia"<<endl;
	else
	{
		Noh_produto *pAux = list->inicio;
		
		while(pAux != NULL)
		{
			if(pAux->quantidadeEstocada > QUANTIDADE_MAXIMA_ESTOQUE)
			{
				produtos_com_quantidadeMaxima_excedida++;
			}
			pAux = pAux->proximo;
		}
	}
	return produtos_com_quantidadeMaxima_excedida;
}

void imprime(Lista *list){
	cout<< endl <<"Tamanho da lista: "<< list->tamanho << endl;
	if(eVazia(list))
		cout<<"Lista vazia!"<<endl;
	else
	{
		Noh_produto *pAux = list->inicio;
		
		cout<<"Codigo do Produto  | Preco do produto  | Quantidade Estocada "<<endl;
		while(pAux != NULL)
		{	
			cout<< pAux->codProduto<< " ";
			cout<<"\t\t\t"<< pAux->preco<< " ";
			cout<<"\t\t\t"<< pAux->quantidadeEstocada<< " ";
			cout<<endl;
			pAux = pAux->proximo;
		}
		cout<<endl<<endl; 
	}
}

void aplicarDesconto(Lista *list, int desconto){
	if(eVazia(list))
		cout<<"Não tem nada para aplicar desconto"<<endl;
	else
	{
		Noh_produto *pAux = list->inicio;
		
		while(pAux != NULL)
		{
			pAux->preco -= (desconto/100)*pAux->preco;
			pAux = pAux->proximo; 
		}
		cout<< endl;
	}
}

void esvaziar(Lista *list){
	if(!eVazia(list))
	{
		Noh_produto *pAux;
		
		while(list->inicio != NULL)
		{
			pAux = list->inicio;
			list->inicio = list->inicio->proximo;
			delete(pAux);
			
			list->tamanho--;
		}
		
	}
	else
		cout<< endl <<"Lista vazia ..."<< endl << endl;
}

int main(){
	/*
		Cadastrar 5 produtos
		receber a taxa de desconto do usuario e aplicar nos produtos
		apresentar a quantidade de produtos com a capacidade maior que 500
		
		o codigo apresenta um problema na impressao fazendo com q a função quantidade_excedida fique em um loop eterno, consertar depois
	*/
	
	Lista lista;
	
	lista.inicio = NULL;
	lista.fim = NULL;
	lista.tamanho = 0;
	
	int escolha, quantidadeEm_estoque, desconto_aSerAplicado;
	string codigo_produto;
	float preco_produto;
	
	do
	{
		escolha = menu();
		
		switch(escolha){
			case 1:
				cout<<"Digite o codigo do produto a ser inserido no fim na lista: ";
				cin>>codigo_produto;
				cout<<"Digite o preco do produto: ";
				cin>>preco_produto;
				cout<<"Digite a quantidade em estoque do produto: ";
				cin>>quantidadeEm_estoque;
				inserirFim(&lista, codigo_produto, preco_produto, quantidadeEm_estoque);
			break;
			
			case 2:
				cout<<"Imprimindo a lista ...";
				imprime(&lista);
				if(quantidade_excedida(&lista) > 0)
					cout<<"Quantidade de produtos com estoque maior que o máximo permitido:"<< quantidade_excedida(&lista) <<endl;
				else
					cout<<"Nao ha produtos com o estoque excedido"<<endl;
			break;
			
			case 3:
				cout<<"Digite o valor de desconto que deseja aplicar: ";
				cin>>desconto_aSerAplicado;
				aplicarDesconto(&lista, desconto_aSerAplicado);
			break;
			
			case 4:
				cout<<endl<<"Esvaziando a lista ...";
				esvaziar(&lista);
			break;
			
			default:
				cout<<"Saindo ...";
				
		}
	}while(escolha != 5);
}
