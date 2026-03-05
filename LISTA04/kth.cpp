#include <iostream>
#include <vector>
#include <string>

#include "lista.h"

using namespace std;

class KthLargest {
private:
    int k;
    ListaOrdenada<int> lista;

public:
    KthLargest(int k, vector<int>& nums)
        : k(k),
          // capacidade: nums + até 10^4 chamadas add
          lista((int)nums.size() + 10005) {

        for (int x : nums) {
            lista.adicionar(x);
        }
    }

    int add(int val) {
        lista.adicionar(val);
        int idx = lista.tamanho() - k + 1; // k-ésimo maior em lista crescente
        return lista.pega(idx);
    }
};

// Teste local (baseado no exemplo do LeetCode)
int main() {
    {
        cout << "Teste 1:\n";
        vector<int> nums = {4, 5, 8, 2};
        KthLargest kth(3, nums);

        cout << kth.add(3) << "\n";   // 4
        cout << kth.add(5) << "\n";   // 5
        cout << kth.add(10) << "\n";  // 5
        cout << kth.add(9) << "\n";   // 8
        cout << kth.add(4) << "\n";   // 8
        cout << "\n";
    }

    {
        cout << "Teste 2:\n";
        vector<int> nums = {7, 7, 7, 7, 8, 3};
        KthLargest kth(4, nums);

        cout << kth.add(2) << "\n";   // 7
        cout << kth.add(10) << "\n";  // 7
        cout << kth.add(9) << "\n";   // 7
        cout << kth.add(9) << "\n";   // 8
        cout << "\n";
    }

    return 0;
}