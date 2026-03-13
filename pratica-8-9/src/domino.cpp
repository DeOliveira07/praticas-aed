
#include "graph.h"


Graph montar_grafo(const vector<pair<int, int>> &pecas, int max) {
    Graph grafo(max + 1);

    // pecas s�o bidirecionais
    for (auto [a, b] : pecas) {
        grafo.edge(a, b, 1);
        grafo.edge(b, a, 1);
    }

    return grafo;
}

bool is_euler(const Graph &graph) {
    // TODO
    if(graph.isConnected()){
        vector<int> grausConexao(graph.size());
        int tamanhoGrafico = graph.size();
        int valorImpar = 0;

        for(int i = 0 ; i < tamanhoGrafico; i++){
            grausConexao.at(i) = graph.neighbors(i).size();
        }

        for(auto x : grausConexao){
            if(x & 1) valorImpar++;
        }

        if(valorImpar <= 2) return true;
    }

    return false;
}

// int main() {
void domino() {
    cout << endl << "*** Testando Domino ***" << endl << endl;
    vector<pair<int, int>> pecas1 = {{0,1}, {1,2}, {2,0}, {2,3}, {3,4}, {4,5}, {5,3}};
    vector<pair<int, int>> pecas2 = {{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7}, {7,0}, {0,3}, {5,1}};

    Graph grafo1 = montar_grafo(pecas1, 5);
    Graph grafo2 = montar_grafo(pecas2, 7);

    cout << "Pecas 1: " << (is_euler(grafo1) ? "Sim" : "Não") << endl; // Sim
    cout << "Pecas 2: " << (is_euler(grafo2) ? "Sim" : "Não") << endl; // Nao
}