#pragma once

#include <iostream>
#include <string>

using namespace std;


class Produto {
private:
	string Nome;
	int IdProduto;
	float Preco;
	int Quantidade;

public:

	Produto();
	Produto(string Nome, int IdProduto, int Quantidade, float Preco);

	string getNome();
	int getIdProduto();
	int getQuantidade();
	float getPreco();

	void setNome(string nome);
	void setIdProduto(int idproduto);
	void setQuantidade(int quantidade);
	void setPreco(float preco);

};
