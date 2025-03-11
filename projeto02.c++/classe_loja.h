#pragma once
#include<iostream>
#include<string>
#include "classe_cliente.h"
#include "classe_produto.h"
#include "classe_venda.h"
#include <limits> 
#include <iomanip> 
#include <ctime> 
#include <algorithm>



using namespace std;

class Loja {
private:
	Produto vecProduto[100];
	Venda vecVenda[100];
	Cliente vecCliente[100];
	int totalClientes, totalProdutos, totalVendas, numFatura;        


public:

	Loja(int capacidade = 100);  
	
	//verificações
	bool ehNumero(string& str); 
	bool ehTexto(const string& str); 
	bool ehFloat(const string& str); 
	char ehSimNao(); 
	string removerEspacosExtras(string str);   
	void transformarParaMinusculo(string& str);  


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
	void excluirProduto();
	
	//venda
	void efetuarVenda();  

	//relatório
	void relatorioStock(); 
	void relatorioVendasProduto();       


	

};