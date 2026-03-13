#ifndef PRATICA_06_FULL_HASHTABLE_H
#define PRATICA_06_FULL_HASHTABLE_H

#include <vector>
#include <utility>
#include "hashtable.h"
#include "linkedlist.h"

using namespace std;

/* Tabela de Espalhamento como vector de listas encadeadas.
 * As listas lidam com colisoes  */
template<class T_key, class T_value>
class full_hashtable : hashtable<T_key, T_value> {
private:
    vector<linkedlist<pair<T_key, T_value>>> table;

    T_value not_found;

public:
    explicit full_hashtable(int cap, T_value not_found) : hashtable<T_key, T_value>(cap), table(cap), not_found(not_found) {
    }

    ~full_hashtable() override = default;

    // Se um valor com essa chave já existir, substituir
    void insert(T_key key, T_value value) override {
        int idx = this->get_idx(key);

        this->table.at(idx).add(make_pair(key, value));
    }

    void remove(T_key key) override {
	    int idx = this->get_idx(key);
        // TODO; use a função search_list(idx, key) abaixo

        int indiceValor = search_list(idx, key);

        if(indiceValor == -1) return;

        this->table.at(idx).remove(indiceValor);

    }

    T_value search(T_key key) override {
        int idx = this->get_idx(key);

        // TODO; use a função search_list(idx, key) abaixo

        int indiceValor = search_list(idx, key);

        if(indiceValor == -1) return this->not_found;

        auto &linkedlistTable = this->table.at(idx);

        auto pairLinkedList = linkedlistTable.begin();

        for(int i = 0; i < indiceValor; i++){
            ++pairLinkedList;
        }

        return pairLinkedList->second;

    }

    void show() override {
        int i = 0;
        for (auto &list : table) {
            cout << i++ << ": ";
            for (auto &[key, value] : list)
                cout << "(" << key << ": " << value << ") ";
            cout << endl;
        }
    }

    virtual T_value operator [] (const T_key &key) {
        return search(key);
    }

private:
    int search_list(int idx, T_key key) {
        int i = 0;
        for (auto &[k, _] : table[idx]) {
            if (k == key) return i;
            i++;
        }
        return -1;
    }
};

#endif //PRATICA_06_FULL_HASHTABLE_H
