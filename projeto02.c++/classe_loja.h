#pragma once
#include<iostream>
#include<string>
#include "classe_cliente.h"
#include "classe_produto.h"
#include "classe_venda.h"
#include <limits> 
#include <iomanip> 


using namespace std;

class Loja {
private:
	
	Produto vecProduto[100];
	Venda vecVenda[100];
	Cliente vecCliente[100];
	int capacidade, totalClientes, totalProdutos, linhaMatriz;   
	float matrizVenda[100][3];  //armazena dados no registro de produtos para chamar no talao
	string vecNomeProduto[100]; //armazena nome do prod para chamar no talao
	


public:

	Loja(int capacidade = 100);  
	
	//verificações
	bool ehNumero(string& str); 
	bool ehTexto(const string& str); 
	bool ehFloat(const string& str); 
	char ehSimNao(); 


	//cliente
	void clientesIniciais();  
	void criarCliente(); 
	void excluirCliente();
	void alterarNome();

	//produto
	void stockInicial();
	void mostrarStock();
	void criarProduto();
	void atualizarProduto(); 
	/*void excluirProduto();
	*/  

	
	//venda
	void registrarProdutos(); 
	void checkout();
	void efetuarVenda();

	

};