#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &array, int start, int finish) {
    // TODO
    int pivo = array.at(finish);
    int valueLow = start - 1;

    for(int i = start; i < finish; i++){
        if(array.at(i) <= pivo){
            valueLow++;
            swap(array.at(valueLow), array.at(i));
        }
    }
    
    swap(array.at(valueLow + 1), array.at(finish));

    return valueLow + 1;
}

int quickselectRec(vector<int> &array, int ini, int end,  int k){
    if(ini == end) return array.at(ini);

    int pivoIndex = partition(array, ini, end);

    if(k == pivoIndex){

        return array.at(k);
    }else if(k < pivoIndex){

        return quickselectRec(array, ini, pivoIndex - 1, k);
    }else{
        return quickselectRec(array, pivoIndex + 1, end, k);
    }
}

int quickselect(vector<int> &values, int k) {
    // TODO
    return quickselectRec(values, 0, values.size() - 1, values.size() - k);
}

class KthLargest {
    int k;
    vector<int> scores;
public:
    KthLargest(int k, vector<int>& nums) : k(k), scores(nums) {
    }

    int add(int val) {
        scores.push_back(val);
	    return quickselect(this->scores, this->k);
    }

    const vector<int> & values() {
        return scores;
    }
};

// int main() {
int kthlargest() {
    cout << endl << "******* KTHLARGEST *******" << endl << endl;

    vector<int> nums = {4, 5, 8, 2};
    vector<int> vals = {3, 5, 10, 9, 4};
    KthLargest kthLargest (3, nums);

    for (int v : vals) {
        cout << "Adicionando " << v << ", 3o maior eh " << kthLargest.add(v) << endl;
        for (int x : kthLargest.values()) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
