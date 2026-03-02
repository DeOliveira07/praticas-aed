#include <iostream>
#include <vector>

using namespace std;

// --------------------
// Iterativa: escorre só para a ESQUERDA
// (mantém: de cima; e da direita para a esquerda sobre prateleira)
// --------------------
void solucao_iterativa_esquerda(vector<vector<char>> &C) {
    bool change;
    int n = (int)C.size();
    int m = (int)C[0].size();

    do {
        change = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (C[i][j] != '.') continue;

                bool vem_de_cima = (i > 0 && C[i - 1][j] == 'o');

                // Só para a esquerda: vem do vizinho da direita (j+1) e tem prateleira abaixo dele
                bool vem_da_direita_sobre_prateleira =
                    (j < m - 1 && i < n - 1 && C[i][j + 1] == 'o' && C[i + 1][j + 1] == '#');

                if (vem_de_cima || vem_da_direita_sobre_prateleira) {
                    C[i][j] = 'o';
                    change = true;
                }
            }
        }
    } while (change);
}

// --------------------
// Recursiva: escorre só para a DIREITA
// (mantém: de cima; e da esquerda para a direita sobre prateleira)
// --------------------
void chuva_direita(vector<vector<char>> &C, int i, int j) {
    int n = (int)C.size();
    int m = (int)C[0].size();

    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (C[i][j] != '.') return;

    bool vem_de_cima = (i > 0 && C[i - 1][j] == 'o');

    // Só para a direita: vem do vizinho da esquerda (j-1) e tem prateleira abaixo dele
    bool vem_da_esquerda_sobre_prateleira =
        (j > 0 && i < n - 1 && C[i][j - 1] == 'o' && C[i + 1][j - 1] == '#');

    if (vem_de_cima || vem_da_esquerda_sobre_prateleira) {
        C[i][j] = 'o';

        // Só propaga para a DIREITA e para BAIXO
        chuva_direita(C, i, j + 1);
        chuva_direita(C, i + 1, j);
    }
}

void solucao_recursiva_direita(vector<vector<char>> &C) {
    int m = (int)C[0].size();

    int leak = -1;
    for (int j = 0; j < m; j++) {
        if (C[0][j] == 'o') {
            leak = j;
            break;
        }
    }
    if (leak == -1) return;

    chuva_direita(C, 0, leak + 1); 
    chuva_direita(C, 1, leak);     
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> C(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> C[i][j];
        }
    }

    vector<vector<char>> A = C;
    solucao_iterativa_esquerda(A);
    imprimir(A);

    cout << "\n";

    vector<vector<char>> B = C;
    solucao_recursiva_direita(B);
    imprimir(B);

    return 0;
}