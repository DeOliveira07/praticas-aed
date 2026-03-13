#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float solve(const vector<int> &price, const vector<int> &weight, int k) {
    vector<pair<int,int>> pricesWeights(price.size());

    for(int i = 0; i < price.size(); i++){
        pricesWeights.at(i) = {price.at(i), weight.at(i)};
    }

    sort(pricesWeights.begin(), pricesWeights.end(), [](const pair<int,int> &a, const pair<int,int> &b){
        return (a.first / a.second) > (b.first / b.second);
    });
    
    float totalValue = 0.0, remainWeight = k ;

    for(auto x : pricesWeights){
        if(remainWeight <= 0) return totalValue;

        if(x.second <= remainWeight){
            totalValue += x.first;
            remainWeight -= x.second;
        }else{
            float fraction = remainWeight / x.second;
            totalValue += (x.first * fraction);
            remainWeight = 0;
        }
    }
    
    return totalValue;
}

// int main() {
int mochila() {
    cout << endl << "******* MOCHILA *******" << endl << endl;

    vector<int> precos = {100, 10 , 10, 100, 50};
    vector<int> pesos  = {50, 50, 100, 20, 10};
    int K = 100;

    float res = solve(precos, pesos, K);

    cout << res << endl; // 254

    return 0;
}


