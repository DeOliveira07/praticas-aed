#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> cameras(N + 1, vector<int>(N + 1));

    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            cin >> cameras[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int soma = cameras[i][j]
                     + cameras[i][j + 1]
                     + cameras[i + 1][j]
                     + cameras[i + 1][j + 1];

            if (soma >= 2) cout << 'S';
            else cout << 'U';
        }
        cout << '\n';
    }

    return 0;
}