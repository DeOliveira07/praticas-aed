#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool comparar(const string &a, const string& b) {
    return (a.size() < b.size());
}

vector<vector<string>> groupStrings(vector<string> &strs) {
    int quantidadeGrupos = strs.size();
    int percorreLinhaMatriz = 0;

    vector<vector<string>> res(quantidadeGrupos);

    sort(strs.begin(), strs.end(), comparar);

    for (int i = 0; 
         i < quantidadeGrupos && percorreLinhaMatriz < quantidadeGrupos; 
         i++) 
    {
        // evita acessar posição inválida
        if (i > 0 && strs.at(i).size() > strs.at(i - 1).size()) {
            if (percorreLinhaMatriz + 1 < quantidadeGrupos) {
                percorreLinhaMatriz++;
            }
        }

        res.at(percorreLinhaMatriz).push_back(strs.at(i));
    }

    return res;
}

int main() {

    vector<string> strs = {"Redes", "IFPE", "Algoritmos", "Android",
                           "Complexidade", "IF", "PE", "Recife",
                           "TADS", "2025", "BubbleSort", "Git",
                           "GitHub", "Subversion", "Gradle", "Docker"};

    vector<vector<string>> groups = groupStrings(strs);

    for (const auto &group : groups) {
        for (const auto &str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}