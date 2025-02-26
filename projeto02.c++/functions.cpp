/*#include <iostream>
#include <string>
#include "classe_venda.h"
#include "classe_produto.h"
#include "classe_loja.h"
#include "classe_cliente.h" 

using namespace std;

void menuStock(Loja& loja) {

	int sel2;
	do
	{
		cout << "______________________________________" << endl;
		cout << "               MENU STOCK             " << endl;
		cout << "______________________________________" << endl;
		cout << "Selecione a opcao para continuar: " << endl;
		cout << "______________________________________" << endl;
		cout << "        1 - Criação de Produto        " << endl;
		cout << "     2 - Adicionar Produto Existente  " << endl;
		cout << "          3 - Excluir Produto         " << endl;
		cout << "              4 - Voltar              " << endl;
		cout << "______________________________________" << endl;
		cin >> sel2;
		switch (sel2)
		{
		case 1:
			//criacao produto
			break;
		case 2:
			//add produto existente
			break;
		case 3:
			//exlcuir produto
			break;
		case 4:
			cout << "Saindo..." << endl;
			break;
		default:
			cout << "Opcao invalida!" << endl;
			break;
		}
	} while (sel2 != 4);

}

void menuRelatorio(Loja& loja) {

	int sel3;
	do
	{
		cout << "______________________________________" << endl;
		cout << "           MENU RELATÓRIO             " << endl;
		cout << "______________________________________" << endl;
		cout << "Selecione a opcao para continuar: " << endl;
		cout << "______________________________________" << endl;
		cout << "         1 - Relatório Stock          " << endl;
		cout << " 2 - Relatório de Vendas por Produto  " << endl;
		cout << "    3 - Relatório Total de Vendas     " << endl;
		cout << "              4 - Voltar              " << endl;
		cout << "______________________________________" << endl;
		cin >> sel3;
		switch (sel3)
		{
		case 1:
			//relatorio stock
			break;
		case 2:
			//vendas por produto
			break;
		case 3:
			//total vendas
			break;
		case 4:
			cout << "Saindo..." << endl;
			break;
		default:
			cout << "Opcao invalida!" << endl;
			break;
		}
	} while (sel3 != 4);
}

void menuCLiente(Loja& loja) {

	int sel4;
	do
	{
		cout << "______________________________________" << endl;
		cout << "             MENU CLIENTE             " << endl;
		cout << "______________________________________" << endl;
		cout << "  Selecione a opcao para continuar: " << endl;
		cout << "______________________________________" << endl;
		cout << "           1 - Criar Cliente          " << endl;
		cout << "           2 - Excluir Cliente        " << endl;
		cout << "           3 - Editar CLiente         " << endl;
		cout << "           4 - Voltar                 " << endl;
		cout << "______________________________________" << endl;
		cin >> sel4;
		switch (sel4)
		{
		case 1:

			break;
		case 2:
			//excluir cliente
			break;
		case 3:
			//editar cliente
			break;
		case 4:
			cout << "Saindo..." << endl;
			break;
		default:
			cout << "Opcao invalida!" << endl;
			break;
		}
	} while (sel4 != 4);
}

void menuPrincipal(Loja& loja) {


	int sel1;
	do
	{
		cout << "______________________________________" << endl;
		cout << "           MENU PRINCIPAL             " << endl;
		cout << "______________________________________" << endl;
		cout << "Selecione a opcao para continuar: " << endl;
		cout << "______________________________________" << endl;
		cout << "             1 - Vendas               " << endl;
		cout << "             2 - Stock                " << endl;
		cout << "             3 - Relatorio            " << endl;
		cout << "             4 - Cliente              " << endl;
		cout << "             5 - Sair                 " << endl;
		cout << "______________________________________" << endl;
		cin >> sel1;
		switch (sel1)
		{
		case 1:
			//efetuarVenda();   
			break;
		case 2:
			menuStock(loja);
			break;
		case 3:
			menuRelatorio(loja);
			break;
		case 4:
			menuCLiente(loja);
			break;
		case 5:
			cout << "Saindo..." << endl;
			break;
		default:
			cout << "Opcao invalida!" << endl;
			break;
		}


	} while (sel1 != 5);
}

void efetuarVenda() {

	//criar sistema de checkout
	//1 - ler produtos e suas quantidades (verificar se produto existe e se tem stock dele)
	//2 - mostrar resumo da compra e informar valor total para o cliente
	//3 - fazer o troco
	//4 - imprimmir talao total com todos so dados da compra e com valor do troco
}

*/ 