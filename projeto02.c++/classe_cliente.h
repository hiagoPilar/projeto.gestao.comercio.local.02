#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cliente {
private:
	int IdCliente; 
	string Nome;
	int Idade;
	int Telefone;
	string Morada; 

public:

	Cliente();
	Cliente(int IdCliente, string Nome, int Idade, int Telefone, string Morada); 

	string getNome();
	int getIdade();
	int getTelefone();
	string getMorada();
	int getIdCliente();

	void setNome(string nome);
	void setIdade(int idade);
	void setTelefone(int telefone);
	void setMorada(string morada);  
	void setIdCliente(int idcliente); 

}; 