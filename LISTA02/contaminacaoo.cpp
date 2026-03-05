#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solucao_iterativa(vector<vector<char>> &C) {
    int n = (int)C.size();
    int m = (int)C[0].size();

    vector<int> qr(n * m), qc(n * m);
    int head = 0, tail = 0;

    // enfileira todos os contaminantes iniciais
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (C[i][j] == 'T') {
                qr[tail] = i;
                qc[tail] = j;
                tail++;
            }
        }
    }

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // BFS
    while (head < tail) {
        int r = qr[head];
        int c = qc[head];
        head++;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

            // só contamina água
            if (C[nr][nc] == 'A') {
                C[nr][nc] = 'T';
                qr[tail] = nr;
                qc[tail] = nc;
                tail++;
            }
        }
    }
}

void dfs_contamina(vector<vector<char>> &C, int r, int c) {
    int n = (int)C.size();
    int m = (int)C[0].size();

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

        if (C[nr][nc] == 'A') {
            C[nr][nc] = 'T';
            dfs_contamina(C, nr, nc);
        }
    }
}

void solucao_recursiva(vector<vector<char>> &C) {
    int n = (int)C.size();
    int m = (int)C[0].size();


    vector<pair<int,int>> fontes;
    fontes.reserve(n * m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (C[i][j] == 'T') fontes.push_back({i, j});
        }
    }

    for (auto &p : fontes) {
        dfs_contamina(C, p.first, p.second);
    }
}

static void imprimir(const vector<vector<char>> &C) {
    for (int i = 0; i < (int)C.size(); i++) {
        for (int j = 0; j < (int)C[i].size(); j++) {
            cout << C[i][j];
        }
        cout << "\n";
    }
}

int main() {


    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        vector<vector<char>> C(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> C[i][j];
            }
        }

        // solucao_iterativa(C);
        solucao_recursiva(C);

        imprimir(C);
        cout << "\n"; 
    }

    return 0;
}