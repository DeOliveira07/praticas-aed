// Problema 1: Dado um array (vector) de inteiros e um valor N (N >= 0), escreva uma função que
// desloque os elementos do array N posições à direita. Os elementos cuja nova posição
// extrapolem o tamanho do array são colocados ao início, por exemplo, o array:
// 3 5 8 10 1 7 9 4
// Com valor N (descolamento) = 3, o array ao final ficaria:
// 7 9 4 3 5 8 10 1
// Uma implementação boa deve usar apenas um loop (for, while) e resto da divisão (operador %)
// para calcular as novas posições dos elementos. Pode ser usado um array/vector auxiliar. Use o
// código abaixo como base; chame o arquivo rotate.cpp. Pense também como deixar o código
// genérico o suficiente para lidar com valores negativos de N.
#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<int> &arr, int n) {
 int tamanho = arr.size();
 vector<int>auxiliar (tamanho);
 n = (n % tamanho + tamanho) % tamanho;
 for(int i = 0;i<tamanho;i++){
    
    int calc_np=(i+n)%tamanho;
    auxiliar[calc_np]= arr[i];}

arr=auxiliar;
}
int main() {
 vector<int> arr1 = {0,0,0,0};
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
