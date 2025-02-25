#pragma once
#include<iostream>
#include<string>
#include "classe_cliente.h"
#include "classe_produto.h"
#include "classe_venda.h"

using namespace std;

class Loja {
private:
	//vetores dinâmicos
	vector<Cliente> vecClientes;
	vector<Produto> vecProdutos;
	vector<Venda> vecVendas;

public:

	Loja(); 


	//cliente
	void criarCliente(int idcliente, string nome, int idade, int telefone, string morada); 
	void excluirCliente(int totalclientes);
	void alterarNome(int totalclientes);
};