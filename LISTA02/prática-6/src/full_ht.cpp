#include <iostream>
#include <string>
#include <vector>

#include "cpf.h"
#include "hashfunc.h"
#include "full_hashtable.h"

using namespace std;


template <class T_chave, class T_valor>
bool testar_hashtable (const vector<pair<T_chave, T_valor>> &dados_criacao,
                       const vector<pair<T_chave, T_valor>> &dados_teste,
                       T_valor not_found) {

    full_hashtable<T_chave, T_valor> tabela(10, not_found);

    try {
        for (auto &[k, v] : dados_criacao) {
            tabela.insert(k, v);
        }
    } catch (std::runtime_error &e) {
        cout << "Erro na insercao: " << e.what() << endl;
        return false;
    }

    cout << "TABELA CRIADA: " << endl;
    tabela.show();

    cout << endl << "TESTANDO BUSCA E REMOCAO: "  << endl;

    for (auto &a: dados_teste) {
        cout << "Buscando " << a.first << " ... ";

        T_valor valor = tabela.search(a.first);

        if (valor != a.second) { // encontrado valor errado!
            cout << "ERRO ";
            cout << " esperado = " << a.second;
            cout << " encontrado = " << valor;
            return false;
        }

        if (a.second == not_found) {
            cout << "Nao encontrado [OK]" << endl;
            continue;
        }

        cout << "encontrado = " << a.second <<  " ... removendo...";
        tabela.remove(a.first);
        bool removido = tabela.search(a.first) == not_found;
        cout << (removido ? "OK!" : "ERRO!") << endl;

        if (!removido) return false;
    }

    cout << endl << "TABELA FINAL: " << endl;
    tabela.show();

    return true;
}

int full_ht() {
// int main() {

    cout << endl << "****** Testando Hashtable COMPLETA (Full) ****** " << endl << endl;

    cout << endl << "*** Tabela de Alunos *** " << endl;

    vector<pair<string, float>> dados_notas =  {{"Joao", 5},
                                                {"Pedro", 7},
                                                {"Larissa", 10},
                                                {"Tereza", 7.5},
                                                {"Victor", 6},
                                                {"Mario", 4}};

    vector<pair<string, float>> teste_notas = {{"Joao", 5},
                                               {"Carlos", -1},
                                               {"Pedro", 7},
                                               {"Maria", -1},
                                               {"Mario", 4}};

    if (!testar_hashtable<string, float>(dados_notas, teste_notas, -1.0f))
        return -1;

    // ----------------------
    /* Tabela de clientes: CPF -> Nome */
    cout << endl << "*** Tabela de Clientes *** " << endl;

    vector<pair<CPF, string>> dados_clientes =   {{"123.456.789-99", "Joao"},
                                                  {"987.654.231-00", "Maria"},
                                                  {"111.222.333-44", "Tereza"},
                                                  {"555.666.777-88", "Pedro"},
                                                  {"123.321.123-32", "Everaldo"}};

    vector<pair<CPF, string>> teste_clientes =   {{"123.456.789-99", "Joao"},
                                                  {"999.999.999-99", "NOT_FOUND"},
                                                  {"111.222.333-44", "Tereza"},
                                                  {"111.111.111-11", "NOT_FOUND"},
                                                  {"123.321.123-32", "Everaldo"}};

    if (!testar_hashtable<CPF, string>(dados_clientes, teste_clientes, "NOT_FOUND"))
        return -1;

    cout << endl << "****** HASHTABLE COMPLETA OK! *******" << endl;

    return 0;
}

