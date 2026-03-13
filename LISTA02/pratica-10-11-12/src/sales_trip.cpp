//
// Created by IFPE on 05/08/2025.
//
#include <vector>
#include <iostream>
#include <ranges>

using namespace std;

int max_profit(const vector<int> &costs, const vector<int> &sales) {
    int totalSumSales = 0;
    int totalSumCosts = 0;
    
    for(int i = 0; i < costs.size(); i++){
        int sumCosts = 0;
        int sumSales = 0;
        
        for(int j = i; j < costs.size(); j++){
            sumCosts += costs.at(j);
            sumSales += sales.at(j);
            if((sumSales - sumCosts) > (totalSumSales - totalSumCosts)){
                totalSumCosts = sumCosts;
                totalSumSales = sumSales;
            }
        }
    }

    return (totalSumSales - totalSumCosts);
}

// int main() {
int sales_trip() {
    cout << endl << "******* SALES_TRIP *******" << endl << endl;

    vector<int> costs = {10, 22, 15, 20, 18, 16, 14, 12, 10};
    vector<int> sales = {17, 12, 21, 15, 25, 40, 34, 20, 5};

    cout << "Max profit = " << max_profit(costs, sales) << endl; // 60

    return 0;
}