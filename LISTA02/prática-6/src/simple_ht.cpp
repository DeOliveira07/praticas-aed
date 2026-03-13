#include <iostream>
#include <string>
#include <vector>

#include "hashfunc.h"
#include "simple_hashtable.h"

using namespace std;

// int main() {
int simple_ht() {
    cout << endl << "****** Testando Hashtable SIMPLES ****** " << endl << endl;

    try {
        /* Tabela de alunos por matricula: mat = aluno */

        simple_hashtable<int, string> alunos(10, -1, string("NOT_FOUND"));

        alunos.insert(12312, "Marcos");
        alunos.insert(23523, "Flavia");
        alunos.insert(98787, "Victor");
        alunos.insert(72365, "Pedro");
        alunos.insert(51535, "Esmeralda");

        cout << "TABELA CRIADA: " << endl;
        alunos.show();
        cout << endl;

        cout << "TESTANDO BUSCA: "  << endl;

        cout << 12312 << " : " << alunos.search(12312) << endl; // Marcos
        cout << 99999 << " : " << alunos.search(99999) << endl; // NOT_FOUND
        cout << 23523 << " : " << alunos[23523] << endl; // Flavia, equivalente a search()
        cout << 66666 << " : " << alunos[66666] << endl; // NOT_FOUND
        cout << 72365 << " : " << alunos[72365] << endl; // Pedro

        cout << endl <<  "TESTANDO REMOCAO: "  << endl;

        alunos.remove(12312); // Marcos
        alunos.remove(99999); // NOT_FOUND, sem efeito
        alunos.remove(23523); // Flavia
        alunos.remove(66666); // NOT_FOUND, sem efeito
        alunos.remove(72365); // Pedro

        cout << 12312 << " : " << alunos[12312] << endl; // NOT_FOUND
        cout << 99999 << " : " << alunos[99999] << endl; // NOT_FOUND
        cout << 23523 << " : " << alunos[23523] << endl; // NOT_FOUND
        cout << 66666 << " : " << alunos[66666] << endl; // NOT_FOUND
        cout << 72365 << " : " << alunos[72365] << endl; // NOT_FOUND

    } catch (std::runtime_error &e) {
        cout << "ERRO: " << e.what() << endl;
        return -1;
    }

    return 0;
}

