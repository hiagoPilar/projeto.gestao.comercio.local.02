#include "classe_loja.h"
#include "classe_cliente.h"



Loja::Loja()
{

}


//clientes

void Loja::criarCliente(int idcliente, string nome, int idade, int telefone, string morada)   
{
	string cond;
	bool continuar = false;
	do
	{
		cout << "________________________________________" << endl;
		cout << "        Adicionar Novo Cliente          " << endl;
		cout << "________________________________________" << endl;
		cout << "Nome do cliente: ";
		cin >> nome;
		cout << "Idade: ";
		cin >> idade;
		cout << "Telefone: ";
		cin >> telefone;
		cout << "Morada: ";
		cin >> morada;
		//atualiza o id cliente conforme o tamanho do vetor
		idcliente = vecClientes.size(); 

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


	//novo objeto cliente
	Cliente novoCliente(idcliente, nome, idade, telefone, morada);  

	//add o novo cliente ao vetor clientes
	vecClientes.push_back(novoCliente); 

	cout << endl;
	cout << "_______________________________" << endl;
	cout << "Cliente adicionado com sucesso!";
	cout << "_______________________________" << endl;  
	cout << endl;
}

void Loja::excluirCliente(int idcliente)
{
	int idexcluir;
	bool continuar = false;
	do
	{
		cout << "________________________________________" << endl;
		cout << "             Excluir Cliente            " << endl;
		cout << "________________________________________" << endl;
		cout << "Digite o ID do cliente que deseja excluir: ";
		cin >> idexcluir;
		cout << "________________________________________" << endl;

	} while (continuar == false);

}

void Loja::alterarNome(int idcliente) 
{


}
