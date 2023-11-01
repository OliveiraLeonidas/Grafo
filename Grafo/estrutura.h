#include <iostream>
#include <vector>
using namespace std;

#ifndef GRAFO_h
#define GRAFO_h


class Grafo { //Sistema Metroviario é basicamente uma classe, com um vetor de vetores.
private:
	vector<vector<int>> grafo_matriz;
	vector<vector<int>> grafo_lista;
	vector<pair<int, int>> listaPares;
	int totalVertices;

public:
	void tem_conexao(int v1, int v2);

	/* para criar a matriz-grafo dinamicamente vertices/arestas/peso */
	Grafo();
	int getVerticesTotais();
	void criaGrafoMatriz();
	void criaConexoes();
	void criaNovaEstacao();
	void buscarEstacao();
	void removeNovaEstacao(int arco);
	void imprimeMatriz();
	void imprimeLista();
};


#endif //end class grafo