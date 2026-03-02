#include <iostream>
#include <vector>
using namespace std;
int maior(const vector<int> &arr, int n) {
    if (n == 1)
        return arr[0];
        
    int maiorAnterior = maior(arr, n - 1);

    if (arr[n - 1] > maiorAnterior)
        return arr[n - 1];
    else
        return maiorAnterior;

    
}
int main() {
 vector<int> arr1 = {1, 1, 1, 1, 1, 1, 1, 2}; //2
 vector<int> arr2 = {-1, -2, -3, -4, -5, -6}; //-1
 vector<int> arr3 = {10, 1, 5, 3, 12, 7, 4, 6}; //12
 // o array size é o n que chamo na minha recursão
 cout << maior(arr1, arr1.size()) << endl; 
 cout << maior(arr2, arr2.size()) << endl; // -1
 cout << maior(arr3, arr3.size()) << endl; // 12
 return 0;
}
