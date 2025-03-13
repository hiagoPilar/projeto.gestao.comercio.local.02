
#include <iostream>
#include<locale>
#include "functions.cpp"
#include "classe_venda.h"
#include "classe_produto.h"
#include "classe_loja.h"
#include "classe_cliente.h"

void menuStock(Loja& loja) {

	int sel2;
	do
	{
		system("cls"); 
		cout << "______________________________________" << endl;
		cout << "               MENU STOCK             " << endl;
		cout << "______________________________________" << endl;
		cout << "Selecione a opcao para continuar: "     << endl;
		cout << "______________________________________" << endl;
		cout << "        1 - Criação de Produto        " << endl;
		cout << "     2 - Atualizar Produto Existente  " << endl;
		cout << "          3 - Excluir Produto         " << endl;
		cout << "              4 - Voltar              " << endl;
		cout << "______________________________________" << endl;
		cin >> sel2;
		switch (sel2)
		{
		case 1:
			loja.criarProduto();  
			break;
		case 2:
			loja.atualizarProduto(); 
			break;
		case 3:
			loja.excluirProduto(); 
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
		system("cls"); 
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
			loja.relatorioStock(); 
			break;
		case 2:
			loja.relatorioVendasProduto();  
			break;
		case 3:
			loja.relatorioTotal(); 
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
		system("cls");  
		cout << "______________________________________" << endl;
		cout << "             MENU CLIENTE             " << endl;
		cout << "______________________________________" << endl;
		cout << "  Selecione a opcao para continuar: "   << endl;
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
			loja.criarCliente();   
			break;
		case 2:
			loja.excluirCliente();   
			break;
		case 3:
			loja.alterarNome(); 
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
		system("cls"); 
		cout << "______________________________________" << endl;
		cout << "           MENU PRINCIPAL             " << endl;
		cout << "______________________________________" << endl;
		cout << "Selecione a opcao para continuar: "     << endl;
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
			loja.efetuarVenda();     
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


int main()  
{
    setlocale(LC_ALL, "portuguese");   

    Loja loja;  
    
    menuPrincipal(loja);  
    return 0; 
}
