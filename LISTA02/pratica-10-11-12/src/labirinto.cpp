//
// Created by IFPE on 05/08/2025.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


bool solveRec(vector<string> &grid, int n, int m) {
    int i = static_cast<int>(grid.size());
    int j = static_cast<int>(grid.at(0).size());

    if (grid.at(n).at(m) == 'd') return true;

    grid.at(n).at(m) = 'o';

    // cima
    if (n > 0 && (grid.at(n - 1).at(m) == '.' || grid.at(n - 1).at(m) == 'd')) {
        if(solveRec(grid, n - 1, m)) return true;
    }

    // direita
    if (m < j - 1 && (grid.at(n).at(m + 1) == '.' || grid.at(n).at(m + 1) == 'd')) {
        if(solveRec(grid, n, m + 1)) return true;
    }

    // baixo
    if (n < i - 1 && (grid.at(n + 1).at(m) == '.' || grid.at(n + 1).at(m) == 'd')) {
        if(solveRec(grid, n + 1, m)) return true;
    }

    // esquerda
    if (m > 0 && (grid.at(n).at(m - 1) == '.' || grid.at(n).at(m - 1) == 'd')) {
        if(solveRec(grid, n, m - 1)) return true;
    }

    grid.at(n).at(m) = '.';
    return false;
}

void solve(vector<string> &M) {
    // TODO
    for(int i = 0; i < M.size(); i++){
        for(int j = 0; j < M.at(i).size(); j++){
            char charArray = M.at(i).at(j);
            if( charArray == 'o'){
                cout << (charArray) << "\n";
                
                solveRec(M, i, j);
                return;
            }
        }
    }
}

void print(const vector<string> &M) {
    for (auto &s : M) {
        cout << s << endl;
    }
    cout << endl;
}

int labirinto() {
    cout << endl << "******* LABIRINTO *******" << endl << endl;

    vector<string> M1 = {
            ".#...",
            "...##",
            ".#..#",
            "o##.d",
            "#####"
    };

    vector<string> M2 = {
            "#...o",
            "..###",
            ".#...",
            "...#.",
            "###d."
    };

    solve(M1);
    print(M1);

    /* sa�da valida
    .#...
    xxx##
    x#xx#
    o##xd
    #####
    */

    solve(M2);
    print(M2);

    /*
    #xxxo
    xx###
    x#xxx
    xxx#x
    ###dx
     */


    return 0;
}

/*
  https://judge.beecrowd.com/pt/problems/view/1621

5 5
.#...
...##
.#..#
.##..
#####
5 5
.....
####.
.....
.####
.....
0 0
 */
