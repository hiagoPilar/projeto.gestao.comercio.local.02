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



//verificações

bool Loja::ehNumero(string& str)
{
	for(char const& c : str) //ciclo para percorrer cada caractere da string str
	{
		if (!isdigit(c)) { //verifica se o caractere atual nao é um digito  
			return false;
		}
	}
	return true;
}

bool Loja::ehTexto(const string& str)
{
	for (char const& c : str)
	{
		if (!isalpha(c) && c != ' ') { //verifica se o caractere é uma letra ou espaço
			return false;
		}
	}
	return true;
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


void Loja::criarCliente()  
{
	int idcliente, idade, telefone; 
	string nome, morada; 
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
		if (!ehTexto(nome)) {
			cout << "Nome deve conter somente letras, digite novamente: ";
			cin >> nome;
		}

		cout << "Idade: ";
		cin >> idade;
		while (!(cin >> idade)) //verifica se a entrada é válida
		{
			cin.clear(); //limpa o estado de erro do cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignora a entrada invalida
			cout << "Entrada invalida! Digite um número para a idade: ";
		}
		if (!ehNumero(idade)) { 
			cout << "Idade deve conter somente números, digite novamente: ";
			cin >> idade;  
		}

		cout << "Telefone: ";
		while (!(cin >> telefone))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Entrada inválida! Digite um número para o telefone: ";
		}

		cout << "Morada: ";
		cin.ignore(); 
		getline(cin, morada);
		
		idcliente = totalClientes + 1;   

		vecCliente[totalClientes] = Cliente(idcliente, nome, idade, telefone, morada); 
		totalClientes++;
		
		string opcao;   
		cout << "Os dados estão corretos?" << endl;
		cout << idcliente << " | " << nome << " | " << idade << " | " << telefone << " | " << morada << endl;
		cout << "S ou N?";
		cin >> opcao;   
		
		 
		if (opcao == "s") {  
			continuar = true;
		}
		else {  
			cout << "Por favor, insira os dados novamente." << endl;
			break; 
		} 

		cout << endl;
		cout << "-------------------------------" << endl;
		cout << "Cliente adicionado com sucesso!";
		cout << "_______________________________" << endl;
		cout << endl;

		cout << "Deseja adicionar outro cliente? (S) ou (N)" << endl;
		cin >> opcao;
		if (opcao == "s") {
			continuar = false;
		}
		else {
			continuar = true;
		} 

	} while (continuar == false);

}

void Loja::excluirCliente()
{
	int idexcluir; 
	string opcao;  
	bool continuar = false;

	if (totalClientes == 0) {
		cout << "Nenhum cliente cadastrado!" << endl;
		return;  
	}

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
				cout << "Tem certeza que deseja excluir o cliente com ID " << vecCliente[i].getIdCliente() << endl; 
				cout << "s | n = ";
				cin >> opcao; 
				if (opcao == "s") { 
					//remover o id do vetor 
					for (int k = i; k < totalClientes - 1; k++)  
					{
						vecCliente[k] = vecCliente[k + 1]; 
					}
					totalClientes--; 

					cout << "Cliente com ID " << idexcluir << " excluído com sucesso!" << endl;
				} 
			}
		}
		
		cout << "-------------------------------------------" << endl; 
		cout << "Deseja excluir outro cliente? (S) ou (N)" << endl;
		cin >> opcao;
		if (opcao == "S") {
			continuar = false;
		}
		else { 
			return; 
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
				cout << "Nome do cliente com ID " << idAlterar << " alterado com sucesso!" << endl;
				continuar = true; 
				break;
			}
		}
		if (!continuar) { 
			cout << "Cliente com o ID " << idAlterar << " não encontrado!" << endl; 
		}
		string opcao; 
		cout << "----------------------------------------" << endl;
		cout << "Deseja alterar outro cliente? (S) ou (N)" << endl;
		cin >> opcao;
		if (opcao == "s") {
			continuar = false; 
		}
		else {
			continuar = true; 
		}

	} while (false);

}
