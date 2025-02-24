#include "classe_cliente.h"

Cliente::Cliente()
{
	Nome = "";
	IdCliente = 0;
	Idade = 0;
	Telefone = 0;
	Morada = "";
}

Cliente::Cliente(string Nome, int IdCliente, int Idade, int Telefone, string Morada)
{
	this->Nome = Nome;
	this->IdCliente = IdCliente;
	this->Idade = Idade; 
	this->Telefone = Telefone; 
	this->Morada = Morada; 
}

string Cliente::getNome()
{
	return Nome;
}

int Cliente::getIdCliente()
{
	return IdCliente;
}

int Cliente::getIdade()
{
	return Idade;
}

int Cliente::getTelefone()
{
	return Telefone;
}

string Cliente::getMorada()
{
	return Morada;
}

void Cliente::setNome(string nome)
{
	Nome = nome;
}

void Cliente::setIdCliente(int idcliente)
{
	IdCliente = idcliente;
}

void Cliente::setIdade(int idade)
{
	Idade = idade;
}

void Cliente::setTelefone(int telefone)
{
	Telefone = telefone;
}

void Cliente::setMorada(string morada)
{
	Morada = morada;
}


