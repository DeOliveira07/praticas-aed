//
// Created by IFPE on 20/11/2025.
//

#include <iostream>
#include "hashfunc.h"
#include "cpf.h"

using namespace std;

int hashfunc() {
// int main() {
    cout << endl << "*** Testando Funcoes de Espalhamento *** " << endl;

    cout << "Hash de " << 100 << " = " << hash_function(100) << endl;
    cout << "Hash de " << 100 << " = " << hash_function(100) << endl;
    cout << "Hash de " << 1 << " = " << hash_function(1) << endl;
    cout << "Hash de " << 11241 << " = " << hash_function(11241) << endl;
    cout << "Hash de " << -123 << " = " << hash_function(-123) << endl;

    cout << "Hash de " << "Maria" << " = " << hash_function(string("Maria")) << endl;
    cout << "Hash de " << "Maria" << " = " << hash_function(string("Maria")) << endl;
    cout << "Hash de " << "airaM" << " = " << hash_function(string("airaM")) << endl;
    cout << "Hash de " << "Joao" << " = " << hash_function(string("Joao")) << endl;
    cout << "Hash de " << "StringGrandeDeTeste" << " = " << hash_function(string("StringGrandeDeTeste")) << endl;
    cout << "Hash de " << "StringGrandeDeTeste" << " = " << hash_function(string("StringGrandeDeTeste")) << endl;
    cout << "Hash de " << "esteTeDednarGgnirtS" << " = " << hash_function(string("esteTeDednarGgnirtS")) << endl;
    cout << "Hash de " << "$a$ " << " = " << hash_function(string("$a$ ")) << endl;

    cout << "Hash do CPF " << "123.456.789-00" << " = " << hash_function(CPF("123.456.789-00")) << endl;
    cout << "Hash do CPF " << "111.222.333-44" << " = " << hash_function(CPF("111.222.333-44")) << endl;
    cout << "Hash do CPF " << "987.654.321-00" << " = " << hash_function(CPF("987.654.321-00")) << endl;

    return 0;
}
