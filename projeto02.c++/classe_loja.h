#pragma once
#include<iostream>
#include<string>
#include "classe_cliente.h"
#include "classe_produto.h";

using namespace std;

class Loja {
private:
	string Nome;
	int IdLoja;
	string Morada;
	Cliente cliente[100];
	Produto produtos[100];

public:

	Loja();
	Loja(string Nome, int IdLoja, string Morada);

	string getNome();
	int getIdLoja();
	string getMorada();

	void setNome(string nome);
	void setIdLoja(int idloja);
	void setMorada(string morada); 

};