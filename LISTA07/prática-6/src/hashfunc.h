#ifndef PRATICA_06_MISC_H
#define PRATICA_06_MISC_H

#include <iostream>
#include <iterator>
#include "cpf.h"

using namespace std;

/* Funcao de espalhamento abstrata
 * Deve sempre retornar valor positivo! */
template <class T>
long hash_function(const T &v);

// Calcula o hash para chaves do tipo int
template <>
inline long hash_function<int>(const int &v) {

    const long primo = 2654435761L;  

    long hash = static_cast<long>(v) * primo;
    

    if (hash < 0) hash = -hash;
    
    return hash;
}

// Calcula o hash para chaves do tipo string
template <>
inline long hash_function<string>(const string &v) {
    const long numeroHash = 137L;
    const long max_value = 1e8;
    long valorFinal = 0L;
    long no_mudanca = 1L;

    for(char c : v){
        valorFinal = (valorFinal + (c - 32 + 1) * no_mudanca) % max_value;
        no_mudanca = (no_mudanca * numeroHash) % max_value;
    }

    return valorFinal;
}

template <>
inline long hash_function<CPF>(const CPF &cpf) {
    long numeroHash = 59L;
    const long max_value = 1e8;
    long valorFinal = 0L;
    long no_mudanca = 1L;


    for(char c : cpf.valor){
        valorFinal = (valorFinal + (c - 45 + 1) * no_mudanca) % max_value;
        no_mudanca = (no_mudanca * numeroHash) % max_value;
    }

    return valorFinal;
}
#endif //PRATICA_06_MISC_H