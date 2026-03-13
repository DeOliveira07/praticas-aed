#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> memo;

public:
    Solution() : memo(46, -1) {}

    int climbStairs(int n) {
        // TODO
       
	return -1;
    }
};

int stairs() {
// int main() {
    cout << endl << "******* STAIRS *******" << endl << endl;

    cout << Solution().climbStairs(1) << endl; // res = 1
    cout << Solution().climbStairs(2) << endl; // res = 2
    cout << Solution().climbStairs(3) << endl; // res = 3
    cout << Solution().climbStairs(4) << endl; // res = 5
    cout << Solution().climbStairs(5) << endl; // res = 8
    cout << Solution().climbStairs(10) << endl; // res = 89
    cout << Solution().climbStairs(45) << endl; // res = 1836311903 (45 eh o limite)

    return 0;
}