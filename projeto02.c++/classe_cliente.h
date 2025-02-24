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