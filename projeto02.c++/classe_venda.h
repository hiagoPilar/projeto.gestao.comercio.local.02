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
	float getPreco();
	float getPrecoTotal();
	float getIva();

	void setNumFatura(int numfatura);
	void setIdCliente(int idcliente);
	void setIdProduto(int idproduto);
	void setQuantidade(int quantidade);
	void setPreco(float preco);
	void setPrecoTotal(float precototal);
	void setIva(float iva); 


};
