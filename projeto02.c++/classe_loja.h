#pragma once
#include<iostream>
#include<string>
#include "classe_cliente.h"
#include "classe_produto.h"
#include "classe_venda.h"
#include <limits> //para limites de tipos de dados
#include <iomanip> //para formatar saidas (setprecision)
#include <ctime> //para data e hora 
#include <algorithm> //para operacoes 
#include <unordered_map> //para tabelas de hash
#include <cstdlib> // para funcoes utilitarias (rand)

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

	//extras
	void dataHora(); 
	bool sorteio(); 

	//cliente
	void clientesIniciais();   
	void mostrarClientes(); 
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
	bool selecionarProduto(int& idProdBsucar, int& qtdVenda);
	void registrarVenda(int idProdBuscar, int qtdVenda, int& qtdVendaSessao); 
	bool calcularTotal(float total, int qtdVendaSessao);   
	void efetuarVenda(); 
	 
	//relatório
	void relatorioStock(); 
	void relatorioVendasProduto(); 
	void relatorioTotal();


	

};