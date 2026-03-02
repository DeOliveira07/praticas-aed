#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<int> &arr, int n) {
    int tamanhoMax = arr.size();
    vector<int> auxiliar(tamanhoMax);
    for (int i = 0; i < tamanhoMax; i++) {
      int novaPos = (i+n)%tamanhoMax;
      auxiliar[novaPos] = arr[i];
    }
    arr=auxiliar;
}
int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> arr2 = {8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> arr3 = {3, 5, 8, 10, 1, 7, 9, 4};
    rotate(arr1, 2);
    for (auto & v : arr1) cout << v << " "; // 7 8 1 2 3 4 5 6
    cout << endl;
    rotate(arr2, 5);
    for (auto & v : arr2) cout << v << " "; // 5 4 3 2 1 8 7 6
    cout << endl;
    rotate(arr3, 3);
    for (auto & v : arr3) cout << v << " "; // 7 9 4 3 5 8 10 1
    cout << endl;
    return 0;
}