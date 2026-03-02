#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
 int islandPerimeter(vector<vector<int>>& grid) {
 int rows = (int)grid.size();
    int cols = (int)grid[0].size();

    int perimeter = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                perimeter += 4;

                // se tem vizinho terra em cima, remove 2 (aresta compartilhada)
                if (i > 0 && grid[i - 1][j] == 1) perimeter -= 2;

                // se tem vizinho terra à esquerda, remove 2 (aresta compartilhada)
                if (j > 0 && grid[i][j - 1] == 1) perimeter -= 2;
            }
        }
    }
 return perimeter;
 }
};
int main() {
 vector<vector<int>> grid = {
 {0,1,0,0},
 {1,1,1,0},
 {0,1,0,0},
 {1,1,0,0}
 };
 cout << Solution().islandPerimeter(grid) << endl; // res = 16
 return 0;
}