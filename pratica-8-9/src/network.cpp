//
// Created by IFPE on 15/07/2025.
//

#include "graph.h"

vector<int> overloaded(Graph capacity, Graph traffic) {

    int tamanhoRede = capacity.size();
    vector<int> valoresSobrecarregados;

    for (int i = 0; i < tamanhoRede; i++) {

        int somaCapacidade = 0;
        int somaTrafego = 0;

        auto vizinhos = capacity.neighbors(i);
        for (auto v : vizinhos) {
            somaCapacidade += capacity.weight(i, v);
        }

        for (int j = 0; j < tamanhoRede; j++) {
            auto vizinhosEntrada = traffic.neighbors(j);
            for (auto v : vizinhosEntrada) {
                if (v == i) {
                    somaTrafego += traffic.weight(j, v);
                }
            }
        }

        if (somaTrafego > somaCapacidade) {
            valoresSobrecarregados.push_back(i);
        }
    }

    return valoresSobrecarregados;
}


// int main() {
void network() {
    cout << endl << "*** Testando Network ***" << endl << endl;

    // Grafo de capacidade da rede
    Graph capacity(6);
    capacity.edge(0, 1, 10);
    capacity.edge(0, 2, 5);
    capacity.edge(1, 2, 3);
    capacity.edge(1, 3, 3);
    capacity.edge(2, 4, 3);
    capacity.edge(4, 3, 4);
    capacity.edge(3, 5, 12);
    capacity.edge(5, 4, 8);

    // Grafo de trafego atual da rede
    Graph traffic(6);
    traffic.edge(0, 1, 7);
    traffic.edge(0, 2, 2);
    traffic.edge(1, 2, 4);
    traffic.edge(1, 3, 2);
    traffic.edge(2, 4, 3);
    traffic.edge(4, 3, 4);
    traffic.edge(3, 5, 8);
    traffic.edge(5, 4, 8);

    auto over = overloaded(capacity, traffic);

    cout << "Sobrecarregados: "; // 1 2 4
    for (int i : over) cout << i << " ";
    cout << endl;

}
