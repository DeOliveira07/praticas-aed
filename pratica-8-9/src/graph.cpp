#include <queue>
#include <set>
#include <utility>

#include "graph.h"

// Cria��o da aresta src --> dst
void Graph::edge(int src, int dst, int w) {
	if (src < 0) throw std::runtime_error("Src invalido");
	if (dst < 0) throw std::runtime_error("Dst invalido");
    if (w < 0) throw std::runtime_error("Distancia/peso invalido");
    
    Graph::adj.at(src).push_back(make_pair(dst, w));

}

// Grau de sa�da: src -> dst
int Graph::degree(int src) const {
    if (src < 0 || src >= adj.size()) throw std::runtime_error("Src invalido");
    // TODO
	return Graph::adj.at(src).size();
}

list<int> Graph::neighbors(int src) const {
    if (src < 0 || src >= adj.size()) throw std::runtime_error("Src invalido");
    // TODO
	list<int> neighbors;
	auto listAdj = Graph::adj.at(src);

	for(auto pair : listAdj){
		neighbors.push_back(pair.first);
	}
	
    return neighbors;
}

int Graph::weight(int src, int dst) const {
    if (src < 0 || src >= adj.size()) throw std::runtime_error("Src invalido");
    if (dst < 0 || dst >= adj.size()) throw std::runtime_error("Dst invalido");
    // TODO

	int valueWeight;
	auto listAdj = Graph::adj.at(src);

	for(auto pair : listAdj){
		if(pair.first == dst){
			valueWeight = pair.second;
		}
	}

	return valueWeight;
}

void Graph::print() const {
	for (int i = 0; i < this->size(); i++) {
		int d = this->degree(i);
		cout << i << "(" << d << "): ";
		list<int> nei = this->neighbors(i);
		for (int dst : nei) {
			int w = this->weight(i, dst);
			cout << dst << "[" << w << "]; ";
		}
		cout << endl;
	}
}


bool Graph::isConnected() const {
	// TODO

	int tamanhoArray = Graph::adj.size();
	int vertices[tamanhoArray];

	for(int i = 0; i<tamanhoArray; i++){
		vertices[i] = i;
	}

	for(int i = 0; i < tamanhoArray; i++){
		for(auto j : Graph::adj.at(i)){
			vertices[j.first] = vertices[i];
		}
	}
	int valorCompara = vertices[0];

	for(int x : vertices){
		if(x != valorCompara){
			return false;
		}
	}

	return true;
}

// -------- PRAT 09 --------------//

// Busca em profundidade
list<int> Graph::dfs(int src) {
    if (src < 0 || src >= adj.size())
        throw std::runtime_error("Src invalido");

	list<int> result;
	vector<bool> visited(adj.size(), false);

	DFS(src, visited, result);

	return result;
}

// Busca em profundidade
void Graph::DFS(int src, vector<bool> &visited, list<int> &result) {
	if(visited.at(src)){
		return;
	}
	visited.at(src) = true;

	result.push_back(src);

	auto neighbors = adj.at(src);

	for(auto x : neighbors){
		DFS(x.first, visited, result);
	}
}

// Busca em largura
list<int> Graph::bfs(int src) {
    if (src < 0 || src >= adj.size())
        throw std::runtime_error("Src invalido");

	list<int> result;
    vector<bool> visited(adj.size(), false);

	BFS(src, visited, result);

	return result;
}

// Busca em largura
void Graph::BFS(int src, vector<bool> &visited, list<int> &result) {
	// TODO
	queue<int> searchQueue;
	visited.at(src) = true;
	searchQueue.push(src);
	result.push_back(src);

	while (!(searchQueue.empty())){
		int vtx = searchQueue.front();
		searchQueue.pop();
		auto neighbors = adj.at(vtx);

		for(auto x : neighbors) {
			int neighbor = x.first;
			if(!visited.at(neighbor)){
				visited.at(neighbor) = true;
				result.push_back(neighbor);
				searchQueue.push(neighbor);
			}
		}
	}
}

bool Graph::has_cycle() const {
    for (int i = 0; i < adj.size(); i++) {
        if (has_cycle(i)) return true;
    }
    return false;
}

bool Graph::has_cycle(int src) const {
    if (src < 0 || src >= adj.size())
        throw std::runtime_error("Src invalido");

    vector<bool> visited(adj.size(), false);

    return has_cycle(src, visited);
}

bool Graph::has_cycle(int src, vector<bool> &visited) const {
	// todo

	if(visited.at(src)){
		return true;
	}

	visited.at(src) = true;

	auto neighbors = adj.at(src);

	for(auto x : neighbors){
		if(has_cycle(x.first, visited)) return true;
	}

	visited.at(src) = false;

	return false;
}

bool Graph::reacheable(int src, int dst) const {
    if (src < 0 || src >= adj.size())
        throw std::runtime_error("Src invalido");

    if (dst < 0 || src >= adj.size())
        throw std::runtime_error("Dst invalido");

    // TODO

	if(src == dst) return true;

	vector<bool> visited(adj.size(), false);

	queue<int> searchQueue;

	visited.at(src) = true;
	searchQueue.push(src);

	while (!(searchQueue.empty())){
		int vtx = searchQueue.front();
		searchQueue.pop();

		auto neighbors = adj.at(vtx);

		for(auto x : neighbors) {
			int neighbor = x.first;

			if(neighbor == dst){
				return true;
			}

			if(!visited.at(neighbor)){
				visited.at(neighbor) = true;
				searchQueue.push(neighbor);
			}
		}
	}
	
	return false;
}

void Graph::dijkstra(int src, vector<int> &prev, vector<long> &dist) {
    // TODO Desafio

	set<pair<long, int>> setVTX;
	setVTX.insert({0 , src});

	dist.at(src) = 0;

	while (!(setVTX.empty()))
	{
		auto vtx = *setVTX.begin();
		setVTX.erase(vtx);

		if(vtx.first != dist[vtx.second]) continue;

		auto neighbors = Graph::adj.at(vtx.second);

		for(auto x : neighbors){

			long newDist = dist.at(vtx.second) + x.second;

			if(newDist < dist.at(x.first)){
				dist.at(x.first) = newDist;
				prev.at(x.first) = vtx.second;
				setVTX.insert({newDist, x.first});
			}
		}
	}
}

list<int> Graph::spf(int src, int dst) {
    if (src < 0 || src >= this->size())
        throw std::runtime_error("Src invalido");

    if (dst < 0 || dst >= this->size())
        throw std::runtime_error("Dst invalido");

	vector<int> prev(adj.size(), -1);     // v�rtices anteriores
    vector<long> dist(adj.size(), 99999); // dist�ncias acumuladas; 99999 = INF

    dijkstra(src, prev, dist);

    list<int> result;						    // retorno menor caminho

	path(dst, prev, result);				// extrair caminho em result

	return result;
}


void Graph::path(int src, const vector<int> &prev, list<int> &result) {
	if (src < 0) return;
	path(prev[src], prev, result);
	result.push_back(src);
}

// Para facilitar a exibi??o de listas de v?rtices
ostream & operator <<(ostream &out, const list<int> &l) {
	for (int i : l) out << i << " ";
	return out;
}

void graph() {
	cout << endl << "*** Testando Grafo ***" << endl << endl;

	Graph graph1(6);		// Connected
	graph1.edge(0, 1, 4);
	graph1.edge(0, 2, 2);
	graph1.edge(1, 2, 5);
	graph1.edge(1, 3, 10);
	graph1.edge(2, 4, 3);
	graph1.edge(4, 3, 4);
	graph1.edge(3, 5, 11);
	graph1.edge(5, 1, 11);

	Graph graph2(9);		// Connected
	graph2.edge(0, 1, 4);
	graph2.edge(0, 7, 8);
	graph2.edge(1, 2, 8);
	graph2.edge(1, 7, 11);
	graph2.edge(2, 3, 7);
	graph2.edge(2, 5, 4);
	graph2.edge(2, 8, 2);
	graph2.edge(3, 4, 9);
	graph2.edge(3, 5, 14);
	graph2.edge(4, 5, 10);
	graph2.edge(5, 6, 2);
	graph2.edge(6, 7, 1);
	graph2.edge(6, 8, 6);
	graph2.edge(7, 8, 7);

	Graph graph3(6);		// Not connected
	graph3.edge(0, 1, 12);
	graph3.edge(0, 2, 2);
	graph3.edge(3, 4, 1);
	graph3.edge(4, 5, 10);

	// Pr?tica 08
	cout << "Graph1 is connected? " << (graph1.isConnected()?"YES":"NO") << endl; // YES
	graph1.print();
	cout << endl;

	cout << "Graph2 is connected? " << (graph2.isConnected()?"YES":"NO") << endl; // YES
	graph2.print();
	cout << endl;

	cout << "Graph3 is connected? " << (graph3.isConnected()?"YES":"NO") << endl; // NO
	graph3.print();
	cout << endl;

	// Pratica 09

	cout << endl;

	cout << "Graph1: " << endl;
	cout << "DFS(0): " << graph1.dfs(0) << endl; // 0 1 2 4 3 5
	cout << "BFS(0): " << graph1.bfs(0) << endl; // 0 1 2 3 4 5
	cout << "SPF(0, 5): " << graph1.spf(0, 5) << endl; // 0 2 4 3 5
    cout << "Has cycle: " << (graph1.has_cycle()?"yes":"no") << endl; // yes
    cout << "Reachable(0, 5): " << (graph1.reacheable(0, 5)?"yes":"no") << endl; // yes
    cout << "Reachable(5, 0): " << (graph1.reacheable(5, 0)?"yes":"no") << endl; // no
    cout << endl;

	cout << "Graph2: " << endl;
	cout << "DFS(0): " << graph2.dfs(0) << endl; // 0 1 2 3 4 5 6 7 8
	cout << "BFS(0): " << graph2.bfs(0) << endl; // 0 1 7 2 8 3 5 4 6
	cout << "SPF(0, 5): " << graph2.spf(0, 5) << endl; // 0 1 2 5
    cout << "Has cycle: " << (graph2.has_cycle() ? "yes":"no") << endl; // no
    cout << "Reachable(0, 5): " << (graph2.reacheable(0, 5)?"yes":"no") << endl; // yes
    cout << "Reachable(5, 0): " << (graph2.reacheable(5, 0)?"yes":"no") << endl; // no
    cout << "Reachable(4, 8): " << (graph2.reacheable(4, 8)?"yes":"no") << endl; // yes
    cout << "Reachable(8, 4): " << (graph2.reacheable(8, 4)?"yes":"no") << endl; // no
    cout << endl;

	cout << "Graph3: " << endl;
	cout << "DFS(0): " << graph3.dfs(0) << endl; // 0 1 2
	cout << "BFS(0): " << graph3.bfs(0) << endl; // 0 1 2
	cout << "SPF(0, 5): " << graph3.spf(0, 5) << endl; // 5 ou vazio
    cout << "Has cycle: " << (graph3.has_cycle()?"yes":"no") << endl; // no
    cout << "Reachable(0, 5): " << (graph3.reacheable(0, 5)?"yes":"no") << endl; // no
    cout << "Reachable(3, 5): " << (graph3.reacheable(3, 5)?"yes":"no") << endl; // yes
    cout << "Reachable(1, 2): " << (graph3.reacheable(1, 2)?"yes":"no") << endl; // no
}

