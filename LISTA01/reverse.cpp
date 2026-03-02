#include <iostream>
#include <string>
using namespace std;

string inverter(const string &s) {

    if (s.size() <= 1)  // caso base
        return s;

    return inverter(s.substr(1)) + s[0];
}

int main() {
    cout << inverter("recursao") << endl; // oasrucer
    cout << inverter("banana") << endl;   // ananab
    cout << inverter("ifpe") << endl;     // epfi
}