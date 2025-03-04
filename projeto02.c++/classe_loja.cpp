#include "classe_loja.h"
#include "classe_cliente.h"


Loja::Loja(int capacidade) 
{
	this->capacidade = capacidade; 
	this->totalClientes = 0;    
	this->totalProdutos = 0;
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
		getline(cin, opcao);

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
	
	cout << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                                     STOCK                                      " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << totalProdutos; 
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
 




//venda

void Loja::registrarProdutos()
{
	bool continuar = false;
	int qtdVenda, qtdStock, qtdAtual, idProdBuscar;   
	string idprodbuscarStr, qtdvendaStr, opcao;
	bool prodEncontrado = false;

	system("cls"); 
	cout << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                              REGISTRO DE PRODUTOS                              " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	 
	do
	{
		
		mostrarStock();
		cout << endl;
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "Digite o ID do produto que deseja registrar (ou 'sair' para voltar ao Menu Principal): ";
		cin >> idprodbuscarStr;
		//verificar
		if (idprodbuscarStr == "sair") {
			return;
		}
		while (!ehNumero(idprodbuscarStr)) {
			cout << "----------------------------------" << endl;
			cout << "Digite um número válido para o ID: ";
			cin.clear();
			cin >> idprodbuscarStr;
		}

		idProdBuscar = stoi(idprodbuscarStr);

		
		for (int i = 0; i < totalProdutos; i++)
		{
			if (vecProduto[i].getIdProduto() == idProdBuscar) {


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

				
				continuar = false;   
				//verificando dados corretos
				cout << endl;
				cout << "-------------------------------------------------------------------------" << endl;
				cout << "Os dados estão corretos? ID: " << idProdBuscar << " | Nome: " << vecProduto[i].getNome() << " | Quantidade: " << qtdVenda  << " | Preço: " << vecProduto[i].getPrecoFinal() << endl;   
				cin.ignore();   
				char resposta = ehSimNao(); 

				if (opcao == "S" || opcao == "s") {

					//atualiza qtd no stock
					qtdAtual = qtdStock - qtdVenda;
					vecProduto[i].setQuantidade(qtdAtual); 

					//armazenar a venda na matriz
					if (linhaMatriz < 100) {
						matrizVenda[linhaMatriz][0] = idProdBuscar;
						matrizVenda[linhaMatriz][1] = qtdVenda;
						matrizVenda[linhaMatriz][2] = vecProduto[i].getPrecoFinal() * qtdVenda; 
						vecNomeProduto[linhaMatriz] = vecProduto[i].getNome();
						linhaMatriz++;
					}
					else {
						cout << "Erro! Limite de vendas atingido!" << endl;
					} 
				}
				else if (opcao == "N" || opcao == "n") {
					continuar = false;
				}

				cout << endl;
				cout << "--------------------------------------" << endl;
				cout << "Deseja registrar outro produto?" << endl;
				cin.ignore(); 
				resposta = ehSimNao();

				if (opcao == "S" || opcao == "s") {
					continuar = false;
				}
				else if(opcao == "N" || opcao == "n") {
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

}

void Loja::checkout()
{
	int numCliente = 0, numFatura = 0; 
	float totCompra = 0 , totCompraIva, pagoCliente, troco, iva = 1.07; 
	string pagoClienteStr, opcao;  
	bool continuar = false;

	cout << endl;
	cout << endl;
	cout << "----------------------------------" << endl;
	cout << "             CHECKOUT             " << endl;
	cout << "----------------------------------" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;
	cout << "          ITENS FATURADOS         " << endl; 
	cout << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl; 
	//mostra os itens que estao no carrinho para pagamento
	for (int i = 0; i < linhaMatriz; i++)
	{
		cout << "ID Produto: " << matrizVenda[i][0] << " | Nome: " << vecNomeProduto[i] << " | Quantidade " << matrizVenda[i][1] << " | Preço: " << matrizVenda[i][2] << endl;
		cout << "---------------------------------------------------------------------" << endl;  
		totCompra = totCompra + matrizVenda[i][2]; 
	}
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;
	cout << "            PAGAMENTO             " << endl;
	cout << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;
	totCompraIva = totCompra * iva;
	cout << "Total da Compra C/ IVA: € " << fixed << setprecision(2) << totCompraIva << endl;  
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
		if (pagoCliente >= totCompraIva) { 
			troco = pagoCliente - totCompraIva; 
			cout << "Troco: " << fixed << setprecision(2) << troco << endl;  
			cout << endl; 
			continuar = true; 
		}
		else {
			troco = totCompraIva - pagoCliente; 
			cout << "Valor pago insuficiente, esta faltando: € " << fixed << setprecision(2) << troco << endl; 
			cout << endl;  
			continuar = false; 
		}


	} while (!continuar);
	numCliente++;
	numFatura++;
	
	//imrpimirfatura
	system("cls"); 
	cout << endl;
	cout << endl;
	cout << "Data: " << endl; 
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;
	cout << "               FATURA             " << endl;
	cout << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;

	cout << "Número da Fatura: " << numFatura << endl;
	cout << "----------------------------------" << endl;
	cout << "Número Cliente: " << numCliente << endl;
	cout << "----------------------------------" << endl; 
	cout << "Quantidade de Produtos Registrados: " << linhaMatriz << endl;
	cout << "----------------------------------" << endl; 
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;
	cout << "          ITENS FATURADOS         " << endl;
	cout << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl; 
	for (int i = 0; i < linhaMatriz; i++)
	{
		cout << "ID Produto: " << matrizVenda[i][0] << " | Nome: " << vecNomeProduto[i] << " | Quantidade " << matrizVenda[i][1] << " | Preço: " << matrizVenda[i][2] << endl;  
	}
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl; 
	cout << endl;
	cout << "            PAGAMENTO             " << endl; 
	cout << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl; 
	cout << "----------------------------------" << endl;
	cout << "Total da Compra S/ IVA: € " << fixed << setprecision(2) << totCompra << endl;
	cout << "----------------------------------" << endl;
	totCompraIva = totCompra * iva;
	cout << "IVA: € " << fixed << setprecision(2) << totCompraIva - totCompra << endl; 
	cout << "----------------------------------" << endl;
	cout << "Total da Compra C/ IVA: € " << fixed << setprecision(2) << totCompraIva << endl; 
	cout << "----------------------------------" << endl;
	cout << "Valor entregue: € " << fixed << setprecision(2) << pagoCliente << endl; 
	cout << "----------------------------------" << endl;
	cout << "Troco: € " << fixed << setprecision(2) << troco << endl; 
	cout << "__________________________________" << endl;
	cout << endl;
	cout << endl;  
	cout << "Deseja imprimir a fatura?" << endl;
	cin.ignore();    
	char resposta = ehSimNao();
	if (opcao == "S" || opcao == "s") {
		return;
	} 
		

}

void Loja::efetuarVenda() 
{
	registrarProdutos();  
	system("cls"); 
	checkout(); 
}
