#include "classe_loja.h"

Loja::Loja()
{
	Nome = "";
	IdLoja = 0;
	Morada = "";
}

Loja::Loja(string Nome, int IdLoja, string Morada)
{
	this->Nome = Nome;
	this->IdLoja = IdLoja;
	this->Morada = Morada;
}

string Loja::getNome()
{
	return Nome;
}

int Loja::getIdLoja()
{
	return IdLoja;
}

string Loja::getMorada()
{
	return Morada;
}

void Loja::setNome(string nome)
{
	Nome = nome;
}

void Loja::setIdLoja(int idloja)
{
	IdLoja = idloja;
}

void Loja::setMorada(string morada)
{
	Morada = morada;
}
