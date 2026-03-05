#include <iostream>
#include <vector>
using namespace std;

class fila_media {
private:
    vector<int> itens;
    // sugestao de atributos; pode/deve haver outros
    int ini = 0, // posicao do 1o elemento
        tam = 0, // tamanho (numero atual de elementos)
        cap = 0; // capacidade (numero max. de elementos)

    long long soma = 0; // soma atual dos elementos (para media O(1))

public:
    // construtor receba capacidade; inicializa cap e o vector itens.
    explicit fila_media(int cap) : cap(cap), itens(cap) { }

    bool cheia() const { return tam == cap; } // fila esta cheia?
    bool vazia() const { return tam == 0; }   // fila esta vazia?

    void desenfileira() { // remove elemento na frente da fila
        if (vazia()) return; // ou poderia lançar erro; aqui só ignora

        soma -= itens[ini];
        ini = (ini + 1) % cap;
        tam--;
    }

    void enfileira(int i) { // adiciona i ao final da fila
        if (cheia()) return; // no main você já garante que não enfileira cheia

        int fim = (ini + tam) % cap;
        itens[fim] = i;
        soma += i;
        tam++;
    }

    int proximo() { // retorna elemento na frente da fila
        if (vazia()) return 0; // (ou lançar erro)
        return itens[ini];
    }

    double media() const { // retorna atual media dos elementos
        if (tam == 0) return 0.0;
        return (double)soma / (double)tam;
    }

    int tamanho() { // retorna tamanho atual da fila
        return tam;
    }
};

int main() {
    int arr[] = {10, 2, 3, 5, 6, 10, 7, 9, 2, 6, 3, 13, 6};
    fila_media fila(4);

    for (int i : arr) {
        if (fila.cheia()) fila.desenfileira();
        fila.enfileira(i);
        cout << fila.media() << endl;
    }

    // Saida: 10 6 5 5 4 6 7 8 7 6 5 6 7
    return 0;
}