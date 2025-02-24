#pragma once

#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
	string Nome;
	int IdCliente;
	int Idade;
	int Telefone;
	string Morada;

public:

	Cliente();
	Cliente(string Nome, int IdCliente, int Idade, int Telefone, string Morada);

	string getNome();
	int getIdCliente();
	int getIdade();
	int getTelefone();
	string getMorada();

	void setNome(string nome);
	void setIdCliente(int idcliente);
	void setIdade(int idade);
	void setTelefone(int telefone);
	void setMorada(string morada); 

};


class Venda {
private:
	int NumFatura;
	int IdCliente;
	int IdProduto;
	int Quantidade;
	float Preco;
	float PrecoTotal;
	float Iva;

public:

	Venda();
	Venda(int NumFatura, int IdCLiente, int IdProduto, int Quantidade, float Preco, float PrecoTotal, float Iva);

	int getNumFatura();
	int getIdCliente();
	int getIdProduto();
	int getQuantidade();
	int getPreco();
	int getPrecoTotal();
	int getIva();

	void setNumFatura(int numfatura);
	void setIdCliente(int idcliente);
	void setIdProduto(int idproduto);
	void setQuantidade(int quantidade);
	void setPreco(int preco);
	void setPrecoTotal(int precototal);
	void setIva(int iva);


};