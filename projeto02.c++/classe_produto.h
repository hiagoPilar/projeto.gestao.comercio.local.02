#pragma once

#include <iostream>
#include <string>

using namespace std;


class Produto {
private:
	string Nome;
	int IdProduto;
	float Preco, precoFinal;  
	int Quantidade; 


public:

	Produto();
	Produto(int IdProduto, string Nome, int Quantidade, float Preco, float precoFinal);  

	string getNome();
	int getIdProduto();
	int getQuantidade();
	float getPreco();
	float getPrecoFinal(); 

	void setNome(string nome);
	void setIdProduto(int idproduto);
	void setQuantidade(int quantidade);
	void setPreco(float preco);
	void setPrecoFinal(float precoFinal); 

};
