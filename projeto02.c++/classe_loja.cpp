#include "classe_loja.h"
#include "classe_cliente.h"


Loja::Loja(int capacidade) 
{
	this->totalClientes = 4;      
	this->totalProdutos = 0;
	this->totalVendas = 0; 
	this->numFatura = 1; 
	clientesIniciais(); 
	stockInicial(); 
}



//verificações

bool Loja::ehNumero(string& str)
{
	if (str.empty()) return false; //nao permite aceitar string vazia

	for(char const& c : str) //ciclo para percorrer cada caractere da string str
	{
		if (!isdigit(c)) { //verifica se o caractere atual nao é um numero  
			return false;
		}
	}
	return true;
}

bool Loja::ehTexto(const string& str)
{
	if (str.empty()) return false; 
	
	for (char const& c : str)
	{
		if (!isalpha(c) && c != ' ') { //verifica se o caractere é uma letra ou espaço
			return false;
		}
	}
	return true;
}

bool Loja::ehFloat(const string& str)
{
	bool ponto = false; //variavel para procurar um ponto decimal

	for (char c : str) { //percorre cada caractere da string 
		if (!isdigit(c)) { //se o caractere NAO for um numero
			if (c == '.' && !ponto) { //se for um ponto decimal e nao encontrei outro
				ponto = true; //ponto encontrado
			}
			else {
				return false; //senao for um numero nem um unico ponto, false
			}
		}
	}

	return !str.empty(); //retorna true se a string nao estiver vazia
}

char Loja::ehSimNao() 
{
	string opcao;
	char resposta;
	
	while (true)
	{  
		cout << "Digite (S) para sim ou (N) para não: ";   
		cin >> opcao; 

		//verifica se a entrada tem somente um caractere
		if (opcao.length() == 1) {
			resposta = toupper(opcao[0]); //converte para maiusculo 

			//verifica se é s ou n
			if (resposta == 'S' || resposta == 'N') {
				return resposta;    
			}
		}
		cout << "Entrada inválida! Digite apenas (S) ou (N)." << endl;

	}
	
}

string Loja::removerEspacosExtras(string str)
{
	str.erase(0, str.find_first_not_of(" ")); //remove espacos do inicio
	str.erase(str.find_last_not_of(" ") + 1); //remove espacos do fim
	return str;
}

void Loja::transformarParaMinusculo(string& str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);     
}



//extras

void Loja::dataHora()
{
	time_t tempoAtual = time(0); //obtem o tempo atual do sistema

	struct tm tempoLocal;  //cria um struct de tempo para armazenar data e hora

	localtime_s(&tempoLocal, &tempoAtual); //converte para o formato de data e hora legivel, usando localtime_s para maior segurança

	cout << "Data: " << tempoLocal.tm_mday << "/" << tempoLocal.tm_mon + 1 << "/" << tempoLocal.tm_year + 1900 << " - Hora: " << tempoLocal.tm_hour << ":" << tempoLocal.tm_min << ":" << tempoLocal.tm_sec << endl;   

}

bool Loja::sorteio()
{
	srand(time(0));

	int chanceSorteio = rand() % 100;  // Número entre 0 e 9 (10% de chance) 
	return (chanceSorteio == 0);  // Retorna verdadeiro se for sorteado  
}




//clientes

void Loja::clientesIniciais()
{
	vecCliente[0] = Cliente(1, "Hiago Pilar Ribeiro", 32, 123123123, "Rua A"); 
	vecCliente[1] = Cliente(2, "Luan Rodrigues", 36, 321321312, "Rua B"); 
	vecCliente[2] = Cliente(3, "Joao Silva", 68, 789789789, "Rua C"); 
	vecCliente[3] = Cliente(4, "Pedro Souza", 52, 456456456, "Rua D"); 
	
}

void Loja::mostrarClientes()
{
	
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                   CLIENTES                                     " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;;
	for (int i = 0; i < totalClientes -1; i++)
	{
		cout << "ID: " << vecCliente[i].getIdCliente() << " | Nome: " << vecCliente[i].getNome() << " | Idade: " << vecCliente[i].getIdade() << " Telefone: " << vecCliente[i].getTelefone() << " | Morada: " << vecCliente[i].getMorada() << endl;
		cout << "--------------------------------------------------------------------------------" << endl; 
	}
}

void Loja::criarCliente()  
{
	int idcliente, idade, telefone, capacidade = 0;      
	string nome, morada, opcao, idadeStr, telefoneStr;  
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

		do
		{
			cout << "Nome do cliente (ou 'sair' para voltar ao Menu Cliente): ";
			cin.ignore();
			getline(cin, nome);
			while (!ehTexto(nome)) {
				cout << "Nome deve conter somente letras, digite novamente: ";
				getline(cin, nome); 
			}
			if(nome == "sair") { 
				return;   
			}

			cout << "Idade: ";
			getline(cin, idadeStr);  
			while (!ehNumero(idadeStr)) {   
				cout << "Entrada invalida! Digite um número para a idade: "; 
				getline(cin, idadeStr);   
			}
			idade = stoi(idadeStr);

			cout << "Telefone: ";
			getline(cin, telefoneStr);
			while (!ehNumero(telefoneStr)) {
				cout << "Entrada inválida! Digite um número para o telefone: " << '\n';
				getline(cin, telefoneStr);  
			}
			telefone = stoi(telefoneStr);

			cout << "Morada: ";
			cin.ignore();
			getline(cin, morada);

			idcliente = totalClientes + 1; 

			vecCliente[totalClientes] = Cliente(idcliente, nome, idade, telefone, morada);
			totalClientes++; 

			
			cout << "Os dados estão corretos?" << endl;
			cout << idcliente << " | " << nome << " | " << idade << " | " << telefone << " | " << morada << endl;
			cin.ignore();
			char resposta = ehSimNao();

			if (opcao == "s") {
				continuar = true;
			}
			else if (opcao == "n") {
				cout << endl;
				cout << "Por favor, insira os dados novamente." << endl;
				cout << endl; 
			}

		} while (!continuar);
		

		cout << endl;
		cout << "-------------------------------" << endl;
		cout << "Cliente adicionado com sucesso!";
		cout << "_______________________________" << endl;
		cout << endl;

		cout << "Deseja adicionar outro cliente? " << endl;
		cin.ignore();
		char resposta = ehSimNao();
		if (opcao == "s") {
			continuar = false;
		}
		else if (opcao == "n") {
			continuar = true;
		}  

	} while (continuar == false);

}

void Loja::excluirCliente()
{
	int idexcluir; 
	string opcao, idexcluirStr;   
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
		
		do
		{
			
			cout << endl;
			cout << "Digite o ID do cliente que deseja excluir (ou 'sair' para voltar ao Menu Cliente): ";
			cin >> idexcluirStr; 
			cin.ignore(); 
			while (!ehNumero(idexcluirStr)) {
				cout << "Entrada inválida! Digite um número para o ID do cliente: ";
				cin >> idexcluirStr;  
			}
			cout << "________________________________________" << endl;
			if (idexcluirStr == "sair") {
				return;
			}
			idexcluir = stoi(idexcluirStr); 

			//busca pelo ID no vetor clientes
			for (int i = 0; i < totalClientes; i++)
			{
				if (vecCliente[i].getIdCliente() == idexcluir)
				{
					continuar = true;
					cout << "Tem certeza que deseja excluir o cliente com ID " << vecCliente[i].getIdCliente() << endl;
					cin.ignore();
					char resposta = ehSimNao();
					if (opcao == "s") { 
						//remover o cliente do vetor 
						for (int k = i; k < totalClientes - 1; k++)
						{
							vecCliente[k] = vecCliente[k + 1];
						}
						totalClientes--;

						cout << "Cliente com ID " << idexcluir << " excluído com sucesso!" << endl; 
						cout << "-------------------------------------------" << endl;
						
					}
					else if (opcao == "n") {
						continuar = false; 
					}
				}
			}
		} while (!continuar); 
		if (!continuar) {
			cout << "Cliente com ID " << idexcluir << " não encontrado!" << endl; 
		}
		cout << "Deseja excluir outro cliente? " << endl;
		cin.ignore();
		char resposta = ehSimNao(); 
		if (opcao == "s") {
			continuar = false;
		}
		else if (opcao == "n") {
			continuar = true;
		}

	} while (!continuar);

}

void Loja::alterarNome() 
{
	int idAlterar;
	string novoNome, opcao, idAlterarStr;  
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

		do
		{
			cout << endl;
			cout << "Digite o ID do cliente que deseja alterar (ou 'sair' para retornar ao Menu Cliente): ";
			cin >> idAlterarStr; 
			cin.ignore(); 
			while (!ehNumero(idAlterarStr)) {
				cout << "Entrada inválida! Digite um número para o ID do cliente: ";
				cin >> idAlterarStr;  
			}
			cout << "________________________________________" << endl;
			if (idAlterarStr == "sair") {
				return; 
			}
			idAlterar = stoi(idAlterarStr); 

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
		} while (!continuar);

		if (!continuar) { 
			cout << "Cliente com o ID " << idAlterar << " não encontrado!" << endl; 
		}
		
		cout << "----------------------------------------" << endl;
		cout << "Deseja alterar outro cliente? " << endl;
		cin.ignore();
		char resposta = ehSimNao();
		if (opcao == "s") {
			continuar = false; 
		}
		else if (opcao == "n") {
			continuar = true; 
		}

	} while (!continuar); 

}





//produtos

void Loja::stockInicial()
{ 
	vecProduto[0] = Produto(1, "T-Shirt", 150, 8.0, 10.40);
	vecProduto[1] = Produto(2, "Bermuda", 100, 14.0, 18.20);
	vecProduto[2] = Produto(3, "Tênis", 200, 45.0, 58.50);
	vecProduto[3] = Produto(4, "Hoodie", 180, 13.0, 16.90); 

	totalProdutos = 4;

}

void Loja::mostrarStock()
{
	
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                     STOCK                                      " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < totalProdutos; i++) 
	{
		cout << "ID: " << vecProduto[i].getIdProduto() << " | Nome: " << vecProduto[i].getNome() << " | Quantidade: " << vecProduto[i].getQuantidade() << " | Preço: " << fixed << setprecision(2) << vecProduto[i].getPreco() << " | Preço Venda: " << fixed << setprecision(2) << vecProduto[i].getPrecoFinal() << endl; 
		cout << "--------------------------------------------------------------------------------" << endl;
	}
}

void Loja::criarProduto()
{
	int idproduto, quantidade; 
	string nome, quantidadeStr, precoStr;    
	float preco, precofinal;   
	bool continuar = true;

	system("cls");
	
	do
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  
		cout << "----------------------------------" << endl;
		cout << "    ADICIONAR PRODUTO AO STOCK    " << endl;
		cout << "----------------------------------" << endl;
		cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;  
		cout << "Digite o NOME do produto (ou 'sair' para voltar ao Menu Principal): ";   
		getline(cin, nome);
		if (nome == "sair") { 
			return; 
		}
		cout << "----------------------------------" << endl;
		cout << "Digite a QUANTIDADE do produto: ";
		cin >> quantidadeStr; 
		while (!ehNumero(quantidadeStr)) { 
			cout << "Entrada inválida! Digite um número para quantidade: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> quantidadeStr;  
		}
		quantidade = stoi(quantidadeStr); 
		cout << "----------------------------------" << endl;
		cout << "Digite o PREÇO COMPRA do produto: ";
		cin >> precoStr; 
		while (!ehFloat(precoStr)) { 
			cout << "Entrada inválida! Digite o preço de compra: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cin >> precoStr;  
		}
		preco = stof(precoStr); 
		cout << "----------------------------------" << endl;
		precofinal = preco * 1.3;
		idproduto = totalProdutos + 1;  

		cout << endl;
		cout << fixed << setprecision(2);
		cout << "Os dados inseridos estäo corretos? " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "ID: " << idproduto << " | Nome: " << nome << " | Quantidade: " << quantidade << " | Preço Compra: " << preco << " | Preço Venda: " << precofinal << endl;  
		cout << "---------------------------------------------------------------------------------" << endl;
		

		cin.ignore(numeric_limits<streamsize>::max(), '\n');   
		char resposta = ehSimNao(); 
		if (resposta == 'S') {

			Produto novoProduto(idproduto, nome, quantidade, preco, precofinal);
			vecProduto[totalProdutos] = novoProduto;    
			totalProdutos++;  
			mostrarStock(); 
			continuar = false;
		}
		else if (resposta == 'N') {
			system("cls"); 
			continuar = true; 
		}

		cout << "Deseja adicionar outro produto?" << endl;   
		resposta = ehSimNao();
		if (resposta == 'N') { 
			return;
		}
		system("cls");   

	} while (true);

	

} 

void Loja::atualizarProduto()
{
	string idprodutoStr, qtdAtualizarStr; 
	int idproduto, qtdAtualizar, qtdFinal;    
	
	system("cls");
	cout << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                          ATUALIZAR PRODUTO NO STOCK                            " << endl; 
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	mostrarStock(); 

	do
	{
		cout << endl; 
		cout << "Digite o ID do produto que deseja atualizar (ou 'sair' para voltar ao Menu Principal): ";
		cin >> idprodutoStr; 
		if (idprodutoStr == "sair") {
			return; 
		}
		while (!ehNumero(idprodutoStr)) {
			cout << "Entrada inválida! Digite um número para ID do produto: "; 
			cin >> idprodutoStr;   
		}
		idproduto = stoi(idprodutoStr);

		bool continuar = false; 
		for (int i = 0; i < totalProdutos; i++)
		{
			if (vecProduto[i].getIdProduto() == idproduto) {
				cout << "--------------------" << endl;
				cout << "Produto encontrado!" << endl;
				cout << "--------------------" << endl;
				continuar = true; 

				cout << "Qual a quantidade que deseja adicionar ao Stock: ";
				cin >> qtdAtualizarStr; 
				while (!ehNumero(qtdAtualizarStr)) { 
					cout << "Entrada inválida! Digite apenas números para a quantidade: "; 
					cin >> qtdAtualizarStr;   
				}
				qtdAtualizar = stoi(qtdAtualizarStr);  

				//atualizar o stock 
				qtdFinal = vecProduto[i].getQuantidade() + qtdAtualizar;
				vecProduto[i].setQuantidade(qtdFinal); 

				cout << "-------------------------------------" << endl;
				cout << "Produto atualizado: " << endl;
				cout << "Nome: " << vecProduto[i].getNome() << " | Quantidade: " << vecProduto[i].getQuantidade() << endl;
				cout << "-------------------------------------" << endl; 
				break;
			}
			
		}
		if (!continuar) {
			cout << ">>> ID não encontrado! <<<" << endl;
		}    

	} while (true);

	cout << "Deseja atualizar outro produto?" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	char resposta = ehSimNao();
	if (resposta == 'n' || resposta == 'N') {
		return;
	}
	system("cls"); 

}

void Loja::excluirProduto()
{
	string idprodutoStr;
	int idproduto;
	bool continuar = false; 
	
	

	do
	{
		system("cls"); 
		cout << endl; 
		cout << endl; 
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "                            EXCLUIR PRODUTO DO STOCK                            " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
		mostrarStock(); 
		cout << endl;
		cout << "Digite o ID do produto que deseja excluir (ou 'sair' para voltar ao Menu Principal): ";
		cin >> idprodutoStr;   
		if (idprodutoStr == "sair") {  
			return;
		}
		while (!ehNumero(idprodutoStr)) { 
			cout << "Entrada inválida! Digite um número para ID do produto: ";
			cin >> idprodutoStr; 
		}
		idproduto = stoi(idprodutoStr); 

		for (int i = 0; i < totalProdutos; i++)
		{
			continuar = true;
			if (vecProduto[i].getIdProduto() == idproduto) {

				for (int j = i; j < totalProdutos - 1; j++)
				{
					vecProduto[j] = vecProduto[j + 1]; 
					
				}
				cout << "-----------------------------" << endl;
				cout << "Produto excluído com sucesso!" << endl;
				cout << "-----------------------------" << endl;
				totalProdutos--;  
				break; 
			}
			
		}

		if (!continuar) { 
			cout << ">>> ID não encontrado! <<<" << endl; 
		}

		cout << "Deseja excluir outro produto?" << endl; 
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		char resposta = ehSimNao();  
		if (resposta == 'N') {
			return; 
		}
		continuar = false; 


	} while (true);
}
 



//vendas

bool Loja::selecionarProduto(int& idProdBuscar, int& qtdVenda) {
	
	bool prodEncontrado = false;
	string idProdBuscarStr, qtdVendaStr;  
	
	
	system("cls");
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                              REGISTRO DE PRODUTOS                              " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	mostrarStock(); 

	do
	{
		cout << "Digite o ID do produto que deseja registrar (ou 'sair' para voltar ao Menu Principal): ";
		cin >> idProdBuscarStr;
		if (idProdBuscarStr == "sair") {
			return false;
		}
		while (!ehNumero(idProdBuscarStr)) {
			cout << "----------------------------------" << endl;
			cout << "Digite um número válido para o ID do produto: ";
			cin.clear();
			cin >> idProdBuscarStr;
		}
		idProdBuscar = stoi(idProdBuscarStr);

		for (int i = 0; i < totalProdutos; i++)
		{
			if (vecProduto[i].getIdProduto() == idProdBuscar) {
				prodEncontrado = true;

				//verifica quantidade
				cout << "---------------------------------" << endl;
				cout << "Digite a quantidade do produto: ";
				cin >> qtdVendaStr;
				while (!ehNumero(qtdVendaStr)) {
					cout << "Digite um número válido para quantidade: ";
					cin.clear();
					cin >> qtdVendaStr;
				}
				qtdVenda = stoi(qtdVendaStr);
				if (qtdVenda > vecProduto[i].getQuantidade()) {
					cout << "-------------------------------------------------------" << endl;
					cout << "Stock insuficiente! Stock atual do produto: " << vecProduto[i].getQuantidade() << endl;
					cout << "-------------------------------------------------------" << endl;
					break;
				}
				else {
					return true;
				}
			}else {
				cout << "Produto nao existe. Tente novamente..." << endl;
				break;
			}
		}
		
	} while (true);

	return true;
}

void Loja::registrarVenda(int idProdBuscar, int qtdVenda)
{
	



	cout << "Deseja registrar outro produto? ";
	char resposta = ehSimNao();
	if (resposta == 'S') {
		selecionarProduto(idProdBuscar, qtdVenda);
	}
	else {

	}
}


void Loja::efetuarVenda() {

	int idProdBuscar, qtdVenda;

	system("cls");
	cout << "------------------------------" << endl; 
	cout << "          VENDA               " << endl; 
	cout << "------------------------------" << endl;

	if (!selecionarProduto(idProdBuscar, qtdVenda)) {
		cout << "Erro ao selecionar produto!" << endl;
		return; 
	}
	 

}




/*
void Loja::efetuarVenda() 
{
	bool continuar = false, prodEncontrado = false; 
	int qtdVenda, qtdStock, qtdAtual, idProdBuscar, totalVendasSessao = 0;      
	string idprodbuscarStr, qtdvendaStr, opcao, nomeProduto;   
	float iva;   

	system("cls"); 
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                              REGISTRO DE PRODUTOS                              " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	 
	do
	{
		
		mostrarClientes(); 
		mostrarStock();
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "Digite o ID do produto que deseja registrar (ou 'sair' para voltar ao Menu Principal): ";
		cin >> idprodbuscarStr; 
		//verificar
		if (idprodbuscarStr == "sair") { 
			return;
		}
		while (!ehNumero(idprodbuscarStr)) { 
			cout << "----------------------------------" << endl;
			cout << "Digite um número válido para o ID do produto: ";
			cin.clear();
			cin >> idprodbuscarStr;  
		}

		idProdBuscar = stoi(idprodbuscarStr);  

		//buscar o produto
		for (int i = 0; i < totalProdutos; i++)
		{
			if (vecProduto[i].getIdProduto() == idProdBuscar) {

				prodEncontrado = true; 
				qtdStock = vecProduto[i].getQuantidade();

				//quantidade do produto
				do
				{
					cout << endl;
					cout << "--------------------------------" << endl;
					cout << "Digite a quantidade do produto: ";
					cin >> qtdvendaStr;
					if (!ehNumero(qtdvendaStr)) {
						cout << "Digite um número válido para a quantidade!";
						continue; // essa validacao foi preciso fazer diferente e inserir continue, porque estava dando erro de entrada no buffer
					}
					qtdVenda = stoi(qtdvendaStr);
					if (qtdVenda > qtdStock) {
						cout << "Stock insuficiente! Stock atual do produto: " << qtdStock << endl;
						continuar = false;

					}
					else {
						continuar = true;
					}

				} while (!continuar);

				/*
				cout << "Deseja incluir um novo cliente?" << endl;
				char resposta = ehSimNao();
				if (resposta == 'S') {
					criarCliente(); 
					cout << "Cliente com ID " << totalClientes << " adicionado com sucesso!" << endl;
					cout << "-------------------------------------------------------------------------" << endl; 
				}
				else if (resposta == 'N') {
					cout << "Digite o ID do cliente para prosseguir: ";

				}
				 
				continuar = false;   

				float precoUnitario = vecProduto[i].getPrecoFinal(); 
				float precoTotal = qtdVenda * precoUnitario;  
				iva = precoTotal * 0.23;    
				nomeProduto = vecProduto[i].getNome();   
				

				//verificando dados corretos
				cout << endl;
				cout << "-------------------------------------------------------------------------" << endl;
				cout << "Os dados estão corretos? | Produto ID: " << idProdBuscar << " | Nome Produto: " << nomeProduto << " | Quantidade: " << qtdVenda << " | Preço Unitário: " << precoUnitario << " | Preço Total: " << precoTotal << " | IVA: " << iva << endl; 
				cin.ignore();   
				char resposta = ehSimNao();   

				if (resposta == 'S') { 

					//atualiza qtd no stock
					qtdAtual = qtdStock - qtdVenda;
					vecProduto[i].setQuantidade(qtdAtual);  
 

					//armazenar a venda no vetor
					if (totalVendas < 100) {
						    
						vecVenda[totalVendas] = Venda(numFatura, totalClientes, idProdBuscar, nomeProduto, qtdVenda, precoUnitario, precoTotal, iva);  
						totalVendas++; 
						totalVendasSessao++; 
						 
					}
					else {
						totalClientes--; 
						cout << "Erro! Limite de vendas atingido!" << endl;
					} 
				}
				else if (resposta == 'N') {
					totalClientes--;   
					continuar = false;
				}

				cout << endl;
				cout << "--------------------------------------" << endl;
				cout << "Deseja registrar outro produto?" << endl;   
				cin.ignore(); 
				resposta = ehSimNao();

				if (resposta == 'S' || resposta == 's') {
					continuar = false;  
				}
				else if(resposta == 'N' || resposta == 'n') {    
					continuar = true;  
				}


			}	 

		}

		system("cls"); 
		if (!prodEncontrado) {
			cout << endl;
			cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
			cout << "ID não encontrado! Digite novamente..." << endl;
			cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
		}


	} while (!continuar);

	float totCompra = 0.0, pagoCliente, troco, totIva = 0.0;
	string pagoClienteStr;
	continuar = false;
	bool vendaSorteada = sorteio(); 

	cout << endl;
	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "             CHECKOUT             " << endl;
	cout << "----------------------------------" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;

	if (vendaSorteada) {
		cout << "🎉🎊 PARABÉNS! Sua compra foi SORTEADA e é 100% GRATUITA! 🎊🎉" << endl; 
		cout << "----------------------------------------------------------------" << endl;
		totCompra = 0.0;
		totIva = 0.0;
		return;
	}

	cout << endl;
	cout << "          ITENS FATURADOS         " << endl;
	cout << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	//mostra os itens que estao no carrinho para pagamento
	for (int i = totalVendas - totalVendasSessao; i < totalVendas; i++)
	{
		cout << "ID Produto: " << vecVenda[i].getIdProduto() << " | Nome: " << vecVenda[i].getNomeProduto() << " | Quantidade " << vecVenda[i].getQuantidade() << " | Preço Unitário: " << vecVenda[i].getPreco() << " | Preço Total: " << vecVenda[i].getPrecoTotal() << endl;
		cout << "---------------------------------------------------------------------" << endl;
		totCompra = totCompra + vecVenda[i].getPrecoTotal();
		totIva = totIva + vecVenda[i].getIva();
	}
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;
	cout << "            PAGAMENTO             " << endl;
	cout << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;
	float totCompraComIva = totCompra + totIva;
	cout << "Total da Compra C/ IVA: € " << fixed << setprecision(2) << totCompraComIva << endl;
	cout << "----------------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	//efetuar processo de pagamento
	do
	{
		cout << "Digite o valor pago pelo cliente: ";
		cin >> pagoClienteStr;
		if (!ehNumero(pagoClienteStr)) {
			cout << "------------------------" << endl;
			cout << "Digite um valor válido: " << endl;
			cin >> pagoClienteStr;
		}
		pagoCliente = stof(pagoClienteStr);
		//verifica se o valor pago pelo cliente é suficiente
		if (pagoCliente >= totCompraComIva) {
			troco = pagoCliente - totCompraComIva;
			cout << "Troco: " << fixed << setprecision(2) << troco << endl;
			cout << endl;
			continuar = true;
		}
		else {
			troco = totCompraComIva - pagoCliente;
			cout << "Valor pago insuficiente, esta faltando: € " << fixed << setprecision(2) << troco << endl;
			cout << endl;
			continuar = false;
		}


	} while (!continuar);


	//imrpimirfatura
	system("cls");
	cout << endl;
	cout << endl;
	dataHora(); 
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;
	cout << "               FATURA             " << endl;
	cout << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;

	cout << "Número da Fatura: " << numFatura << endl;
	cout << "----------------------------------" << endl;
	cout << "Número Cliente: " << totalClientes << endl;
	cout << "----------------------------------" << endl;
	cout << "Quantidade de Produtos Registrados: " << totalVendas << endl;
	cout << "----------------------------------" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;
	cout << "          ITENS FATURADOS         " << endl;
	cout << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;
	for (int i = totalVendas - totalVendasSessao; i < totalVendas; i++) 
	{
		cout << "ID Produto: " << vecVenda[i].getIdProduto() << " | Nome: " << vecVenda[i].getNomeProduto() << " | Quantidade " << vecVenda[i].getQuantidade() << " | Preço Unitário: " << vecVenda[i].getPreco() << " | Preço Total: " << vecVenda[i].getPrecoTotal() << endl;
		cout << "---------------------------------------------------------------------" << endl;
	}
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;
	cout << "            PAGAMENTO             " << endl;
	cout << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << "----------------------------------" << endl;
	cout << "Total da Compra S/ IVA: € " << fixed << setprecision(2) << totCompra << endl;
	cout << "----------------------------------" << endl;
	cout << "IVA: € " << fixed << setprecision(2) << totIva << endl;
	cout << "----------------------------------" << endl;
	cout << "Total da Compra C/ IVA: € " << fixed << setprecision(2) << totCompraComIva << endl;
	cout << "----------------------------------" << endl;
	cout << "Valor entregue: € " << fixed << setprecision(2) << pagoCliente << endl;
	cout << "----------------------------------" << endl;
	cout << "Troco: € " << fixed << setprecision(2) << troco << endl;
	cout << "__________________________________" << endl;
	cout << endl;
	cout << endl;

	totalClientes++;
	numFatura++;
	cout << "Deseja imprimir a fatura?" << endl;
	cin.ignore();
	char resposta = ehSimNao(); 
	if (resposta == 'S') {
		return;
	}


} 
*/ 





//relatórios

void Loja::relatorioStock()
{
	
	system("cls");
	cout << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                   RELATÓRIO                                    " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	mostrarStock();  
	cout << endl;  
	cout << "Deseja voltar ao Menu Principal? " << endl; 
	char resposta = ehSimNao();
}

void Loja::relatorioVendasProduto() 
{
	float totalFaturado = 0.0, totalIva = 0.0;
	int totalVendasRelatorio = 0; 
	bool prodEncontrado = false;   
	string nomeProdBuscar;   

	do
	{
		system("cls"); 
		cout << endl;
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "                         RELATÓRIO DE VENDAS POR PRODUTO                        " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		mostrarStock();
		cout << "Digite o nome do produto para gerar o relatório de vendas (ou 'sair' para voltar ao Menu Principal): ";
		cin.ignore();
		getline(cin, nomeProdBuscar);
		nomeProdBuscar = removerEspacosExtras(nomeProdBuscar);
		transformarParaMinusculo(nomeProdBuscar); 
		cout << "-------------------------------------------------------------------" << endl;
		if (nomeProdBuscar == "sair") {
			return;
		}
		for (int i = 0; i < totalVendas; i++)
		{
			string nomeProdutoVenda = removerEspacosExtras(vecVenda[i].getNomeProduto());
			transformarParaMinusculo(nomeProdutoVenda);  
			
			if (nomeProdutoVenda == nomeProdBuscar) { 
				prodEncontrado = true;

				int quantVendida = vecVenda[i].getQuantidade();
				float precoUnitario = vecVenda[i].getPreco();
				float precoTotal = vecVenda[i].getPrecoTotal();
				float iva = vecVenda[i].getIva();

				totalVendasRelatorio += quantVendida;
				totalFaturado += precoTotal;
				totalIva += iva;

				cout << "----------------------------------------------------------------------------------------" << endl;
				cout << "Fatura: #" << vecVenda[i].getNumFatura() << " | Quantidade: " << quantVendida << " | Preço Unitário: €" << fixed << setprecision(2) << precoUnitario << " | Preço Total: €" << fixed << setprecision(2) << totalFaturado << " | IVA: €" << fixed << setprecision(2) << totalIva << endl;
				cout << "----------------------------------------------------------------------------------------" << endl;
			}

		}

		if (!prodEncontrado) {
			cout << ">> Produto não encontrado! <<<" << endl;
		}
		else {
			cout << "-------------------------------------------------------------------" << endl;
			cout << "TOTAL VENDIDO: " << totalVendasRelatorio << " unidades" << endl;
			cout << "TOTAL S/IVA: €" << fixed << setprecision(2) << totalFaturado << endl;
			cout << "TOTAL C/IVA: €" << fixed << setprecision(2) << totalFaturado + totalIva << endl; 
			cout << "===================================================================" << endl;
		}

		cout << "Deseja mostrar o relatório de outro produto?" << endl;
		char resposta = ehSimNao();
		if (resposta == 'S') {
			prodEncontrado = false;
		}
		else if (resposta == 'N') {
			return;   
		}

	} while (true);

	

}

void Loja::relatorioTotal()
{
	system("cls"); 
	if (totalVendas == 0) {
		cout << "Nenhuma venda registrada!" << endl;
		return; 
	}


	unordered_map<int, int> vendasPorProduto; //id produto -> quant vendida
	unordered_map<int, float> valorPorCliente; //id cliente -> total gasto

	int produtoMaisVendido = -1, produtoMenosVendido = -1;
	int qtdMaisVendida = 0, qtdMenosVendida = INT_MAX;
	float lucroMaisVendido = 0.0;
	int clienteMaiorGasto = -1;
	float maiorGasto = 0.0;

	for (int i = 0; i < totalVendas; i++)
	{
		int idProduto = vecVenda[i].getIdProduto();
		int idCliente = vecVenda[i].getIdCliente();
		int qtdVendida = vecVenda[i].getQuantidade();
		float precoTotal = vecVenda[i].getPrecoTotal();
		float precoCompra = 0.0;

		vendasPorProduto[idProduto] += qtdVendida;
		valorPorCliente[idCliente] += precoTotal; 

		//achar preco compra produto
		for (int j = 0; j < totalProdutos; j++)
		{
			if (vecProduto[j].getIdProduto() == idProduto) {
				precoCompra = vecProduto[j].getPreco();
				break; 
			}
		}

		//lucro na compra desse produto
		float lucroProduto = (vecVenda[i].getPreco() - precoCompra) * qtdVendida;

		//atualiza o produto mais vendido
		if (vendasPorProduto[idProduto] > qtdMaisVendida) {
			qtdMaisVendida = vendasPorProduto[idProduto];
			produtoMaisVendido = idProduto;
			lucroMaisVendido = lucroProduto;
		}

		//atualiza o produto menos vendido
		if (vendasPorProduto[idProduto] < qtdMenosVendida) {
			qtdMenosVendida = vendasPorProduto[idProduto];
			produtoMenosVendido = idProduto;
		}

		//atualiza cliente que mais comprou em valor
		if (valorPorCliente[idCliente] > maiorGasto) {
			maiorGasto = valorPorCliente[idCliente];
			clienteMaiorGasto = idCliente;  
		}

		cout << endl;
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "                            RELATÓRIO TOTAL DE VENDAS                           " << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
		cout << endl;

		cout << "Produto mais vendido: ";
		for (int j = 0; j < totalProdutos; j++)
		{
			if (vecProduto[j].getIdProduto() == produtoMaisVendido) {
				cout << vecProduto[j].getNome() << " (" << qtdMaisVendida << " unidades)" << endl;
				break;
			}
		}
		cout << endl; 
		cout << "===================================================" << endl;
		cout << "Produto menos vendido: ";
		for (int j = 0; j < totalProdutos; j++)
		{
			if (vecProduto[j].getIdProduto() == qtdMenosVendida) {
				cout << vecProduto[j].getNome() << " (" << qtdMenosVendida << " unidades)" << endl;
				break;
			}
		}

		cout << endl; 
		cout << "===================================================" << endl;
		cout << "Lucro do produto mais vendido: €" << fixed << setprecision(2) << lucroMaisVendido << endl; 
		cout << "===================================================" << endl;
		cout << endl;  
		cout << "Cliente que mais comprou em valor: ";
		for (int j = 0; j < totalClientes; j++)
		{
			if (vecCliente[j].getIdCliente() == clienteMaiorGasto) {
				cout << vecCliente[i].getNome() << " (€" << fixed << setprecision(2) << maiorGasto << endl;
				break; 
			}
		}
		 

	}
	cout << endl;   
	cout << "Deseja voltar ao Menu Principal?" << endl;
	char resposta = ehSimNao();
	if (resposta == 'S') {
		return;
	}

	
}




//efetuarvenda é preciso corrigir a verificacao dos produtos registrados, ao inserir nao, ele continua para o checkout, onde deveria voltar para registrar novamente o produto

//selecionar o produto e verificar stock
//registrar a venda no vetor
//calcular totais e iva
//realizar sorteio 
//processo de pagamento
//imprimir fatura