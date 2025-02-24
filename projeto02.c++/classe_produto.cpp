#include "classe_produto.h"

Produto::Produto()
{
	Nome = "";
	IdProduto = 0;
	Quantidade = 0;
	Preco = 0.0;
}

Produto::Produto(string Nome, int IdProduto, int Quantidade, float Preco)
{
	this->Nome = Nome;
	this->IdProduto - IdProduto;
	this->Quantidade = Quantidade;
	this->Preco = Preco;
}

string Produto::getNome()
{
	return Nome;
}

int Produto::getIdProduto()
{
	return IdProduto;
}

int Produto::getQuantidade()
{
	return Quantidade;
}

float Produto::getPreco()
{
	return Preco;
}

void Produto::setNome(string nome)
{
	Nome = nome;
}

void Produto::setIdProduto(int idproduto)
{
	IdProduto - idproduto;
}

void Produto::setQuantidade(int quantidade)
{
	Quantidade = quantidade;
}

void Produto::setPreco(float preco)
{
	Preco = preco;
}
