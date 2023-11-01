#include "estrutura.h"
//Esta implementação se refere apenas a grafos NÃO-DIRECIONADOS e PONDERADOS

Grafo::Grafo() {
	this->totalVertices = 0;
}

void Grafo::criaGrafoMatriz() {
	int estacoes;
	int origem = 0;
	int destino = 0;
	int peso = 0;
	cout << "Bem vindo ao sistema de criacao do seu GRAFO.:\n";
	cout << "Agora digite o numero de estacoes do GRAFO: \n";
	cin >> estacoes;                                              //É o numero de vetores que são criados dentro do vetor principal
	this->grafo_matriz.resize(estacoes, vector<int>(estacoes, 0)); //Preenche os vetores interno com [n,n] no tamanho da quantia de estacoes
	this->grafo_lista.resize(estacoes, vector<int>());          //contador feito para verificar grau total do grafo
	this->totalVertices = estacoes;
	cout << "GRAFO criado com sucesso.\n";
	cout << "Agora crie as conexões do GRAFO: \n";
	imprimeMatriz();
	for (int i = 0; i <= estacoes; i++) {
		cout << "Crie as conexoes do grafo criado: \n Digite a conexão: " << i + 1 << ", na seguinte sequencia origem, destino e tempo de viagem em minutos.";
		cout << "Controle: o tamanho da matriz do grafo é " << this->grafo_matriz.size() << "\n";
		cin >> origem >> destino >> peso;
		origem = origem - 1;
		destino = destino - 1;
		
		if (origem > this->grafo_matriz.size() || destino > this->grafo_matriz.size() || origem < 0 || destino < 0) {
			cout << "Uma das coordenadas de origem ou destino estão incorretas!\n";
			break;
		}
		else {
			this->grafo_matriz[origem][destino] = peso; //Aqui é adcionado na posição LinhaxColuna o peso da aresta, para que seja impresso corretamente na matriz
			this->grafo_matriz[destino][origem] = peso;

			/*Tratar pontos de looping do grafo*/

			/*Implementa em pares*/
			
			this->grafo_lista[origem].push_back(peso * 60); //Primeiro pushback é SEMPRE o peso (LISTA), pois é a ordem de impressão do modo como foi implementado
			this->grafo_lista[origem].push_back(destino);

			this->grafo_lista[destino].push_back(peso * 60); //Foi multiplicado o peso por 60, porque pode ocorrer uma ambiguidade quanto ao destino e peso na hora da remoção
			this->grafo_lista[destino].push_back(origem);
		}
		cout << "Conexão" << i + 1 << " criada com sucesso\n";
	};


}

void Grafo::criaConexoes() {
	int controle;
	int origem, destino, peso;
	cout << "Edite as conexões do Grafo:\n";
	cin >> controle;                //Quantia de conexoes que se deseja criar
	for (int i = 0; i < controle; i++) {
		cout << "Digite a " << i + 1 << " conexao que deseja adicionar: \n origem, destino e tempo de viagem em minutos, nessa respectiva ordem.\n";
		cin >> origem >> destino >> peso;
		if (origem > this->grafo_matriz.size() || destino > this->grafo_matriz.size()) {
			cout << " Nao e possivel adcionar a conexao, pois a estacao de destino ou origem nao existem." << endl;
			break;
		}
		else {
			this->grafo_matriz[origem][destino] = peso; //Aqui é adcionado na posição LinhaxColuna o peso da aresta, para que seja impresso corretamente na matriz
			this->grafo_matriz[destino][origem] = peso; //Foi implementada dessa forma por ser um grafo NÃO-DIRECIONADO e PONDERADO
			this->grafo_lista[origem].push_back(peso * 60); //Primeiro pushback é SEMPRE o peso (LISTA), pois é a ordem de impressão do modo como foi implementado
			this->grafo_lista[origem].push_back(destino);
			this->grafo_lista[destino].push_back(peso * 60); //Foi multiplicado o peso por 60, porque pode ocorrer uma ambiguidade quanto ao destino e peso na hora da remoção
			this->grafo_lista[destino].push_back(origem);
		}
	}
	cout << "Conexao criada com sucesso!" << endl;
};

void Grafo::criaNovaEstacao() {
	int novaEstacao = this->totalVertices + 1;
	this->grafo_matriz.push_back(vector<int>(novaEstacao, 0)); //Cria um novo vetor dentro do vetor pai, e preenche com 0's
	this->grafo_lista.push_back(vector<int>()); //Cria um novo vetor dentro do vetor pai

	for (int i = 0; i < novaEstacao; i++) {
		grafo_matriz[i].push_back(0);   //Para adcionar os 0's ao vetores ja existentes
	};
	cout << "Uma nova estacao foi criada!! \n";
	this->totalVertices++;
}

void Grafo::removeNovaEstacao(int arco) {
	//exclui o vetor interno da matriz
	this->grafo_matriz.erase(this->grafo_matriz.begin() + arco);

	if (arco == 0) {
		for (int i = 0; i < this->grafo_matriz.size(); i++) {
			this->grafo_matriz[i].erase(this->grafo_matriz[i].begin() + arco);
		};
	}
	else {
		//exclui os elementos que correspondiam ao vetor excluido nos outros vetores
		for (int i = 0; i < arco; i++) {
			this->grafo_matriz[i].erase(this->grafo_matriz[i].begin() + arco);
		}
	}
	//remoção dos destinos e tempo de locomoção dentro dos vetores internos
	for (int i = 0; i < grafo_lista.size(); i++) { //percorre o vetor de vetores
		for (int j = grafo_lista[i].size() - 1; j >= 0; --j) {  //percorre os vetores internos de trás pra frente
			if (grafo_lista[i][j] == arco) {
				grafo_lista[i].erase(grafo_lista[i].begin() + j);   //apaga o valor do destino

				if (j > 0) {
					grafo_lista[i].erase(grafo_lista[i].begin() + j - 1); // o valor do tempo de locomocao (PESO)
				}
			}
		}
	}

	this->totalVertices--;
	this->grafo_lista[arco].clear(); //limpa o vetor escolhido pelo usuario
}


void Grafo::imprimeMatriz() {
	for (int i = 0; i < this->grafo_matriz.size(); i++) {
		for (int j = 0; j < this->grafo_matriz.size(); j++) { //imprime a matriz utilizando um contador para linha e um para coluna da matriz
			cout << this->grafo_matriz[i][j] << " ";
		}
		cout << endl;
	}
}

void Grafo::imprimeLista() {
	int cont2 = 0;// para imprimir o peso primeiro
	int cont3 = 1;// para imprimir o destino em segundo
	for (int i = 0; i < this->grafo_lista.size(); i++) {
		cout << "Estacao " << i << "-> ";
		for (int j = 0; j < this->grafo_lista[i].size() / 2; j++) {
			cout << "{Duracao do trajeto: " << ((grafo_lista[i][cont2]) / 60) << "min. , destino: " << grafo_lista[i][cont3] << "}";
			cont2 += 2;
			cont3 += 2;
		}
		cont2 = 0;
		cont3 = 1;
		cout << endl;
	}
}

int Grafo::getVerticesTotais() { //Funcao que retorna o grau do GRAFO
	return this->totalVertices;
}

void Grafo::buscarEstacao() {
	int temp;
	cout << "Digite a estacao que esta buscando: \n"; cin >> temp; //NAO FOI IMPLEMENTADO AINDA

}