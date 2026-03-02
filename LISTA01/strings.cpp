#include <iostream>
#include <string>
using namespace std;

string reordenar(const string &str) {
    // Caso base: se a string tiver 0 ou 1 caractere, já está ordenada
    if (str.size() == 1)//caso base
        return str;

    char menor = str[0];
    int pos = 0;
    for (int i = 1; i < str.size(); i++) {
        if (str[i] < menor) {
            menor = str[i];
            pos = i;
        }
    }

    string resto = str.substr(0, pos) + str.substr(pos + 1);

    return menor + reordenar(resto);
}

int main() {
    cout << reordenar("miguel") << endl;    // egilmu
    cout << reordenar("roberto") << endl;  // beoorrt
    cout << reordenar("nemesio") << endl;    // eeimnos
    cout << reordenar("de") << endl;  // de
    cout << reordenar("oliveira") << endl; //aeiilorv
    return 0;
}
