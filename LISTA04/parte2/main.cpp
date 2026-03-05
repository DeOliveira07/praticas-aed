#include <iostream>
#include <vector>
#include <string>

#include "lista.h"

using namespace std;

struct tarefa {
    string nome;
    bool feita = false;

    bool operator < (const tarefa &t) const { return this->nome < t.nome; }
    bool operator > (const tarefa &t) const { return this->nome > t.nome; }
    bool operator ==(const tarefa &t) const { return this->nome == t.nome; }
};

struct compras {
    string nome;
    int quantidade = 0;
    float preco = 0.0f;

    // Comparar SOMENTE pelo nome (para ordenação e busca binária)
    bool operator < (const compras &c) const { return this->nome < c.nome; }
    bool operator > (const compras &c) const { return this->nome > c.nome; }
    bool operator ==(const compras &c) const { return this->nome == c.nome; }
};

int main() {
    cout << " === Testando Lista Simples ==== " << endl << endl;

    vector<int> valores = {11, 4, 7, 9, 10};

    cout << "Lista Simples: " << endl;

    Lista<int> lista(10);

    for (auto &v : valores) {
        lista.adicionar(v);
    }

    cout << "Antes: " << endl;
    for (int i = 1; i <= lista.tamanho(); i++) {
        cout << " " << i << ": " << lista.pega(i) << endl;
    }
    cout << endl;

    lista[5] = 55;
    lista.inserir(2, 22);
    lista.remover(3);
    lista.adicionar(77);
    lista.remover(4);

    cout << "Depois: " << endl;
    for (int i = 1; i <= lista.tamanho(); i++) {
        cout << " " << i << ": " << lista.pega(i) << endl;
    }
    cout << endl;

    vector<int> b = {10, 22, 11, 5, 7};
    cout << "Buscas (sequencial): " << endl;
    for (int v : b) {
        cout << "- Buscando " << v << ": " << lista.buscar(v) << endl;
    }

    cout << endl << " === Testando Lista Ordenada ==== " << endl;

    cout << endl << "Lista Ordenada (int): " << endl;

    ListaOrdenada<int> listaOrd(10);

    for (auto &v : valores) {
        listaOrd.adicionar(v);
    }

    for (int i = 1; i <= listaOrd.tamanho(); i++) {
        cout << i << ": " << listaOrd.pega(i) << "; ";
    }
    cout << endl;

    cout << "Buscas (binaria): " << endl;
    for (int v : b) {
        cout << "- Buscando " << v << ": " << listaOrd.buscar(v) << endl;
    }

    cout << endl << "Lista Ordenada de Tarefas: " << endl;

    ListaOrdenada<tarefa> todo(10);

    vector<tarefa> arr = {
        {"Feira", false},
        {"Aluguel", false},
        {"Lixo", false},
        {"Estudar", false},
        {"Cinema", false}
    };

    for (auto &v : arr) {
        todo.adicionar(v);
    }

    todo[1].feita = true;
    todo[3].feita = true;

    for (int i = 1; i <= todo.tamanho(); i++) {
        cout << i << ": " << todo[i].nome << " ["
             << (todo[i].feita ? "feita" : "nao feita") << "]" << endl;
    }

    vector<string> str = {"Feira", "Tarefa de casa", "Cinema", "Padaria"};
    cout << "Buscas (binaria): " << endl;
    for (string &s : str) {
        cout << "- Buscando " << s << ": " << todo.buscar({s, false}) << endl;
    }

    cout << endl << " === Lista de Compras (Lista ORDENADA) === " << endl;

    // Agora é ListaOrdenada
    ListaOrdenada<compras> listaCompras(10);

    // Adicionando itens (já entra ordenado por nome)
    listaCompras.adicionar({"Arroz", 2, 25.90f});
    listaCompras.adicionar({"Feijao", 3, 9.50f});
    listaCompras.adicionar({"Leite", 6, 4.80f});
    listaCompras.adicionar({"Cafe", 1, 18.00f});

    cout << "Conteudo: " << endl;
    for (int i = 1; i <= listaCompras.tamanho(); i++) {
        compras c = listaCompras[i];
        cout << i << ": " << c.nome
             << " (qtd=" << c.quantidade
             << ", preco=" << c.preco << ")" << endl;
    }
    cout << endl;

    // Inserir() não existe na ordenada; para "inserções", você usa adicionar()
    listaCompras.adicionar({"Acucar", 1, 6.75f});
    listaCompras.adicionar({"Oleo", 2, 7.90f});

    // Remoção: pode remover por posição
    // Ex: remover o item "Cafe" (busca por nome e remove a posição encontrada)
    int posCafe = listaCompras.buscar({"Cafe", 0, 0.0f});
    if (posCafe != -1) listaCompras.remover(posCafe);

    cout << "Depois: " << endl;
    for (int i = 1; i <= listaCompras.tamanho(); i++) {
        compras c = listaCompras[i];
        cout << i << ": " << c.nome
             << " (qtd=" << c.quantidade
             << ", preco=" << c.preco << ")" << endl;
    }
    cout << endl;

    // Buscas (binária) por nome
    vector<string> buscaCompras = {"Leite", "Arroz", "Pao", "Cafe"};
    cout << "Buscas (binaria): " << endl;
    for (string &nome : buscaCompras) {
        cout << "- Buscando " << nome << ": "
             << listaCompras.buscar({nome, 0, 0.0f}) << endl;
    }

    return 0;
}