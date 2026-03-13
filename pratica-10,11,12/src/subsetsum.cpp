/*
 * subsetsum.cpp
 *
 *  Created on: 14 de dez de 2017
 *      Author: ramide
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long count_ssk = 0;

/* Pr�tica 10 - For�a Bruta ------------------*/

bool subsetSumBF(const vector<int> &array, int K, vector<bool> &subset) {

    long total = 1 << array.size(); // 2^N combina��es totais

	for (long v = 0; v < total; v++) { // para todas as combina��es
		count_ssk ++;

		int cur_sum = 0;
		for (unsigned i = 0; i < array.size(); i++) { // para todas as posi��es / bits
			subset[i] = v & (1 << i);
			if (subset[i]) cur_sum += array[i];
		}
		if (cur_sum == K) return true;
	}

	return false;
}

/* Pr�tica 10 - Backtracking ------------------- */

bool subsetSumBTRec(const vector<int> &array, int n, int k, vector<bool> &subset) {
	// todo
	if(k == 0){
			return true;
	}
	if(n < 0){
		
		return false;
	}
	subset.at(n) = false;

	if(subsetSumBTRec(array, n - 1, k, subset)){
		return true;
	}

	if(array.at(n) <= k){
		subset.at(n) = true;

		if(subsetSumBTRec(array, n - 1, k - array.at(n), subset)){
			return true;
		}

		subset.at(n) = false;
	}

	return false;
}

bool subsetSumBT(const vector<int> &array, int k, vector<bool> &subset) {
	return subsetSumBTRec(array, (int)array.size() - 1, k, subset);
}

/* Pr�tica 11 - Greedy ------------------ */

bool subsetSumGreedy(const vector<int> &array, int k, vector<bool> &subset) {
	// todo
	vector<pair<int, int>> valores;

	for(int i = 0; i < array.size(); i++){
		valores.push_back({array[i], i});
	}

	sort(valores.rbegin(), valores.rend());

	int soma = 0;

	for(auto &[valor, idx] : valores){

		if(soma + valor <= k){
			subset.at(idx) = true;
			soma += valor;
			if(soma == k) return true;
		}
	}

	return soma == k;
}

/* Pr�tica 12 - Programa��o Din�mica ------------------ */

bool subsetSumRecMemo(const vector<int> &array, int n, int k, vector<bool> &subset, vector<vector<int>> &memo) {
    // todo

    if (k == 0) {
        return true;
    }
    
    
    if (n < 0 || k < 0) {
        return false;
	}

    if (memo[n][k] != -1) {
        return memo[n][k] == 1;
    }
    

    subset[n] = false;
    
    if (subsetSumRecMemo(array, n - 1, k, subset, memo)) {
        memo[n][k] = 1;
        return true;
    }
    

    if (array[n] <= k) {
        subset[n] = true;
        if (subsetSumRecMemo(array, n - 1, k - array[n], subset, memo)) {
            memo[n][k] = 1;
            return true;
        }
        

        subset[n] = false;
    }
    
    memo[n][k] = 0;
    return false;
}


bool subsetSumMemo(const vector<int> &array, int k, vector<bool> &subset) {
	vector<vector<int>> memo(array.size() + 1, vector<int>(k + 1,  -1));

	return subsetSumRecMemo(array, (int)array.size() - 1, k, subset, memo);
}

bool subsetSumDP(const vector<int> &array, int k, vector<bool> &subset) {
	// TODO
    

    return true;
}



/* -------------------------------------- */

bool check_sum(const vector<int> &array, int sum, const vector<bool> &subset) {
	int cur_sum = 0;

	for (int i = 0; i < (int)array.size(); i++) {
		if (subset[i]) cur_sum += array[i];
	}

	return (cur_sum == sum);
}

void runSubsetSum(const char *name, bool subsetSum(const vector<int> &, int, vector<bool> &), const vector<int> &array, int sum) {
	using namespace std::chrono;

    count_ssk = 0;

	vector<bool> subset(array.size(), false);

	auto start = high_resolution_clock::now();

	bool found = subsetSum(array, sum, subset);

	auto finish = high_resolution_clock::now();
	long elapsed = duration_cast<nanoseconds>(finish - start).count() / 1000;

	bool valid = found && check_sum(array, sum, subset);

	cout << name << ": " << (found ? ( valid ? "YES " : "ERR " ): " NO ");

	cout << "[time: " << elapsed << "us] ";
	cout << "[count: " << count_ssk << "] ";
	if (found) {
		cout << "[ ";
		for (unsigned i = 0; i < array.size(); i++) {
			if (subset[i])
				cout << array[i] << " ";
		}
		cout << "] ";
	}
	cout << endl;

}

// int main() {
int subsetsum() {
	int size = 20;

	vector<int> array(size);

	srand(333);
//	srand(12345);

	for (int i = 0; i < size; i++) {
		cout << (array[i] = 1 + rand() % (size * 5)) << " ";
	}
	cout << endl;

	cout << endl << "******* SUBSETSUM *******" << endl << endl;

	int value = 0;
	for (int i = 0; i < 20; i++) {
		value += (rand() % (size * 6));
		cout << i << ": Trying " << value << " ..." << endl;

		runSubsetSum("Bruteforce   ", subsetSumBF, array, value);
		runSubsetSum("Backtracking ", subsetSumBT, array, value);
		runSubsetSum("Memoization  ", subsetSumMemo, array, value);
		runSubsetSum("Dynamic Prog.", subsetSumDP, array, value);
		runSubsetSum("Greedy       ", subsetSumGreedy, array, value);
	}


	return 0;
}

