#include <vector>
#include <stdexcept>
using namespace std;

//  lista.h + exemplo leetcode

template <class T>
class Lista {
protected:
    int capacidade;
    int num_itens = 0;
    vector<T> itens;

    T & pega_ref(int idx) {
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");
        return itens[idx - 1];
    }

public:
    explicit Lista(int capacidade) : capacidade(capacidade), itens(capacidade) {
        if (capacidade <= 0) throw runtime_error("Capacidade invalida");
    }

    virtual ~Lista() = default;

    virtual void adicionar(T v) {
        if (num_itens >= capacidade) throw runtime_error("Fila cheia!");
        itens[num_itens] = v;
        num_itens++;
    }

    int tamanho() const {
        return num_itens;
    }

    T pega(int idx) {
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");
        return itens[idx - 1];
    }

    T & operator [] (int idx) {
        return pega_ref(idx);
    }

    virtual int buscar(T valor) {
        for (int i = 0; i < num_itens; i++) {
            if (itens[i] == valor) return i + 1;
        }
        return -1;
    }
};

template <class T>
class ListaOrdenada : public Lista<T> {
public:
    explicit ListaOrdenada(int cap) : Lista<T>(cap) {}

    void adicionar(T v) override {
        if (this->num_itens >= this->capacidade) throw runtime_error("Fila cheia!");

        int i = 0;
        for (i = this->num_itens - 1; i >= 0 && this->itens[i] > v; i--) {
            this->itens[i + 1] = this->itens[i];
        }
        this->itens[i + 1] = v;
        this->num_itens++;
    }

    int buscar(T v) override {
        int l = 0, r = this->num_itens - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (this->itens[mid] == v) return mid + 1;
            if (this->itens[mid] < v) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};


class KthLargest {
private:
    int k;
    ListaOrdenada<int> lista;

public:
    KthLargest(int k, vector<int>& nums)
        : k(k),
          lista((int)nums.size() + 10005) {

        for (int x : nums) {
            lista.adicionar(x);
        }
    }

    int add(int val) {
        lista.adicionar(val);
        int idx = lista.tamanho() - k + 1;
        return lista.pega(idx);
    }
};