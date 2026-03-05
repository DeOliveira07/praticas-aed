#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

static void contaminar_com_fila(vector<string> &C) {
    int n = (int)C.size();
    int m = (int)C[0].size();

    queue<pair<int,int>> q;

    // Enfileira todas as fontes iniciais 'T'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (C[i][j] == 'T') {
                q.push({i, j});
            }
        }
    }

    const int di[4] = {-1, 1, 0, 0};
    const int dj[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        int i = p.first;
        int j = p.second;

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

            // Só espalha para água; rocha 'X' barra, e 'T' já está contaminado
            if (C[ni][nj] == 'A') {
                C[ni][nj] = 'T';
                q.push({ni, nj});
            }
        }
    }
}

static void imprimir(const vector<string> &C) {
    for (const auto &linha : C) {
        cout << linha << "\n";
    }
}

int main() {
    int N, M;

    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        vector<string> C(N);
        for (int i = 0; i < N; i++) {
            cin >> C[i];
        }

        contaminar_com_fila(C);
        imprimir(C);

        cout << "\n"; 
    }

    return 0;
}