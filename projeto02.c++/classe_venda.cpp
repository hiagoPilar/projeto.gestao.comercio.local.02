#include "classe_venda.h"

Venda::Venda()
{
	NumFatura = 0;
	IdCliente = 0;
	IdProduto = 0;
	Quantidade = 0;
	Preco = 0.0;
	PrecoTotal = 0.0;
	Iva = 0.0;
}

Venda::Venda(int NumFatura, int IdCLiente, int IdProduto, int Quantidade, float Preco, float PrecoTotal, float Iva)
{
	this->NumFatura = NumFatura;
	this->IdCliente - IdCLiente;
	this->IdProduto = IdProduto;
	this->Quantidade = Quantidade;
	this->Preco = Preco;
	this->PrecoTotal = PrecoTotal;
	this->Iva = Iva;
}

int Venda::getNumFatura()
{
	return NumFatura;
}

int Venda::getIdCliente()
{
	return IdCliente;
}

int Venda::getIdProduto()
{
	return IdProduto;
}

int Venda::getQuantidade()
{
	return Quantidade;
}

int Venda::getPreco()
{
	return Preco;
}

int Venda::getPrecoTotal()
{
	return PrecoTotal;
}

int Venda::getIva()
{
	return Iva;
}

void Venda::setNumFatura(int numfatura)
{
	NumFatura = numfatura;
}

void Venda::setIdCliente(int idcliente)
{
	IdCliente = idcliente;
}

void Venda::setIdProduto(int idproduto)
{
	IdProduto - idproduto;
}

void Venda::setQuantidade(int quantidade)
{
	Quantidade = quantidade;
}

void Venda::setPreco(int preco)
{
	Preco = preco;
}

void Venda::setPrecoTotal(int precototal)
{
	PrecoTotal = precototal;
}

void Venda::setIva(int iva)
{
	Iva = iva;
}
