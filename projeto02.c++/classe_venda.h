#pragma once

#include <iostream>
#include <string>

using namespace std;


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
