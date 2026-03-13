#include <iostream>
#include "linkedlist.h"

using namespace std;

int simple_ll() {
// int main() {
    cout << endl << "******* Testando Lista Encadeada ******* " << endl << endl;

    linkedlist<string> lista_nomes;
    lista_nomes.add("Felipe");
    lista_nomes.add("Antonio");
    lista_nomes.add("Esmeralda");
    lista_nomes.add("Frederico");
    lista_nomes.add("Matilde");

    cout << "LISTA CRIADA: " << endl;
    int i = 0;
    for (auto &s : lista_nomes) {
        cout << i++ << ": " << s << endl;
    }

    lista_nomes.remove(1);
    lista_nomes.remove(2);

    cout << endl << "LISTA POS-REMOCAO: " << endl;
    i = 0;
    for (auto &s : lista_nomes) {
        cout << i++ << ": " << s << endl;
    }

   // 0: Matilde
   // 1: Esmeralda
   // 2: Felipe

    return 0;
}
