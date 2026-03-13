/*
 * ordenacao.cpp
 *
 *  Created on: 20 de out de 2017
 *      Author: ramide
 */

#ifndef ORDENACAO_H_AULA
#define ORDENACAO_H_AULA

#include <iostream>
#include <chrono>
#include <vector>
#include <stack>
#include <span>
#include <utility>

using namespace std;

//A STL oferece uma sunção swap() que troca elementos; ela pode ser usada abaixo

template<class T>
void bubblesort(vector<T> &array) {
	int mudanca;
	T salva;
	do{

		mudanca = 0;

		for(int i = 0; i < array.size() - 1; i++){
			if(array.at(i) > (array.at(i + 1))){
				salva = array.at(i + 1);
				array.at(i + 1) = array.at(i);
				array.at(i) = salva;
				mudanca++;
			}
		}
		
	}while(mudanca > 0);
}

template<class T>
void selectionsort(vector<T> &array) {
	int sizeArry = array.size();

	T saveValor;

	int menor;

	for(int Inicio = 0; Inicio < sizeArry - 1; Inicio++){
		menor = Inicio;


		for(int i = Inicio + 1; i < sizeArry; i++){
			if(array.at(i) < array.at(menor)){
				menor = i;
			}
		}


		saveValor = array.at(Inicio);
		array.at(Inicio) = array.at(menor);
		array.at(menor) = saveValor;
	}
	
}

template<class T>
void insertionsort(vector<T> &array) {
	int valorDaSequencia;
	int i, j;
	for(i = 1; i < array.size(); i++){
		valorDaSequencia = array.at(i);
		j = i - 1;

		while( j > 0 && array.at(j) > valorDaSequencia){
			array.at(j + 1) = array.at(j);

			j--;
		}
		array.at(j + 1) = valorDaSequencia;
	}
}



template<class T>
void quick(vector<T> &array){
	int inicio, fim, percorreMenores, percorreMaiores;

	T pivo, valor;

	stack<pair<int,int>> pilhaDeParticao;

	pilhaDeParticao.push(make_pair(0, array.size() - 1));

	while(!(pilhaDeParticao.empty())){

		inicio = pilhaDeParticao.top().first;

		fim = pilhaDeParticao.top().second;

		pilhaDeParticao.pop();

		if(inicio >= fim){
			continue;
		};

		pivo = array.at((inicio + fim) / 2);

		percorreMenores = inicio;
		percorreMaiores = fim;

		while(percorreMenores <= percorreMaiores){

			while(array.at(percorreMenores) < pivo){
				percorreMenores++;
			}

			while(array.at(percorreMaiores) > pivo){
				percorreMaiores--;
			}

			if(percorreMenores <= percorreMaiores){
				valor = array.at(percorreMaiores);
				array.at(percorreMaiores) = array.at(percorreMenores);
				array.at(percorreMenores) = valor;

				percorreMenores++;
				percorreMaiores--;
			}
		}

		if(inicio < percorreMaiores){
			pilhaDeParticao.push(make_pair(inicio, percorreMaiores));
		}

		if(percorreMenores < fim){
			pilhaDeParticao.push(make_pair(percorreMenores, fim));
		}
	}
}

// Array: array que vai conter o resultado ordenado
// Aux: array auxiliar usado para ordenar as duas metades, esquerda e direita
// Repare que na chamada recursiva de mergesorte, array e aux se alternam
// Isto é, uma hora um é o principal e o outro é o auxiliar, depois invertem
template<class T>
void merge(vector<T> &array, vector<T> &aux, int start, int finish) {
	if (start >= finish) return;

	int mid = (start + finish)/2;

	merge(aux, array, start, mid);
	merge(aux, array, mid + 1, finish);

	int ini = start;
	int meio = mid + 1;
	int i = start;

	while(ini <= mid && meio <= finish){
		if(aux.at(ini) <= aux.at(meio)){
			array.at(i) = aux.at(ini);
			i++;
			ini++;
		}else{
			array.at(i) = aux.at(meio);
			i++;
			meio++;
		}
	}

	while(ini <= mid){
		array.at(i) = aux.at(ini);
		i++;
		ini++;
	}
	while(meio <= finish){
		array.at(i) = aux.at(meio);
		i++;
		meio++;
	}
}

// Função chamada inicialmente;
// Chama a função mergesorte() acima com os limites start e finish, e o clone do array (aux).
template<class T>
void mergesort(vector<T> &array) {
    vector<T> aux = array; // TODO ajeitado!
	merge(array, aux, 0, array.size() - 1);
}

// Partição do QuickSort
template<class T>
int partition(vector<T> &array, int start, int finish) {
	// TODO
	return (start + finish)/2;
}

template<class T>
void quicksort(vector<T> &array, int start, int finish) {
	if (finish <= start) return;
	int pivot = partition(array, start, finish);
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, finish);
}

// Semelhante ao que ocorre com o MergeSort.
template<class T>
void quicksort(vector<T> &array) {
	quicksort(array, 0, array.size() - 1);
}

template<class T>
void stdsort(vector<T> &array) {
	sort(array.begin(), array.end());
}

// Funções Utilitárias

// Valida um array (isto é, se está ordenado ou não)
template<class T>
int validate(vector<T> &array) {
	for (int i = 0; i < array.size() - 1; i++) {
		if (array[i] > array[i + 1]) return 0;
	}
	return 1;
}

// Exibe um array na tela
template<class T>
void print(vector<T> &array) {
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

// Testa um algoritmo passado como parâmetro.
template<class T>
void test(vector<T> &array, const char * name, void function(vector<T> &array), bool printFlag) {
    vector<T> copy = array;
	auto start = std::chrono::high_resolution_clock::now();

	function(copy);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

	string status = "ok";
	if (!validate(copy)) {
		status = "error";
	} else {
		auto copy2 = array;
		sort(copy2.begin(), copy2.end());
		for (int i = 0; i < array.size(); i++) {
			if (copy[i] != copy2[i]) {
				status = "corrupted";
				break;
			}
		}
	}

	cout << name << ": " << status << " (tempo[us] = " << elapsed << ") ";

	if (printFlag) print(copy); else cout << endl;
}

#endif


