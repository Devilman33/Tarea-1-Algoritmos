#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int num = 10;  // Tamaño de la matriz n x n

vector<vector<int>> generateRandomMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    srand(time(0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            matrix[i][j] = rand() % num;  // Genera números aleatorios entre 0 y 99
    return matrix;
}

void saveMatrixToFile(const vector<vector<int>>& matrix, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        int n = matrix.size();
        outFile << n << endl;  // Guardamos el tamaño de la matriz
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                outFile << matrix[i][j] << " ";
            }
            outFile << endl;
        }
        outFile.close();
        cout << "Matriz guardada en " << filename << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

int main() {
    vector<vector<int>> matrix = generateRandomMatrix(num);
    saveMatrixToFile(matrix, "1matrix10.txt");
    return 0;
}