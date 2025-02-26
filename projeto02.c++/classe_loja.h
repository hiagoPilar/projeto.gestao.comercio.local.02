#pragma once
#include<iostream>
#include<string>
#include "classe_cliente.h"
#include "classe_produto.h"
#include "classe_venda.h"

using namespace std;

class Loja {
private:
	
	Produto vecProduto[100];
	Venda vecVenda[100];
	Cliente vecCliente[100];
	int capacidade;
	int totalClientes;

public:

	Loja(int capacidade = 100);  
	

	//cliente
	void clientesIniciais();  
	void criarCliente(); 
	void excluirCliente();
	void alterarNome();
};