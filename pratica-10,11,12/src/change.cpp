
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {

public:

    int coinChange(const vector<int>& coins, int amount) {
        // TODO
        
        vector<int> memo(amount + 1, INT_MAX);

        memo.at(0) = 0;

        for(int i = 1; i <= amount; i++){
            for(auto v : coins){
                if((i - v) >= 0 && memo.at(i - v) != INT_MAX) memo.at(i) = min(memo.at(i), memo.at(i - v) + 1);
            }
        }

        return memo.at(amount);
    }

};

// int main() {
int change() {
    cout << endl << "******* CHANGE *******" << endl << endl;

    cout << Solution().coinChange({1, 2}, 10) << endl; // res = 5
    cout << Solution().coinChange({1, 2, 5}, 10) << endl; // res = 2
    cout << Solution().coinChange({1, 2, 5}, 11) << endl; // res = 3
    cout << Solution().coinChange({1, 6, 7, 9, 11}, 13) << endl; // res = 2 (greedy = 3)
    cout << Solution().coinChange({1, 2, 5, 10}, 16) << endl; // res = 3
    cout << Solution().coinChange({1, 2, 7, 10}, 16) << endl; // res = 3 (greedy = 4)
    cout << Solution().coinChange({1, 2, 5, 7, 8}, 30) << endl; // res = 4
    cout << Solution().coinChange({83, 186, 408, 419}, 6249) << endl; // res = 20

    return 0;
}