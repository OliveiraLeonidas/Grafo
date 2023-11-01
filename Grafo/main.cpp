#include <iostream>
#include "menu.h"
#include "estrutura.h"

using namespace std;

int main()
{
	Grafo matriz;
	int opcaoMenu, opcaoMenuImprime;

	do {             
		cout << "GRAFO NAO DIRECIONADO E PONDERADO\n";
		cout << "\nBem vindo ao menu de sistemas metroviarios: \n";

		cout << "\n1. Criar Sistema metroviario inicial: \n";
		cout << "2. Criar uma conexao entre as estacoes: \n";
		cout << "3. Adicionar estacao: \n";
		cout << "4. Remover estacao: \n";
		cout << "5. Encontrar caminho determinado entre estacoes estacoes e o tempo entre elas: \n";
		cout << "6. Encontrar o menor caminho entre estacoes e seu tempo: \n";
		cout << "7. Imprimir sistema criado: \n";
		cout << "0. Para sair do sistema: \n";
		cout << "\nDigite a sua opcao: ";
		cin >> opcaoMenu;

		switch (opcaoMenu) {

		case 0:
			cout << "\nPrograma finalizado! \n";
			break;

		case 1:
			matriz.criaGrafoMatriz();
			cout << "\n";
			break;

		case 2:
			matriz.criaConexoes();
			cout << "\n";
			break;

		case 3:

			matriz.criaNovaEstacao();
			cout << "\n";
			break;

		case 4:
			int aux;
			cout << "\nInsira o numero da estacao que deseja remover: ";
			cin >> aux;
			matriz.removeNovaEstacao(aux); // aux corresponde ao arco na funcao
			cout << "\nA estacao " << aux << " foi removida do sistema." << endl;
			break;

		case 5:
			cout << "Opcao nao implementada, volte depois\n";
			break;

		case 6:
			cout << "Opcao nao implementada, volte depois\n";
			break;

		case 7:
			do {
				cout << "\n\n\nVoce pode imprimir o sistema atual em lista ou em matriz.\n";
				cout << "1 - Imprimir a Matriz :\n";
				cout << "2 - Imprimir a Lista :\n";
				cout << "0 - Retonar ao menu principal :\n";
				cout << "\nDigite a sua opcao: ";
				cin >> opcaoMenuImprime;

				switch (opcaoMenuImprime) {
				case 1:
					matriz.imprimeMatriz();
					break;
				case 2:
					matriz.imprimeLista();
					break;
				case 0:
					cout << "\n";
					break;

				default:
					cout << "\nOpcao invalida\n";
					break;
				}
			} while (opcaoMenuImprime != 0);

		default:
			cout << "\nOpcao invalida\n";
			break;
		}

	} while (opcaoMenu != 0);
}