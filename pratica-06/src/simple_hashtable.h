#ifndef PRATICA_06_SIMPLE_HASHTABLE_H
#define PRATICA_06_SIMPLE_HASHTABLE_H

#include <vector>
#include <utility>
#include "hashtable.h"


/* Tabela de Espalhamento simples com vector. */
template<class T_key, class T_value>
class simple_hashtable : public hashtable<T_key, T_value> {
private:
    std::vector<std::pair<T_key, T_value>> table;

    // Usados para representar posicoes vazias na tabela
    T_key no_key;
    T_value no_value;

public:
    explicit simple_hashtable(int cap, T_key no_key, T_value no_value)
    : hashtable<T_key, T_value>(cap), // construtor da superclasse
      table(cap, {no_key, no_value}), no_key(no_key),
      no_value(no_value)  // iniciliza tabela com tamanho cap, e com valores {no_key, no_value}
            {  }

    ~simple_hashtable() override = default;

void insert(T_key key, T_value value) override {

    int idx = this->get_idx(key);
    

    if(this->table.at(idx).second == this->no_value || 
       this->table.at(idx).first == this->no_key){

        this->table.at(idx) = std::make_pair(key, value);

        return;
    }
    
    
    if(this->table.at(idx).first == key){
        this->table.at(idx).second = value;

        return;
    }

    this->table.at(idx) = std::make_pair(key, value);
}

    void remove(T_key key) override {
        // TODO
        // Setar o valor associado com a chave como not_found
        int idx = this->get_idx(key);
        
        if(this->table.at(idx).second == this->no_value || this->table.at(idx).first == this->no_key) return;

        this->table.at(idx) = std::make_pair(this->no_key, this->no_value);

    }

    T_value search(T_key key) override {
        // TODO
	    // Acha e retorna o valor associado com a chave
        int idx = this->get_idx(key);
        int idxInitial = idx;

        if(this->table.at(idx).first == this->no_key || this->table.at(idx).second == this->no_value) return this->no_value;
            
        if(this->table.at(idx).first == key && this->table.at(idx).second != this->no_value) return this->table.at(idx).second;

        return this->table.at(idx).second;
    }

    void show() override {
        int i = 0;
        for (auto &[k, v]: table) {
            std::cout << i++ << ": (" << k << ": " << v << ") " << endl;
        }
    }

    T_value operator [] (const T_key &key) {
        return search(key);
    }

};

#endif
