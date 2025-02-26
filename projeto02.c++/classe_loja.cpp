#include "classe_loja.h"
#include "classe_cliente.h"

using namespace std; 

Loja::Loja(int capacidade) 
{
	this->capacidade = capacidade; 
	this->totalClientes = 0;    
	//inicializa o sistema com alguns clientes já inseridos
	clientesIniciais(); 
}


//clientes

void Loja::clientesIniciais()
{
	vecCliente[0] = Cliente(1, "Hiago Pilar Ribeiro", 32, 123123123, "Rua A"); 
	vecCliente[1] = Cliente(2, "Luan Rodrigues", 36, 321321312, "Rua B"); 
	vecCliente[2] = Cliente(3, "Joao Silva", 68, 789789789, "Rua C"); 
	vecCliente[3] = Cliente(4, "Pedro Souza", 52, 456456456, "Rua D"); 
	totalClientes = 4;
}

//PRECISA ARRUMAR AS ENTRADAS DE TEXTOS E NUMEROS PARA NAO DAR ERRO DE LOOP INFINITO QUANDO DIGITAR ALGO ERRADO


void Loja::criarCliente()  
{
	int idcliente, idade, telefone; 
	string cond, nome, morada; 
	bool continuar = false; 

	if (totalClientes >= capacidade)        
	{ 
		cout << "Limite de clientes atingido. Não é possível adicionar mais clientes." << endl;
		return; 
	}

	do
	{
		
		system("cls"); 
		cout << "----------------------------------------" << endl;
		cout << "        Adicionar Novo Cliente          " << endl;
		cout << "________________________________________" << endl;
		cout << "Nome do cliente: "; 
		cin.ignore(); 
		getline(cin, nome); 
		cout << "Idade: ";
		cin.ignore();
		cin >> idade;  
		cout << "Telefone: ";
		cin >> telefone; 
		cout << "Morada: ";
		cin.ignore(); 
		getline(cin, morada);
		
		totalClientes++;
		idcliente = totalClientes;  

		vecCliente[totalClientes] = Cliente(idcliente, nome, idade, telefone, morada);
		
		cout << "Os dados estão corretos?" << endl;
		cout << idcliente << "|" << nome << "|" << idade << "|" << telefone << "|" << morada << endl;
		cout << "S ou N?";
		cin >> cond; 
		
		if (cond == "S") {
			continuar = true;
		}
		else {
			cout << "Por favor, insira os dados novamente." << endl;
		}

	} while (continuar == false);

	cout << endl;
	cout << "-------------------------------" << endl;
	cout << "Cliente adicionado com sucesso!";
	cout << "_______________________________" << endl;  
	cout << endl;
}

void Loja::excluirCliente()
{
	int idexcluir; 
	bool continuar = false;
	system("cls");
	cout << "----------------------------------------" << endl;
	cout << "             Excluir Cliente            " << endl;
	cout << "________________________________________" << endl; 
	
	do
	{
		//mostrar na tela lista completa de clientes
		for (int i = 0; i < totalClientes; i++)
		{
			cout << endl;
			cout << "ID: " << vecCliente[i].getIdCliente() << " | Nome: " << vecCliente[i].getNome() << " | Idade: " << vecCliente[i].getIdade() << " | Telefone: " << vecCliente[i].getTelefone() << " | Morada: " << vecCliente[i].getMorada() << endl;
			cout << "-----------------------------------------------------------------------------------" << endl;
		} 
		
		cout << endl; 
		cout << "Digite o ID do cliente que deseja excluir: ";
		cin >> idexcluir;
		cout << "________________________________________" << endl;

		//busca pelo ID no vetor clientes
		for (int i = 0; i < totalClientes; i++)
		{
			if (vecCliente[i].getIdCliente() == idexcluir) 
			{
				continuar = true;
				//remover o id do vetor
				for (int j = i; j < totalClientes -1 ; j++)
				{
					vecCliente[j] = vecCliente[j + 1]; 
				} 
				totalClientes--; 

				cout << "Cliente com ID " << idexcluir << " excluído com sucesso!" << endl;
			}
		}
		string opcao;
		cout << "-------------------------------------------" << endl; 
		cout << "Deseja exluir outro cliente? (S) ou (N)" << endl;
		cin >> opcao;
		if (opcao == "S") {
			continuar = false;
		}
		else { 
			continuar = true;   
		}

	} while (continuar == false);

}

void Loja::alterarNome() 
{
	int idAlterar;
	string novoNome;
	bool continuar = false;

	if (totalClientes == 0) {
		cout << "Nenhum cliente cadastrado!" << endl;
		return;  
	}
	system("cls"); 
	cout << "----------------------------------------" << endl;
	cout << "         Alterar Nome do Cliente        " << endl;
	cout << "________________________________________" << endl; 
	do
	{
		 
		//mostrar na tela lista completa de clientes
		for (int i = 0; i < totalClientes; i++)
		{
			cout << endl;
			cout << "ID: " << vecCliente[i].getIdCliente() << " | Nome: " << vecCliente[i].getNome() << " | Idade: " << vecCliente[i].getIdade() << " | Telefone: " << vecCliente[i].getTelefone() << " | Morada: " << vecCliente[i].getMorada() << endl;
			cout << "-------------------------------------------------------------------------------------------------" << endl; 
		}

		cout << endl;
		cout << "Digite o ID do cliente que deseja alterar: ";
		cin >> idAlterar; 
		cout << "________________________________________" << endl;

		for (int i = 0; i <= totalClientes; i++) 
		{
			if (vecCliente[i].getIdCliente() == idAlterar) 
			{
				cout << endl; 
				cout << "Qual o novo nome para a alteração: ";
				cin.ignore();
				getline(cin, novoNome); 
				//alterar nome do cliente
				vecCliente[i].setNome(novoNome); 
				continuar = true;
				cout << "Nome do cliente com ID " << idAlterar << " alterado com sucesso!" << endl;
				break;
			}
		}
		if (!continuar) { 
			cout << "Cliente com o ID " << idAlterar << " não encontrado!" << endl; 
		}

	} while (false);

}
